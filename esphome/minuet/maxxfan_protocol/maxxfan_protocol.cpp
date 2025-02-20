#include "maxxfan_protocol.h"

#include "esphome/core/log.h"

namespace esphome {
namespace remote_base {

static const char *const TAG = "remote.maxxfan";

/* The Maxxfan IR remote protocol looks like RS232 with 1 start bit (zero), 8 data bits
 * encoded least-significant-bit first, no parity bits, and 2 stop bits (ones).
 * A mark signals a zero bit and a space signals a one bit.  Each bit period is 800 us.
 *
 * The packet consists of a fixed preamble followed by some data and a checksum.
 *
 * Here's an example of a packet and its decoding:
 *
 *   preamble:   0 01011010 11  ->  01011010  0x5A bit pattern
 *   preamble:   0 10100101 11  ->  10100101  0xA5 bit pattern (0x5A inverted)
 *   preamble:   0 00000001 11  ->  10000000  0x80 bit pattern
 *   preamble:   0 11111110 11  ->  01111111  0x7F bit pattern (0x80 inverted)
 *   preamble:   0 00000010 11  ->  01000000  0x40 bit pattern
 *   preamble:   0 11111101 11  ->  10111111  0xBF bit pattern (0x40 inverted)
 *   preamble:   0 00000100 11  ->  00100000  0x20 bit pattern
 *   preamble:   0 11111011 11  ->  11011111  0xDF bit pattern (0x20 inverted)
 *   preamble:   0 00001000 11  ->  00010000  0x10 bit pattern
 *   preamble:   0 00110011 11  ->  11001100  0xCC bit pattern
 *   state:      0 00100100 11  ->  00100100  state: fan off, fan exhaust, cover close, warn
 *   speed:      0 00100110 11  ->  01100100  speed percent: 100%
 *   auto temp:  0 00100010 11  ->  01000100  temperature in Fahrenheit: 68 F
 *   ???:        0 11111111 11  ->  11111111  unknown purpose, always 0xff
 *   ???:        0 11000100 11  ->  00100011  unknown purpose, always 0x23
 *   checksum:   0 00011011 11  ->  11011000  XOR of previous 5 bytes
 *   end:        11111111                     end of transmission
 *
 * The state field consists of a combination of flags as follows (numbered from LSB):
 *
 *   bit 0: fan state - off if 0, on if 1
 *   bit 1: cover override - set to 0 when the cover is controlled by the fan state
 *                           set to 1 in auto mode which opens and closes the cover automatically
 *                           set to 1 in ceiling fan mode when the user closes the cover while the fan is running
 *   bit 2: fan direction - intake if 0, exhaust if 1
 *   bit 3: cover state - close if 0, open if 1
 *   bit 4: mode - manual if 0, automatic if 1
 *   bit 5: warn - set to 1 when the user attempts to raise or lower the speed or temperature
 *                 beyond the allowed range
 *   bit 6-7: unknown purpose, always 0
 *
 * The speed percent is a multiple of 10 between 0 and 100 percent inclusively.
 *
 * The temperature ranges from 29 to 99 Fahrenheit inclusively.
 */
class BitReader {
 public:
  BitReader(const RemoteReceiveData& data) : data_(data) {}

  int next_bit() {
    constexpr int32_t BIT_TIME_US = 800;
    for (;;) {
      if (!data_.is_valid(index_)) return -1; // no more data
      const int32_t duration = data_[index_];
      const int32_t remaining = abs(duration) - consumed_;
      if (remaining > BIT_TIME_US * 2 / 3) {
        consumed_ += BIT_TIME_US;
        return duration > 0 ? 0 : 1;
      }
      if (remaining > BIT_TIME_US / 3) return -1; // malformed bit
      index_ += 1;
      consumed_ = 0;
    }
  }

 private:
  const RemoteReceiveData& data_;
  uint32_t index_{};
  int32_t consumed_{};
};


void MaxxfanProtocol::encode(RemoteTransmitData *dst, const MaxxfanData &data) {
    // NOT IMPLEMENTED
}

optional<MaxxfanData> MaxxfanProtocol::decode(RemoteReceiveData src) {
  if (false) {
    char buffer[256];
    size_t index = 0;
    BitReader reader(src);
    int bit;
    while ((bit = reader.next_bit()) >= 0 && index < sizeof(buffer) - 1) {
      buffer[index++] = bit ? '1' : '0';
    }
    buffer[index] = 0;
    ESP_LOGD(TAG, "Received bits: %s", buffer);
  }

  uint8_t packet[16];
  BitReader reader(src);
  for (size_t i = 0; i < sizeof(packet); i++) {
    uint8_t byte = 0;
    if (reader.next_bit() != 0) return {}; // expected start bit
    for (uint32_t j = 0; j < 8; j++) {
      int bit = reader.next_bit();
      if (bit < 0) return {}; // expected data bit
      byte = (byte >> 1) | (bit ? 0x80 : 0x00);
    }
    if (reader.next_bit() != 1 || reader.next_bit() != 1) return {}; // expected two stop bits
    packet[i] = byte;
  }
  if (reader.next_bit() != 1) return {}; // expected end of transmission

  if (false) {
    ESP_LOGD(TAG, "Received packet: %02x,%02x,%02x,%02x,%02x,%02x,%02x,%02x,%02x,%02x,%02x,%02x,%02x,%02x,%02x,%02x",
        packet[0], packet[1], packet[2], packet[3],
        packet[4], packet[5], packet[6], packet[7],
        packet[8], packet[9], packet[10], packet[11],
        packet[12], packet[13], packet[14], packet[15]);
  }

  constexpr uint8_t preamble[] = { 0x5a, 0xa5, 0x80, 0x7f, 0x40, 0xbf, 0x20, 0xdf, 0x10, 0xcc };
  if (memcmp(packet, preamble, sizeof(preamble))) return {}; // preamble mismatch

  const uint8_t state = packet[10];
  const uint8_t fan_speed = packet[11];
  const uint8_t auto_temperature = packet[12];
  const uint8_t unknown1 = packet[13];
  const uint8_t unknown2 = packet[14];
  const uint8_t checksum = packet[15];
  if ((state ^ fan_speed ^ auto_temperature ^ unknown1 ^ unknown2) != checksum) return {}; // checksum mismatch

  if (unknown1 != 0xff || unknown2 != 0x23 || state & 0xc0) {
    ESP_LOGD(TAG, "Packet has curious data of unknown purpose: unknown1=0x%02x, unknown2=0x%02x, state=0x%02x",
        unknown1, unknown2, state);
  }

  MaxxfanData out{
    .fan_on = state & 0x01,
    .cover_override = state & 0x02,
    .fan_exhaust = state & 0x04,
    .cover_open = state & 0x08,
    .auto_mode = state & 0x10,
    .warn = state & 0x20,
    .fan_speed = fan_speed,
    .auto_temperature = auto_temperature
  };
  return out;
}

void MaxxfanProtocol::dump(const MaxxfanData &data) {
  ESP_LOGD(TAG, "Received Maxxfan: fan_on=%d, fan_exhaust=%d, fan_speed=%d, cover_open=%d, cover_override=%d, auto_mode=%d, auto_temperature=%d, warn=%d",
      data.fan_on, data.fan_exhaust, data.fan_speed, data.cover_open, data.cover_override, data.auto_mode, data.auto_temperature, data.warn);
}

}  // namespace remote_base
}  // namespace esphome
