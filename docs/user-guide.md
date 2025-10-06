# Minuet user guide

This guide explains how to use Minuet.

- [Main functions](#main-functions)
- [Light accessory functions](#light-accessory-functions)
- [WiFi network](#wifi-network)
- [Automation](#automation)
- [Minuet app (help wanted)](#minuet-app-help-wanted)

# Main functions

You can control most of the fan's functions using the built-in keypad.  Some functions can only be used when you have certain accessories installed or using automation (see related sections).

## Using the built-in keypad and the 6 key wall remote

Minuet supports two different control schemes for the built-in keypad and the 6 key wall remote.  After all, why not improve on the fan controls when you're already replacing its brains!

The [enhanced controls](#enhanced-controls) are enabled by default and make the automatic thermostat easier to use and more capable.

If you prefer, you can enable the [standard controls](#standard-controls) instead to mimic the original Maxxfan controls with some loss of functionality.

### Quick reference

These button combinations vary by control mode.

| Button combination | Enhanced controls | Standard controls (manual mode) | Standard controls (auto mode) |
| ------------------ | ----------------- | ------------------------------- | ----------------------------- |
| press `up` | speed up | speed up | thermostat temperature up |
| hold `up` for 1 second | speed maximum | speed maximum | |
| press `down` | speed down | speed down | thermostat temperature down |
| hold `down` for 1 second | speed minimum | speed mimimum | |
| press `in/out` | direction in/out | direction in/out | direction in/out |
| press `on/off` | fan on/off | fan on/off | thermostat disable (return to manual mode) |
| press `open/close` | lid open/close | lid open/close | |
| press `auto` | thermostat enable/disable | thermostat enable (enter auto mode) | thermostat disable (return to manual mode) |
| hold `auto` for 3 seconds | thermostat reset | | thermostat reset |
| hold `auto` and press `up` | thermostat temperature up | | |
| hold `auto` and press `down` | thermostat temperature down | | |
| hold `auto` and press `in/out` | thermostat direction toggle | | |
| hold `auto` and press `on/off` | thermostat function toggle | | |

These button combinations are common to all modes.

| Button combination | Behavior |
| ------------------ | -------- |
| press `rain` | rain sensor toggle (only for models with rain sensors) |
| hold `auto` and `up` for 5 seconds | use enhanced controls |
| hold `auto` and `down` for 5 seconds | use standard controls |
| hold `auto` and `open/close` for 5 seconds | keypad indicator toggle |
| hold `on/off` and `in/out` for 5 seconds | manual safety lock toggle |
| hold `on/off` and `down` for 5 seconds | WiFi toggle |
| hold `on/off` and `up` for 5 seconds | power on restore toggle |
| hold `on/off` for 15 seconds | factory reset |

These button combinations are available when you have the corresponding accessory installed.

| Button combination | Light accessory |
| ------------------ | --------------- |
| hold `in/out` for 1 second | light on/off |
| hold `in/out` for press `up` | brightness up |
| hold `in/out` for press `down` | brightness down |

### Enhanced controls

The enhanced controls let you keep the automatic thermostat enabled while you manually override its behavior for particular situations like when you need extra ventilation for cooking indoors.  The buttons always behave the same way regardless of whether the thermostat is enabled.

While the thermostat is disabled, the `auto` indicator is unlit and the buttons control the fan state similar to the standard controls.

While the thermostat is enabled, the `auto` indicator is lit and the thermostat controls the fan state automatically based on the ambient temperature.  However, if you press a button or send an automation request to change the state of the fan with enhanced controls then your manual settings *override* the behavior of the thermostat.  This behavior differs from the [standard controls](#standard-controls) where such changes are disallowed unless the thermostat is disabled.

While the thermostat is overridden, the `auto` indicator blinks and the buttons control the fan state similar to the standard controls.  The thermostat will remain overridden state by your manual settings until you press `auto` to re-engage the thermostat.

Hold `auto` and press other buttons to modify the thermostat temperature set point, direction, and function with the keypad.  Use the [automation](#automation) interfaces to configure more advanced features of the thermostat.

*To enable the enhanced controls, press and hold `auto` and `up` simultaneously for 5 seconds.  Minuet confirms with three quick tones followed by a long high tone.*

#### Buttons

- Press `up`: increase the fan speed by one
- Hold `up` for 1 second: increase the fan speed to maximum *(bonus)*
- Press `down`: decrease the fan speed by one
- Hold `down` for 1 second: decrease the fan speed to minimum *(bonus)*
- Press `in/out`: toggle the fan direction between air in and air out
- Press `on/off`: toggle the fan off or turn it on at its last selected manual fan speed
- Press `open/close` (`up` and `down` together): toggle the lid open or closed
- Press `auto`: enable the thermostat if it is disabled, re-engage the thermostat if it is overridden, otherwise disable the thermostat
- Hold `auto` for 3 seconds: reset thermostat to default temperature setpoint of 78 °F (approx. 25.5 °C), default direction, and default function, Minuet confirms with a quick turn
- Hold `auto` and press `up`: increase thermostat temperature setpoint by 1 °F (approx. 0.5 °C), Minuet confirms with a quick rising tone
- Hold `auto` and press `down`: decrease thermostat temperature setpoint by 1 °F (approx. 0.5 °C), Minuet confirms with a quick falling tone
- Hold `auto` and press `in/out` one or more times: set the thermostat direction according to the number of presses of `in/out` as indicated in the *thermostat direction* table

  | Thermostat direction | Key presses | Behavior | Confirmation |
  | -------------------- | ----------- | -------- | ------------ |
  | *default* | 1 | use the last selected manual fan direction | two quick tones |
  | *air out* | 2 | exhaust air from the vehicle | quick rising scale |
  | *air in* | 3 | draw air into the vehicle | quick descending scale |

- Hold `auto` and press `on/off` one or more times: set the thermostat function according to the number of presses of `on/off` as indicated in the *thermostat function* table

  | Thermostat function | Key presses | Fan mode | Lid mode | Behavior | Confirmation |
  | ------------------- | ----------- | -------- | -------- | -------- | ------------ |
  | *default* | 1 | fan auto | lid auto | **best for cooling**: automatic fan speed control | long tone, quick tone |
  | *quiet* | 2 | fan quiet | lid open | **best for sleeping**: quieter automatic fan speed control, lid stays open even below the temperature setpoint to provide fresh air and eliminate actuator noises (unless overridden by a safety lock) | long tone, two quick tones |
  | *low* | 3 | fan low | lid auto | **best for energy efficiency**: fan speed at minimum | long tone, three quick tones |
  | *passive* | 4 | fan off | lid auto | **best for passive ventilation**: fan stays off | long tone, four quick tones |

### Standard controls

The standard controls mimic the original Maxxfan controls with a few *bonus* convenience features.

The buttons behave differently depending on whether the fan is in manual or in auto mode.  Check the state of the `auto` indicator light before pressing buttons to avoid surprises.  For example, in manual mode the `up` and `down` buttons control the fan speed whereas in auto mode the `up` and `down` buttons control the thermostat temperature setpoint.

If Minuet receives an automation request to change the fan speed or open/close the lid while auto mode is active with standard controls, it returns to manual mode before performing the requested action.  This behavior differs from the [enhanced controls](#enhanced-controls) where such changes are allowed and override the behavior of the thermostat.

*To enable the standard controls, press and hold `auto` and `down` simultaneously for 5 seconds.  Minuet confirms with three quick tones followed by a long low tone.*

#### Buttons in manual mode (`auto` indicator is unlit)

In manual mode, the up/down buttons control the fan speed and the on/off button toggles the fan on or off.

- Press `up`: increase the fan speed by one
- Hold `up` for 1 second: increase the fan speed to maximum *(bonus)*
- Press `down`: decrease the fan speed by one
- Hold `down` for 1 second: decrease the fan speed to minimum *(bonus)*
- Press `in/out`: toggle the fan direction between air in and air out
- Press `on/off`: toggle the fan off or turn it on at its last configured manual fan speed
- Press `open/close` (`up` and `down` together): toggle the lid open or closed
- Press `auto`: enable the thermostat, enter auto mode

#### Buttons in auto mode (`auto` indicator is lit)

In auto mode, the up/down buttons control the thermostat temperature setpoint, the on/off button exits auto mode, and the thermostat controls the fan speed based on the ambient temperature.  The thermostat will turn the fan on in the direction it last operated in.

- Press `up`: increase thermostat temperature setpoint by 1 °F (approx. 0.5 °C), Minuet confirms with a quick rising tone
- Press `down`: decrease thermostat temperature setpoint by 1 °F (approx. 0.5 °C), Minuet confirms with a quick falling tone
- Press `in/out`: toggle the fan direction between air in and air out
- Press `on/off`: disable the thermostat, return to manual mode
- Press `open/close` (`up` and `down` together): *inoperable in this mode*
- Press `auto`: disable the thermostat, return to manual mode
- Hold `auto` for 3 seconds: reset thermostat to default temperature setpoint of 78 °F (approx. 25.5 °C), Minuet confirms with a quick turn

### Rain sensor (only for models with rain sensors)

Press the `rain sensor` button to toggle the rain sensor on or off.

When the rain sensor is disabled, the LED will turn red to warn that water could enter your vehicle if it rains.

When the rain sensor detects moisture, it turns off the fan, closes the lid, makes the LED flash red, and activates the safety lock feature.  The fan cannot be operated while the safety lock is activated.  Press the `rain sensor` button again to reset the flashing LED and release the rain sensor safety lock.

### Safety lock

The safety lock feature closes the lid and prevents the fan from being operated whenever one or more of the following conditions occur:

| Reason | Condition | How to release |
| ------ | --------- | -------------- |
| Battery safety lock | The battery voltage is too low to too high. | Wait for the battery voltage to return to the normal operating range or adjust the low or high battery voltage thresholds. |
| Rain safety lock | The rain sensor is enabled and detected moisture. | Press the `rain sensor` button to reset or turn off the rain sensor. |
| Accessory safety lock | An accessory triggered the `LOCK` signal. | Consult the documentation of your accessories for details. For example, if you have a sensor to detect the presence of an insulated vent cover then remove the cover. |
| Manual safety lock | The [manual safety lock](#manual-safety-lock) is enabled. | Disable the [manual safety lock](#manual-safety-lock). |
| Automation safety lock | The [automation safety lock](#automation-safety-lock) is enabled. | Disable the [automation safety lock](#automation-safety-lock). |

You cannot turn the fan on or open the lid while the safety lock is active.  If you try, Minuet plays three quick tones as a warning and rejects the request.

The safety lock also turns off and inhibits the light accessory.

#### Manual safety lock

Use the manual safety lock to keep the fan off and the lid closed to prevent the fan from operating accidentally or under control of the thermostat.  For example, it can be helpful to keep out dust and wildfire smoke in extreme conditions or perhaps to discourage an inappropriately inquisitive child from turning on the fan.

Hold `on/off` and `in/out` together for 5 seconds to toggle the manual safety lock.  By default, the manual safety lock is disabled.

When the manual safety lock is enabled, Minuet confirms with two quick tones followed by a long high tone.

When the manual safety lock is disabled (default), Minuet confirms with two quick tones followed by a long low tone.

#### Automation safety lock

Use the automation safety lock to develop automations that keep the fan off and the lid closed under software defined conditions.  Unlike [manual safety lock](#manual-safety-lock), the automation safety lock cannot be toggled using the keypad; it can only be toggled by automations.

For example, you could write an automation to enable the automation safety lock while driving (to reduce road noise and fumes) and disable it when parked.

### WiFi mode

Hold `on/off` and `down` together for 5 seconds to toggle WiFi on or off.  By default, WiFi is turned off.

When WiFi is turned on, Minuet confirms with four quick tones followed by a long high tone.

When WiFi is turned off (default), Minuet confirms with four quick tones followed by a long low tone.

Refer to [these instructions for configuring the WiFi network](#wifi-network).

### Power on restore

Hold `on/off` and `up` together for 5 seconds to toggle power on restore behavior.  By default, power on restore is disabled.

When power on restore is enabled, Minuet will restore the fan operating state, speed, direction, and lid open/close state when it is connected to power.  It confirms this setting with a quick turn followed by a long high tone.

When power on restore is disabled (default), Minuet will leave the fan off and close the lid when it is connected to power.  It confirms this setting with a quick turn followed by a long low tone.

### Keypad indicators

Hold `auto` and `open/close` (`up` and `down` together) for 5 seconds to toggle the behavior of the keypad indicators.  By default, the indicators stay lit or blinking as long as the underlying condition they are indicating remains active.  You can suppress the indicators if you find them distracting.

| Indicator | State | Condition |
| --------- | ----- | --------- |
| `auto` | solid green | the thermostat is enabled |
| `auto` | blinking green | the thermostat has been manually overridden |
| `rain` | solid red | the rain sensor is disabled (only for models with rain sensors) |
| `rain` | blinking red | the rain sensor detected rain and stopped the fan (only for models with rain sensors)

When keypad indicators are suppressed, they will illuminate for just a few seconds when their condition becomes active and will illuminate again after pressing any key on the keypad while their condition remains active.  Minuet confirms by slow blinking all indicators twice.

When keypad indicators are not suppressed (default), they will illuminate indefinitely while their condition is active.  Minuet confirms by slow blinking all indicators three times.

### Factory reset

Hold `on/off` for 15 seconds to turn the fan off and perform a factory reset.  Minuet confirms with four descending tones then erases all of its settings including saved WiFi credentials.  Follow the [Getting started](#getting-started) guide to get started again.

### Fan motor health monitoring

Minuet monitors the state of the fan motor and automatically stops the fan when it detects a problem.  These problems should be rare and they can often be resolved by waiting for the device to cool, starting the fan again, or by performing maintenance.

Minuet indicates a fan motor fault with three quick tones and it writes the cause to the internal logs.

| Possible cause | Resolution |
| -------------- | ---------- |
| Fan motor disconnected | Ensure that the fan motor is plugged in and that its wires are intact. |
| Fan motor stalled | Ensure that the fan blade spins freely and is not obstructed. |
| Overcurrent | Ensure that the fan motor wires are intact. |
| Overtemperature | Allow the device to cool.  Resume operation at a lower speed. |
| Undervoltage or overvoltage | Ensure that the power supply can provide at least 5 amps at 9 to 16 volts. |

If the issue persists, please ask for support.

### Failsafe restart

Minuet monitors the state of its software components and automatically restarts when it detects a problem.  These problems should be rare and they are often resolved automatically by the failsafe restart.

Minuet indicates that a failsafe restart has been triggered with four quick tones and one long tone.  Then, it waits 3 minutes to allow you some time to collect information to help debug the issue.  Finally, it plays the same tones again and restarts the device.

If you have customized the Minuet firmware, please examine the internal logs and review your changes.

If the issue persists, please ask for support.

## Using the 4 key wall remote

The 4 key wall remote has some limitations compares to the built-in keypad and 6 key wall remote.

Because it is designed for a 4 speed fan whereas Minuet supports 10 speeds, the rmeote cycles through 10%, 30%, 70%, and 100%.

When you press any button on the remote while the automatic thermostat is enabled, the remote disables (when using [standard controls](#standard-controls)) or overrides (when using [enhanced controls](#enhanced-controls)) the thermostat before performing the requested action.

### Buttons

- Press `fan on`: turn fan on at its last configured manual fan speed if it was off, otherwise cycle through 4 increasing speeds then back to the lowest speed
- Hold `fan on` for 1 second: turn fan on at maximum speed *(bonus)*
- Press `fan off`: turn fan off
- Press `open`: open lid
- Press `close`: close lid

## Using the Maxxfan infrared remote

Please refer to the instructions originally provided with the remote.

Minuet sets the fan state to match everything that you see on the screen in the remote.  The remote has its own memory of the fan's settings and it may not be completely in sync with the fan.  Sometimes when you press a button to do one thing (such as to change the fan speed) you may observe other settings change too (such as the fan lid closing) because that's what the remote thinks the state should be.

Consequently, there is no difference in the remote's behavior regardless of your choice of [standard](#standard-controls) and [enhanced](#enhanced-controls) controls.

What you see on the infrared remote is what you get.

# Light accessory functions

These additional functions become available when you have installed a light accessory.

## Using the built-in keypad

Use the built-in keypad to control the light as follows.

- Hold `in/out` for 1 second: toggle the light on or off, the light's default color is white
- Hold `in/out` and press `up`: increase the brightness by one step, does nothing if the light is off or is already at maximum brightness
- Hold `in/out` and press `down`: decrease the brightness by one step, does nothing if the light is off or is already at minimum brightness

## Using the 24-key RGBW LED infrared remote control

Use a 24-key RGBW LED remote control to dim the light, change its color, or activate effects as follows.

- Press `on`: turn the light on white, the light's default color is white
- Press `off`: turn the light off
- Press `brightness up`: increase the brightness by one step, does nothing if the light is off or is already at maximum brightness
- Press `brightness down`: decrease the brightness by one step, does nothing if the light is off or is already at minimum brightness
- Press `R`, `G`, `B`, `W`, or any colored button: set the light to the indicated color (approximately), does nothing if the light is off or if it doesn't support changing the color
- Press `Flash`: activate a twinkling color effect, does nothing if the light is off or does not support effects
- Press `Strobe`: activate a pulsing color effect, does nothing if the light is off or does not support effects
- Press `Fade`: activate a solid rainbow color effect, does nothing if the light is off or does not support effects
- Press `Smooth`: activate a chasing rainbow color effect, does nothing if the light is off or does not support effects

Your light accessory kit should include one of these remotes. If you'd like to buy another one, search for "24-key RGBW LED IR remote control" in an online marketplace and you should find some, such as [this listing](https://www.amazon.com/dp/B09C1BFX48). These remotes are fairly generic and inexpensive so they are often included with light fixtures.

You can customize the table of colors and effects by modifying the firmware according to your preferences. Refer to [minuet/accessory/light](https://github.com/brown-studios/minuet-firmware/tree/main/minuet/accessory/light).

![24-key RGBW LED remote](./24%20key%20rgbw%20led%20remote.jpg)

# WiFi network

There are a few ways to configure the WiFi network.  Choose the appropriate method for your situation.

> [!IMPORTANT]
> Minuet only communicates over the local network to integrate with home automation systems.  Never connect Minuet to public networks!

> [!TIP]
> We recommend configuring your router to assign Minuet a static DHCP entry so that it always receives the same host name and IP address and you can more easily identify it on the network.

## Connect to an existing network with the captive portal (out-of-the-box method)

Use this method to connect to a WiFi network if you just installed Minuet out-of-the-box and haven't modified the firmware.

1. [Turn WiFi on using the keypad](#wifi-mode).  Listen for the tones to confirm that WiFi is on.

1. Connect your smartphone or computer to the `minuet-setup` access point.  Use the password `IAmAFan!`.  If the `minuet-setup` access point does not appear, then perform a [factory reset](#factory-reset) to erase the previous network credentials, and try again.

1. Navigate to [http://192.168.4.1/](http://192.168.4.1/) in your web browser.  It should show the Minuet captive portal.

1. The Minuet captive portal will scan for existing WiFi networks and show them in a list.  Pick your WiFi network from the list or type its SSID into the form.  Type the password for your network into the form.  Click `Save`.

1. Minuet will reboot and attempt to connect to your network.

To connect Minuet to a different WiFi network or to change the network credentials using this method, perform a [factory reset](#factory-reset) to erase the previous network credentials, then start over.

## Configure the network in the firmware (advanced method)

Use this method to compile your WiFi network settings directly into the [Minuet firmware](https://github.com/brown-studios/minuet-firmware) so they are always present and cannot be erased by a factory reset.  It gives you full control over the networking behavior.

We recommend using this method whenever you are customizing the firmware and installing firmware updates over-the-air.

Here are some of the things you can do with this method.

* Connect to one or more existing networks.
* Connect to hidden networks.
* Change or remove the access point credentials, captive portal, and fallback behavior.
* Configure a built-in web server for debugging and remote control.
* Change the API and OTA encryption keys.
* Disable all network features.

Refer to the instructions in [minuet.yaml](https://github.com/brown-studios/minuet-firmware/blob/main/minuet.yaml) and [secrets.yaml](https://github.com/brown-studios/minuet-firmware/blob/main/secrets.yaml) for details.

# Automation

Minuet is designed to support a variety of home automation scenarios.  With a bit of technical effort, you can make Minuet do more for your comfort, automatically.

## Project ideas

Here are some ideas for home automation projects that you could implement.

- Add fan controls to a dashboard elsewhere in your vehicle.
- Schedule the fan to run for a few minutes every day to keep the air fresh.
- Set the thermostat setpoint temperature based on whether your vehicle is occupied.
- When your vehicle engine is running, engage the automation safety lock to turn off the fan to reduce road noise and fumes.
- Synchonize two Minuet fans together so one runs in exhaust while the other runs as an intake at the same speed.
- Coordinate a Minuet fan with other HVAC appliances in your vehicle.

Be creative! ❤️

## How to integrate Minuet with Home Assistant

Home Assistant is an open source home automation platform and it works great for operating a smart house on wheels.

When you integrate Minuet with Home Assistant, you can add the Minuet fan, cover (lid), thermostat, light, sensors, and other entities to you Home Assistant dashboard.  You can also create Home Assistant automations to control Minuet in response to triggers.

1. Connect Minuet to a [WiFi network](#wifi-network) that your Home Assistant server can reach.

1. Wait for Home Assistant to automatically discover Minuet.  If it does not, then follow [these instructions](https://esphome.io/guides/getting_started_hassio/#connecting-your-device-to-home-assistant) to add the ESPHome integration manually.

1. When prompted, enter the API encryption key for your device.  If you have not modified the Minuet firmware, you'll find the encryption key in [secrets.yaml](https://github.com/brown-studios/minuet-firmware/blob/main/secrets.yaml).

1. The Minuet entities will be added to your Home Assistant registry.  Take a look at them and add the ones you want into your dashboard.  Some diagnostic and configuration entities are disabled by default; feel free to enable them if you're curious.

> [!TIP]
> We recommend installing the [ESPHome Builder Add-on](https://esphome.io/guides/getting_started_hassio/) for Home Assistant if you plan to customize the Minuet firmware so that you can control everything in one place.

### Home Assistant dashboard cards

Here is a collection of cards that you can add to your Home Assistant dashboard to control Minuet and customize as you like.

- Fan: Set the fan speed and direction.
- Lid: Open and close the lid.
- Thermostat: Select the active preset, fan mode, lid mode, and manual override behavior.
- Preset: Customize the thermostat presets.

This example requires [custom card features](https://github.com/Nerwyn/custom-card-features).

![Home assistant dashboard cards](./home%20assistant%20dashboard%20cards.png)

<details>
<summary>Example dashboard YAML</summary>

```yaml
type: sections
max_columns: 4
title: Minuet
path: minuet
sections:
  - type: grid
    cards:
      - type: heading
        heading_style: title
        heading: Controls
      - features:
          - type: fan-speed
        type: tile
        features_position: bottom
        vertical: false
        entity: fan.minuet_fan
        name: Fan
        hide_state: false
      - features:
          - type: cover-open-close
        type: tile
        features_position: bottom
        vertical: false
        entity: cover.minuet_lid
        name: Lid
      - type: thermostat
        entity: climate.minuet_thermostat
        features:
          - type: climate-hvac-modes
            style: icons
          - type: climate-preset-modes
            style: icons
            preset_modes:
              - home
              - sleep
              - away
              - eco
          - type: custom:service-call
            entries:
              - type: dropdown
                entity_id: climate.minuet_thermostat
                value_attribute: fan_mode
                options:
                  - entity_id: climate.minuet_thermostat
                    value_attribute: fan_mode
                    option: auto
                    tap_action:
                      action: perform-action
                      perform_action: climate.set_fan_mode
                      target:
                        entity_id:
                          - climate.minuet_thermostat
                      data:
                        fan_mode: auto
                    label: Fan auto
                    icon: mdi:fan-auto
                  - entity_id: climate.minuet_thermostat
                    value_attribute: fan_mode
                    option: quiet
                    tap_action:
                      action: perform-action
                      perform_action: climate.set_fan_mode
                      target:
                        entity_id:
                          - climate.minuet_thermostat
                      data:
                        fan_mode: quiet
                    label: Fan quiet
                    icon: mdi:fan-chevron-down
                  - entity_id: climate.minuet_thermostat
                    value_attribute: fan_mode
                    option: low
                    tap_action:
                      action: perform-action
                      perform_action: climate.set_fan_mode
                      target:
                        entity_id:
                          - climate.minuet_thermostat
                      data:
                        fan_mode: low
                    label: Fan low
                    icon: mdi:fan-speed-1
                  - entity_id: climate.minuet_thermostat
                    value_attribute: fan_mode
                    option: "off"
                    tap_action:
                      action: perform-action
                      perform_action: climate.set_fan_mode
                      target:
                        entity_id:
                          - climate.minuet_thermostat
                      data:
                        fan_mode: "off"
                    label: Fan off
                    icon: mdi:fan-off
              - type: dropdown
                entity_id: select.minuet_thermostat_lid_mode
                options:
                  - entity_id: select.minuet_thermostat_lid_mode
                    option: Auto
                    tap_action:
                      action: perform-action
                      perform_action: select.select_option
                      data:
                        option: Auto
                      target:
                        entity_id: select.minuet_thermostat_lid_mode
                    icon: mdi:arrow-up-down-bold
                    label: Lid auto
                  - entity_id: select.minuet_thermostat_lid_mode
                    option: Open
                    tap_action:
                      action: perform-action
                      perform_action: select.select_option
                      data:
                        option: Open
                      target:
                        entity_id: select.minuet_thermostat_lid_mode
                    label: Lid open
                    icon: mdi:arrow-up-bold
                  - entity_id: select.minuet_thermostat_lid_mode
                    option: Closed
                    tap_action:
                      action: perform-action
                      perform_action: select.select_option
                      data:
                        option: Closed
                      target:
                        entity_id: select.minuet_thermostat_lid_mode
                    label: Lid closed
                    icon: mdi:arrow-down-bold
          - type: custom:service-call
            entries:
              - type: dropdown
                entity_id: select.minuet_thermostat_fan_direction
                options:
                  - entity_id: select.minuet_thermostat_fan_direction
                    option: Default
                    tap_action:
                      action: perform-action
                      perform_action: select.select_option
                      data:
                        option: Default
                      target:
                        entity_id: select.minuet_thermostat_fan_direction
                    label: Air default direction
                    icon: mdi:equal
                  - entity_id: select.minuet_thermostat_fan_direction
                    option: Out
                    tap_action:
                      action: perform-action
                      perform_action: select.select_option
                      data:
                        option: Out
                      target:
                        entity_id: select.minuet_thermostat_fan_direction
                    label: Air out
                    icon: mdi:arrow-up-right-bold
                  - entity_id: select.minuet_thermostat_fan_direction
                    option: In
                    tap_action:
                      action: perform-action
                      perform_action: select.select_option
                      data:
                        option: In
                      target:
                        entity_id: select.minuet_thermostat_fan_direction
                    icon: mdi:arrow-down-right-bold
                    label: Air in
              - type: toggle
                entity_id: switch.minuet_thermostat_manual_override
                tap_action:
                  action: toggle
                  target:
                    entity_id: switch.minuet_thermostat_manual_override
                  data: {}
                unchecked_icon: mdi:fan-auto
                checked_icon: mdi:fan-alert
                styles: |-
                  :host {
                    flex-basis: 120px;
                    --feature-color: var(--red-color);
                  }
        name: Thermostat
  - type: grid
    cards:
      - type: heading
        heading_style: title
        heading: Settings
      - features:
          - style: buttons
            type: numeric-input
          - type: custom:service-call
            entries:
              - type: dropdown
                entity_id: select.minuet_thermostat_preset_home_fan_mode
                options:
                  - entity_id: select.minuet_thermostat_preset_home_fan_mode
                    option: Auto
                    tap_action:
                      action: perform-action
                      perform_action: select.select_option
                      data:
                        option: Auto
                      target:
                        entity_id: select.minuet_thermostat_preset_home_fan_mode
                    label: Fan auto
                    icon: mdi:fan-auto
                  - entity_id: select.minuet_thermostat_preset_home_fan_mode
                    option: Quiet
                    tap_action:
                      action: perform-action
                      perform_action: select.select_option
                      data:
                        option: Quiet
                      target:
                        entity_id: select.minuet_thermostat_preset_home_fan_mode
                    label: Fan quiet
                    icon: mdi:fan-chevron-down
                  - entity_id: select.minuet_thermostat_preset_home_fan_mode
                    option: Low
                    tap_action:
                      action: perform-action
                      perform_action: select.select_option
                      data:
                        option: Low
                      target:
                        entity_id: select.minuet_thermostat_preset_home_fan_mode
                    label: Fan low
                    icon: mdi:fan-speed-1
                  - entity_id: select.minuet_thermostat_preset_home_fan_mode
                    option: "Off"
                    tap_action:
                      action: perform-action
                      perform_action: select.select_option
                      data:
                        option: "Off"
                      target:
                        entity_id: select.minuet_thermostat_preset_home_fan_mode
                    label: Fan off
                    icon: mdi:fan-off
              - type: dropdown
                entity_id: select.minuet_thermostat_preset_home_lid_mode
                options:
                  - entity_id: select.minuet_thermostat_preset_home_lid_mode
                    option: Auto
                    tap_action:
                      action: perform-action
                      perform_action: select.select_option
                      data:
                        option: Auto
                      target:
                        entity_id: select.minuet_thermostat_preset_home_lid_mode
                    icon: mdi:arrow-up-down-bold
                    label: Lid auto
                  - entity_id: select.minuet_thermostat_preset_home_lid_mode
                    option: Open
                    tap_action:
                      action: perform-action
                      perform_action: select.select_option
                      data:
                        option: Open
                      target:
                        entity_id: select.minuet_thermostat_preset_home_lid_mode
                    label: Lid open
                    icon: mdi:arrow-up-bold
                  - entity_id: select.minuet_thermostat_preset_home_lid_mode
                    option: Closed
                    tap_action:
                      action: perform-action
                      perform_action: select.select_option
                      data:
                        option: Closed
                      target:
                        entity_id: select.minuet_thermostat_preset_home_lid_mode
                    label: Lid closed
                    icon: mdi:arrow-down-bold
        type: tile
        features_position: bottom
        vertical: false
        entity: number.minuet_thermostat_preset_home_temperature
        name: Home preset
        hide_state: true
        icon: mdi:home
        grid_options:
          columns: full
      - features:
          - style: buttons
            type: numeric-input
          - type: custom:service-call
            entries:
              - type: dropdown
                entity_id: select.minuet_thermostat_preset_sleep_fan_mode
                options:
                  - entity_id: select.minuet_thermostat_preset_sleep_fan_mode
                    option: Auto
                    tap_action:
                      action: perform-action
                      perform_action: select.select_option
                      data:
                        option: Auto
                      target:
                        entity_id: select.minuet_thermostat_preset_sleep_fan_mode
                    label: Fan auto
                    icon: mdi:fan-auto
                  - entity_id: select.minuet_thermostat_preset_sleep_fan_mode
                    option: Quiet
                    tap_action:
                      action: perform-action
                      perform_action: select.select_option
                      data:
                        option: Quiet
                      target:
                        entity_id: select.minuet_thermostat_preset_sleep_fan_mode
                    label: Fan quiet
                    icon: mdi:fan-chevron-down
                  - entity_id: select.minuet_thermostat_preset_sleep_fan_mode
                    option: Low
                    tap_action:
                      action: perform-action
                      perform_action: select.select_option
                      data:
                        option: Low
                      target:
                        entity_id: select.minuet_thermostat_preset_sleep_fan_mode
                    label: Fan low
                    icon: mdi:fan-speed-1
                  - entity_id: select.minuet_thermostat_preset_sleep_fan_mode
                    option: "Off"
                    tap_action:
                      action: perform-action
                      perform_action: select.select_option
                      data:
                        option: "Off"
                      target:
                        entity_id: select.minuet_thermostat_preset_sleep_fan_mode
                    label: Fan off
                    icon: mdi:fan-off
              - type: dropdown
                entity_id: select.minuet_thermostat_preset_sleep_lid_mode
                options:
                  - entity_id: select.minuet_thermostat_preset_sleep_lid_mode
                    option: Auto
                    tap_action:
                      action: perform-action
                      perform_action: select.select_option
                      data:
                        option: Auto
                      target:
                        entity_id: select.minuet_thermostat_preset_sleep_lid_mode
                    icon: mdi:arrow-up-down-bold
                    label: Lid auto
                  - entity_id: select.minuet_thermostat_preset_sleep_lid_mode
                    option: Open
                    tap_action:
                      action: perform-action
                      perform_action: select.select_option
                      data:
                        option: Open
                      target:
                        entity_id: select.minuet_thermostat_preset_sleep_lid_mode
                    label: Lid open
                    icon: mdi:arrow-up-bold
                  - entity_id: select.minuet_thermostat_preset_sleep_lid_mode
                    option: Closed
                    tap_action:
                      action: perform-action
                      perform_action: select.select_option
                      data:
                        option: Closed
                      target:
                        entity_id: select.minuet_thermostat_preset_sleep_lid_mode
                    label: Lid closed
                    icon: mdi:arrow-down-bold
        type: tile
        features_position: bottom
        vertical: false
        entity: number.minuet_thermostat_preset_sleep_temperature
        name: Sleep preset
        hide_state: true
        icon: mdi:bed
        grid_options:
          columns: full
      - features:
          - style: buttons
            type: numeric-input
          - type: custom:service-call
            entries:
              - type: dropdown
                entity_id: select.minuet_thermostat_preset_away_fan_mode
                options:
                  - entity_id: select.minuet_thermostat_preset_away_fan_mode
                    option: Auto
                    tap_action:
                      action: perform-action
                      perform_action: select.select_option
                      data:
                        option: Auto
                      target:
                        entity_id: select.minuet_thermostat_preset_away_fan_mode
                    label: Fan auto
                    icon: mdi:fan-auto
                  - entity_id: select.minuet_thermostat_preset_away_fan_mode
                    option: Quiet
                    tap_action:
                      action: perform-action
                      perform_action: select.select_option
                      data:
                        option: Quiet
                      target:
                        entity_id: select.minuet_thermostat_preset_away_fan_mode
                    label: Fan quiet
                    icon: mdi:fan-chevron-down
                  - entity_id: select.minuet_thermostat_preset_away_fan_mode
                    option: Low
                    tap_action:
                      action: perform-action
                      perform_action: select.select_option
                      data:
                        option: Low
                      target:
                        entity_id: select.minuet_thermostat_preset_away_fan_mode
                    label: Fan low
                    icon: mdi:fan-speed-1
                  - entity_id: select.minuet_thermostat_preset_away_fan_mode
                    option: "Off"
                    tap_action:
                      action: perform-action
                      perform_action: select.select_option
                      data:
                        option: "Off"
                      target:
                        entity_id: select.minuet_thermostat_preset_away_fan_mode
                    label: Fan off
                    icon: mdi:fan-off
              - type: dropdown
                entity_id: select.minuet_thermostat_preset_away_lid_mode
                options:
                  - entity_id: select.minuet_thermostat_preset_away_lid_mode
                    option: Auto
                    tap_action:
                      action: perform-action
                      perform_action: select.select_option
                      data:
                        option: Auto
                      target:
                        entity_id: select.minuet_thermostat_preset_away_lid_mode
                    icon: mdi:arrow-up-down-bold
                    label: Lid auto
                  - entity_id: select.minuet_thermostat_preset_away_lid_mode
                    option: Open
                    tap_action:
                      action: perform-action
                      perform_action: select.select_option
                      data:
                        option: Open
                      target:
                        entity_id: select.minuet_thermostat_preset_away_lid_mode
                    label: Lid open
                    icon: mdi:arrow-up-bold
                  - entity_id: select.minuet_thermostat_preset_away_lid_mode
                    option: Closed
                    tap_action:
                      action: perform-action
                      perform_action: select.select_option
                      data:
                        option: Closed
                      target:
                        entity_id: select.minuet_thermostat_preset_away_lid_mode
                    label: Lid closed
                    icon: mdi:arrow-down-bold
        type: tile
        features_position: bottom
        vertical: false
        entity: number.minuet_thermostat_preset_away_temperature
        name: Away preset
        hide_state: true
        icon: mdi:account-arrow-right
        grid_options:
          columns: full
      - features:
          - style: buttons
            type: numeric-input
          - type: custom:service-call
            entries:
              - type: dropdown
                entity_id: select.minuet_thermostat_preset_eco_fan_mode
                options:
                  - entity_id: select.minuet_thermostat_preset_eco_fan_mode
                    option: Auto
                    tap_action:
                      action: perform-action
                      perform_action: select.select_option
                      data:
                        option: Auto
                      target:
                        entity_id: select.minuet_thermostat_preset_eco_fan_mode
                    label: Fan auto
                    icon: mdi:fan-auto
                  - entity_id: select.minuet_thermostat_preset_eco_fan_mode
                    option: Quiet
                    tap_action:
                      action: perform-action
                      perform_action: select.select_option
                      data:
                        option: Quiet
                      target:
                        entity_id: select.minuet_thermostat_preset_eco_fan_mode
                    label: Fan quiet
                    icon: mdi:fan-chevron-down
                  - entity_id: select.minuet_thermostat_preset_eco_fan_mode
                    option: Low
                    tap_action:
                      action: perform-action
                      perform_action: select.select_option
                      data:
                        option: Low
                      target:
                        entity_id: select.minuet_thermostat_preset_eco_fan_mode
                    label: Fan low
                    icon: mdi:fan-speed-1
                  - entity_id: select.minuet_thermostat_preset_eco_fan_mode
                    option: "Off"
                    tap_action:
                      action: perform-action
                      perform_action: select.select_option
                      data:
                        option: "Off"
                      target:
                        entity_id: select.minuet_thermostat_preset_eco_fan_mode
                    label: Fan off
                    icon: mdi:fan-off
              - type: dropdown
                entity_id: select.minuet_thermostat_preset_eco_lid_mode
                options:
                  - entity_id: select.minuet_thermostat_preset_eco_lid_mode
                    option: Auto
                    tap_action:
                      action: perform-action
                      perform_action: select.select_option
                      data:
                        option: Auto
                      target:
                        entity_id: select.minuet_thermostat_preset_eco_lid_mode
                    icon: mdi:arrow-up-down-bold
                    label: Lid auto
                  - entity_id: select.minuet_thermostat_preset_eco_lid_mode
                    option: Open
                    tap_action:
                      action: perform-action
                      perform_action: select.select_option
                      data:
                        option: Open
                      target:
                        entity_id: select.minuet_thermostat_preset_eco_lid_mode
                    label: Lid open
                    icon: mdi:arrow-up-bold
                  - entity_id: select.minuet_thermostat_preset_eco_lid_mode
                    option: Closed
                    tap_action:
                      action: perform-action
                      perform_action: select.select_option
                      data:
                        option: Closed
                      target:
                        entity_id: select.minuet_thermostat_preset_eco_lid_mode
                    label: Lid closed
                    icon: mdi:arrow-down-bold
        type: tile
        features_position: bottom
        vertical: false
        entity: number.minuet_thermostat_preset_eco_temperature
        name: Eco preset
        hide_state: true
        icon: mdi:leaf
        grid_options:
          columns: full
cards: []
```
</details>

## How to remotely control Minuet with the ESPHome API

You can directly use the ESPHome API to remotely control Minuet without using Home Assistant.  To connect, you'll need the host name and API encryption key for your device.  If you have not modified the Minuet firmware, you'll find the encryption key in [secrets.yaml](https://github.com/brown-studios/minuet-firmware/blob/main/secrets.yaml).

Start here: [ESPHome API client library](https://github.com/esphome/aioesphomeapi)

## How to customize the Minuet firmware

You can program Minuet to do all sorts of useful things by modifying the firmware and making your own accessories.

Start here: [Minuet firmware](https://github.com/brown-studios/minuet-firmware)

# Minuet app (help wanted)

Minuet does not currently have a smartphone app for remote control.  It'd be lovely have one though.

If you'd like to help build an app for Minuet using Bluetooth LE or the local WiFi network, please contact us!
