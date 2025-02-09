# Minuet setup guide

This guide explains how to configure Minuet for your motor, network, automation, and peripherals.

## First time setup

Here's how to set up Minuet given a freshly manufactured circuit board that hasn't already been setup for you by someone else.

### Jumpers

Before you can use Minuet, you need to tell it a little bit about your [fan motor](fan-motor-guide.md).

TODO: How to set the motor current limit and commutation mode jumpers on the board in v2

### Firmware

The Minuet firmware uses [ESPHome](https://esphome.io/).  If you prefer, you can replace the Minuet firmware with something else by following similar steps.  This guide assumes that you will be using ESPHome and that you are somewhat familiar with it already or are willing to learn.

To get started, you will need to install the ESPHome tools either in [Home Assistant](https://esphome.io/guides/getting_started_hassio) or on the [command-line](https://esphome.io/guides/getting_started_command_line).

Next, choose one of the configuration templates included in the Minuet project as a starting point from the [esphome](../esphome) folder.

- [minuet-standalone.yaml](../esphome/minuet-standalone.yaml): The standalone configuration is intended to be the default out-of-the-box setup for end-users.  Pick this one if you want Minuet to offer a web interface over WiFi.  It will offer you the opportunity to specify your WiFi credentials on first boot after connecting to the Minuet access point with a default password as explained in the [user guide](user-guide.md).
- [minuet-api.yaml](../esphome/minuet-api.yaml): Pick the API configuration if you want to integrate Minuet with Home Assistant over WiFi.  It assumes you already have WiFi credentials stored in your `secrets.yaml`.
- [minuet-no-wifi.yaml](../esphome/minuet-no-wifi.yaml): Pick the no WiFi configuration if you want to turn off WiFi completely and only control Minuet with the control panel and/or wall remote.

Copy the configuration template and the contents of the [esphome/minuet](../esphome/minuet) folder to your computer.

- For Home Assistant: One way to do this is to use the [File Editor add-on](https://github.com/home-assistant/addons/blob/master/configurator/DOCS.md) to upload the configuration into the `/homeassistant/esphome` folder.  Upload the files from the minuet folder into the `/homeassistant/esphome/minuet` folder to prevent them from appearing in the ESPHome Builder UI as separate device configurations.
- For the command-line: One way to do this is to check out the Minuet repository then `cd esphome` and away you go.

Edit the configuration template as you need.  Pay attention to the WiFi settings, OTA password, API key, and anything else you might want to change before the first boot.

To flash the firmware:

- Power your Minuet board from your house battery or a benchtop power supply with 9 to 16 V DC (suggest using 12 V DC when available).
- Connect a USB-C cable between your computer and Minuet.
- Boot into the bootloader: Press and hold the BOOT button on the circuit board, tap the RESET button, wait a second, then release the BOOT button.
- Use the ESPHome tools to install the firmware.
    - For Home Assistant: Click the Install button in the ESPHome Builder editor.
    - For the command-line: `esphome run my-minuet.yaml`

Now your Minuet enhanced fan should be ready to go!

If you enable over-the-air software updates, then you'll be able to reprogram your board more conveniently over WiFi next time.  Otherwise, you can always flash the firmware over USB-C again using the method described above.

## Automation

Because Minuet runs ESPHome, you can rig up all sorts of useful automations by programming them in YAML or by remotely controlling Minuet from Home Assistant.

Here are some ideas:

- Turn off the fan when you start the engine.
- Schedule the fan to run for an hour every day.
- Synchonize two Minuet fans together so one runs in exhaust while the other runs as an intake at the same speed.
- Communicate with other devices in your vehicle over WiFi and Bluetooth Low Energy.

Get creative!

## Peripherals

Minuet gets better when you take advantage of its place in the middle of your vehicle's roof to add peripherals connected to the [QWIIC](https://www.sparkfun.com/qwiic) I2C port or the GPIO expansion header (which includes a UART).

These peripherals are specifically designed for use with Minuet:

- Add lights to your fan with a [lighting and load accessory board](../hardware/load/design-and-errata.md)

You can also make your own peripherals that leverage ESPHome and parts that you can buy from hobby electronics shops.  You can find plenty of tutorials online for building stuff with ESPHome.  You might find it easier to program than an Arduino because it's all done with YAML configuration files.

Here are a few ideas for peripherals that you could make yourself:

- Add a CO₂, temperature, humidity sensor: [scd4x sensor](https://esphome.io/components/sensor/scd4x.html)
- Add a temperature, pressure sensor, humidity, gas sensor: [bmp680 sensor](https://esphome.io/components/sensor/bme680)
- Add a light inside the cover: [monochromatic light](https://esphome.io/components/light/monochromatic)
- Add addressable LEDs around the fan or the ceiling: [rmt led strip light](https://esphome.io/components/light/esp32_rmt_led_strip)
- Add more buttons: [gpio binary sensor](https://esphome.io/components/binary_sensor/gpio)
- Add a relay to do something when the fan is running: [gpio switch](https://esphome.io/components/switch/gpio)
- Control a bunch of lights and servos for a disco party: [pca9685](https://esphome.io/components/output/pca9685)
- Detect presence of humans: [dfrobot sen0395](https://esphome.io/components/dfrobot_sen0395)
- Set up a microphone and speaker for a voice assistant: [voice assistant](https://esphome.io/components/voice_assistant.html)

Build your hardware then edit the YAML files to integrate it and consider sharing your hard work with others. ❤️

## Further reading

- [Installation guide](installation-guide.md)
- [User guide](user-guide.md)
