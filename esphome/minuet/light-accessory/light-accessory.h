// Light accessory functions
#include "esphome/components/light/light_state.h"
#include "esphome/components/remote_base/nec_protocol.h"
#include "esphome/core/log.h"

#include <algorithm>

namespace minuet {
namespace light_accessory {

void turn_off(esphome::light::LightState* light) {
  light->turn_off().perform();
}

esphome::light::LightCall make_call_with_white_color(esphome::light::LightState* light) {
  auto call = light->make_call();
  if (light->get_traits().supports_color_mode(esphome::light::ColorMode::RGB_WHITE)) {
    call.set_color_mode(esphome::light::ColorMode::RGB_WHITE)
        .set_color_brightness(0.f)
        .set_rgbw(1.f, 1.f, 1.f, 1.f);
  } else if (light->get_traits().supports_color_mode(esphome::light::ColorMode::WHITE)) {
    call.set_color_mode(esphome::light::ColorMode::WHITE)
        .set_white(1.f);
  } else if (light->get_traits().supports_color_mode(esphome::light::ColorMode::RGB)) {
    call.set_color_mode(esphome::light::ColorMode::RGB)
        .set_rgb(1.f, 1.f, 1.f);
  } else if (light->get_traits().supports_color_mode(esphome::light::ColorMode::BRIGHTNESS)) {
    call.set_color_mode(esphome::light::ColorMode::BRIGHTNESS);
  }
  return call;
}

esphome::light::LightCall make_call_with_rgb_color(esphome::light::LightState* light, float r, float g, float b) {
  auto call = light->make_call();
  if (light->get_traits().supports_color_mode(esphome::light::ColorMode::RGB_WHITE)) {
    call.set_color_mode(esphome::light::ColorMode::RGB_WHITE)
        .set_color_brightness(1.f)
        .set_rgbw(r, g, b, 0.f);
  } else if (light->get_traits().supports_color_mode(esphome::light::ColorMode::RGB)) {
    call.set_color_mode(esphome::light::ColorMode::RGB)
        .set_rgb(r, g, b);
  } else if (light->get_traits().supports_color_mode(esphome::light::ColorMode::BRIGHTNESS)) {
    call.set_color_mode(esphome::light::ColorMode::BRIGHTNESS);
  }
  return call;
}

void turn_on_with_default_color(esphome::light::LightState* light) {
  make_call_with_white_color(light).set_state(true).set_brightness(1.f).perform();
}

void toggle(esphome::light::LightState* light) {
  if (light->remote_values.is_on()) {
    turn_off(light);
  } else {
    turn_on_with_default_color(light);
  }
}

struct IndexedColor {
  unsigned index;
  unsigned rgb;
};
const auto INDEXED_COLORS = std::initializer_list<IndexedColor>{
  { 0x04, 0xff0000 }, // Red
  { 0x05, 0x00ff00 }, // Green
  { 0x06, 0x0000ff }, // Blue
  { 0x08, 0xd32f2f }, // Red 700
  { 0x09, 0x388e3c }, // Green 700
  { 0x0a, 0x1976d2 }, // Blue 700
  { 0x0c, 0xe64a19 }, // Deep Orange 700
  { 0x0d, 0x0097a7 }, // Cyan 700
  { 0x0e, 0x512da8 }, // Deep Purple 700
  { 0x10, 0xffa000 }, // Amber 700
  { 0x11, 0x0288d1 }, // Light Blue 700
  { 0x12, 0x7b1fa2 }, // Purple 700
  { 0x14, 0xfbc02d }, // Yellow 700
  { 0x15, 0x303f9f }, // Indigo 700
  { 0x16, 0xc2185b }, // Pink 700
};

// Handles codes from a common 24 key infrared light remote
void apply_nec_code(esphome::light::LightState* light, esphome::remote_base::NECData code) {
  if (code.address != 0xef00 || code.command_repeats != 1) return;
  unsigned command = code.command & 0xff;
  if (command != ((code.command >> 8) ^ 0xff)) return;

  constexpr int BRIGHTNESS_LEVELS = 5;
  const int brightness = int(light->remote_values.get_brightness() * BRIGHTNESS_LEVELS);
  const bool on = light->remote_values.is_on();

  // Handle color commands from a table of indexed colors
  const auto indexed_color = std::find_if(INDEXED_COLORS.begin(), INDEXED_COLORS.end(),
      [command](const IndexedColor& color) { return color.index == command; });
  if (indexed_color != INDEXED_COLORS.end()) {
    ESP_LOGD("minuet", "Received light remote control code: COLOR index %d, rgb #%06x", indexed_color->index, indexed_color->rgb);
    if (on) {
      const float red = ((indexed_color->rgb >> 16) & 0xff) / 255.f;
      const float green = ((indexed_color->rgb >> 8) & 0xff) / 255.f;
      const float blue = (indexed_color->rgb & 0xff) / 255.f;
      make_call_with_rgb_color(light, red, green, blue).set_effect(0).perform();
    }
    return;
  }

  // Handle all other commands
  auto log_command = [](const char* name) {
    ESP_LOGD("minuet", "Received light remote control code: %s", name);
  };
  switch (command) {
    case 0x00:
      log_command("BRIGHTNESS UP");
      if (on) {
        light->make_call().set_brightness(float(std::min(brightness + 1, BRIGHTNESS_LEVELS)) / BRIGHTNESS_LEVELS).perform();
      }
      return;
    case 0x01:
      log_command("BRIGHTNESS DOWN");
      if (on) {
        light->make_call().set_brightness(float(std::max(brightness - 1, 1)) / BRIGHTNESS_LEVELS).perform();
      }
      return;
    case 0x02:
      log_command("OFF");
      if (on) {
        turn_off(light);
      }
      return;
    case 0x03:
      log_command("ON");
      if (!on) {
        turn_on_with_default_color(light);
      }
      return;
    case 0x07:
      log_command("WHITE");
      if (on) {
        make_call_with_white_color(light).set_effect(0).perform();
      }
      return;
    case 0x0b:
      log_command("FLASH");
      if (on) {
        light->make_call().set_effect("Twinkle").perform();
      }
      return;
    case 0x0f:
      log_command("STROBE");
      if (on) {
        light->make_call().set_effect("Pulse").perform();
      }
      return;
    case 0x13:
      log_command("FADE");
      if (on) {
        light->make_call().set_effect("Fade").perform();
      }
      return;
    case 0x17:
      log_command("SMOOTH");
      if (on) {
        light->make_call().set_effect("Rainbow").perform();
      }
      return;
  }

  ESP_LOGD("minuet", "Received unknown light remote control code: %d", command);
}

} // namespace light_accessory
} // namespace minuet
