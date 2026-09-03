# Minuet user guide

This guide explains how to use Minuet.

- [Basic controls](#basic-controls)
  - [Using the Maxxfan keypad and 6 key wall remote](#using-the-maxxfan-keypad-and-6-key-wall-remote)
  - [Using the Maxxfan 4 key wall remote](#using-the-maxxfan-4-key-wall-remote)
  - [Using the Maxxfan infrared remote](#using-the-maxxfan-infrared-remote)
- [Features](#features)
  - [Auto mode](#auto-mode)
    - [Thermostat](#thermostat-function)
    - [Humidistat](#humidistat-function)
    - [CO₂ monitor](#co-monitor-function)
    - [AQI monitor](#aqi-monitor-function)
    - [Presets](#presets)
  - [Rain sensor](#rain-sensor)
  - [Battery monitor](#battery-monitor)
  - [Safety lock](#safety-lock)
  - [Power on restore](#power-on-restore)
  - [Suppress keypad indiciators](#suppress-keypad-indicators)
  - [Reboot](#reboot)
  - [Factory reset](#factory-reset)
- [Connectivity](#connectivity)
  - [Radio mode](#radio-mode)
  - [Provisioning](#provisioning)
  - [Bluetooth pairing](#bluetooth-pairing)
- [Apps](#apps)
  - [Home Assistant](#home-assistant)
  - [ESPHome Device Builder](#esphome-device-builder)
  - [Minuet app (help wanted)](#minuet-app-help-wanted)
- [Accessories](#accessories)
  - [Light accessory](#light-accessory)
  - [Environmental sensor accessory](#environmental-sensor-accessory)
  - [Cover sensor accessory](#cover-sensor-accessory)
- [Custom firmware](#custom-firmware)

# Basic controls

After upgrading your Maxxfan with Minuet, you'll find that most controls work the same way as before.  Press buttons on the [keypad](#using-the-maxxfan-keypad-and-6-key-wall-remote), [6 key wall remote](#using-the-maxxfan-keypad-and-6-key-wall-remote), [4 key wall remote](#using-the-4-key-wall-remote), or [infrared remote](#using-the-maxxfan-infrared-remote) to start the fan, open the lid, turn on auto mode, and so on.  However, some controls are different.

By default, Minuet offers [enhanced controls](#enhanced-controls) with a few new button combinations that make auto mode more powerful and easier to use.  However, if you prefer how the buttons worked before your upgrade, then you can activate the [standard controls](#standard-controls) instead.  We suggest trying out the enhanced controls for a while if you're not sure what you prefer.

## Using the Maxxfan keypad and 6 key wall remote

The Maxxfan keypad is the primary interface for controlling the fan as it is built right into the fan housing.  The Maxxfan 6 key wall remote offers the same functions as the keypad (except for the `rain sensor` button on some models) so for brevity we will only speak of the keypad in this guide.

Most of the keypad controls are self-explanatory according to their labels.  Minuet uses additional unlabeled button combinations for less common controls as summarized in the [quick reference](#quick-reference) that follows.

### Quick reference

These buttons combinations work differently with [enhanced controls](#enhanced-controls) or [standard controls](#standard-controls) in manual and auto mode.

| Button combination                 | Enhanced controls (default)    | Standard controls in manual mode | Standard controls in auto mode |
| ---------------------------------- | ------------------------------ | -------------------------------- | ------------------------------ |
| press `up`                         | fan speed up                   | fan speed up                     | auto thermostat target up      |
| hold `up` for 1 second             | fan speed maximum              | fan speed maximum                |                                |
| press `down`                       | fan speed down                 | fan speed down                   | auto thermostat target down    |
| hold `down` for 1 second           | fan speed minimum              | fan speed mimimum                |                                |
| press `on/off`                     | fan on/off toggle              | fan on/off toggle                | activate manual mode           |
| press `open/close`                 | lid position toggle            | lid position toggle              |                                |
| press `auto`                       | auto/manual mode toggle        | activate auto mode               | activate manual mode           |
| hold `auto` for 3 seconds          | reset auto mode settings       |                                  | reset auto mode settings       |
| hold `auto` and press `up`         | auto thermostat target up      |                                  |                                |
| hold `auto` and press `down`       | auto thermostat target down    |                                  |                                |
| hold `auto` and press `on/off`     | auto fan mode toggle           |                                  |                                |
| hold `auto` and press `in/out`     | auto fan direction toggle      |                                  |                                |
| hold `auto` and press `open/close` | auto lid position toggle       |                                  |                                |

These button combinations work the same in all modes.

| Button combination                           | Behavior                                               |
| -------------------------------------------- | ------------------------------------------------------ |
| press `in/out`                               | fan direction toggle                                   |
| press `rain sensor`                          | rain sensor toggle (only for models with rain sensors) |
| hold `auto` and `up` for 5 seconds           | use enhanced controls                                  |
| hold `auto` and `down` for 5 seconds         | use standard controls                                  |
| hold `on/off` and `up` for 5 seconds         | power on restore toggle                                |
| hold `on/off` and `down` for 5 seconds       | radio on/off toggle                                    |
| hold `on/off` and `down` for 8 seconds       | radio on and activate pairing mode                     |
| hold `on/off` and `in/out` for 5 seconds     | manual safety lock toggle                              |
| hold `on/off` and `open/close` for 5 seconds | keypad indicator toggle                                |
| hold `on/off` for 5 seconds                  | reboot                                                 |
| hold `on/off` for 15 seconds                 | factory reset                                          |

These button combinations become available when you have the corresponding accessory installed.

| Button combination               | Light accessory         |
| -------------------------------- | ----------------------- |
| hold `in/out` for 1 second       | light on/off toggle     |
| hold `in/out` for press `up`     | light brightness up     |
| hold `in/out` for press `down`   | light brightness down   |
| hold `in/out` for press `on/off` | light preset mode cycle |

### Enhanced controls

When using the enhanced controls, the buttons always behave the same way regardless of whether the device is in manual or auto mode so there's less chance for mistakes, unlike the [standard controls](#standard-controls).

You can easily take control of the fan when you need more ventilation right away (like when the toast is burning) regardless of the current mode.  If you happen to change the fan speed or lid position while auto mode is active then a manual override occurs: the change happens immediately, the device returns to manual mode, and the `auto` indicator blinks a few times as a reminder.

*To activate the enhanced controls, press and hold `auto` and `up` simultaneously for 5 seconds, listen for three quick tones followed by a long high tone.*

#### Button combinations in any mode

- Press `up`: increase the fan speed by one step
- Hold `up` for 1 second: increase the fan speed to maximum
- Press `down`: decrease the fan speed by one step
- Hold `down` for 1 second: decrease the fan speed to minimum
- Press `in/out`: toggle the fan direction between air in and air out
- Press `on/off`: toggle the fan off or turn it on the fan speed last used in manual mode
- Press `open/close` (`up` and `down` together): toggle the lid position open or closed
- Press `auto`: toggle between auto and manual mode
- Hold `auto` for 3 seconds: reset auto mode settings to the [default preset](#presets) (with the auto thermostat target set to 78 °F or 26 °C), listen for a quick rising, falling, and rising tone
- Hold `auto` and press `up`: increase the auto thermostat target by 1 °F or 0.5 °C, listen for a quick rising tone
- Hold `auto` and press `down`: decrease the auto thermostat target by 1 °F or 0.5 °C, listen for a quick falling tone
- Hold `auto` and press `on/off` one or more times then release: change the thermostat settings according to the number of presses of `on/off` as indicated in the following table, listen for one long tone and a number of quick tones equal to the key presses for the setting

  | Presses | Auto thermostat settings      | Behavior                                                |
  | ------- | ----------------------------- | ------------------------------------------------------- |
  | 1       | fan mode `AUTO`, fan speed 10 | adjust fan speed for optimal ventilation (default)      |
  | 2       | fan mode `AUTO`, fan speed 3  | adjust fan speed to balance quietness and ventilation   |
  | 3       | fan mode `OFF`                | keep fan off for passive ventilation to save power      |
  | 4       | fan mode `ON`, fan speed 3    | operate fan at low speed                                |
  | 5       | fan mode `ON`, fan speed 7    | operate fan at medium speed                             |
  | 6       | fan mode `ON`, fan speed 10   | operate fan at high speed                               |

- Hold `auto` and press `in/out` one or more times then release: change the auto fan direction setting according to the number of presses of `in/out` as indicated in the following table, listen for one long tone and a number of quick tones equal to the key presses for the setting

  | Presses | Auto fan direction | Behavior                                                         |
  | ------- | ------------------ | ---------------------------------------------------------------- |
  | 1       | `AUTO`             | keep the same fan direction as was used in manual mode (default) |
  | 2       | `AIR OUT`          | change the fan direction to air out when auto mode activates     |
  | 3       | `AIR IN`           | change the fan direction to air in when auto mode activates      |

- Hold `auto` and press `open/close` one or more times then release: change the auto lid position setting according to the number of presses of `open/close` as indicated in the following table, listen for one long tone and a number of quick tones equal to the key presses for the setting

  | Presses | Auto lid position | Behavior                                                         |
  | ------- | ----------------- | ---------------------------------------------------------------- |
  | 1       | `AUTO`            | open the lid only when auto mode calls for ventilation (default) |
  | 2       | `OPEN`            | open the lid when auto mode activates and keep it open           |
  | 3       | `CLOSED`          | close the lid when auto mode activates and keep it closed        |

### Standard controls

When using the standard controls, the buttons behave differently depending on whether the device is in manual or auto mode like the original Maxxfan controls.

Check the state of the `auto` indicator light before pressing buttons to avoid surprises like accidentally changing the thermostat target instead of the fan speed.  The manual override feature is not available.

*To activate the standard controls, press and hold `auto` and `down` simultaneously for 5 seconds, listen for three quick tones followed by a long long tone.*

#### Buttons in manual mode (`auto` indicator is unlit)

In manual mode, the `up` and `down` buttons control the fan speed and the `on/off` button toggles the fan on or off.

- Press `up`: increase the fan speed by one step
- Hold `up` for 1 second: increase the fan speed to maximum
- Press `down`: decrease the fan speed by one step
- Hold `down` for 1 second: decrease the fan speed to minimum
- Press `in/out`: toggle the fan direction between air in and air out
- Press `on/off`: toggle the fan off or turn it on at its last configured manual fan speed
- Press `open/close` (`up` and `down` together): toggle the lid open or closed
- Press `auto`: activate auto mode from manual mode

#### Buttons in auto mode (`auto` indicator is lit)

In auto mode, the `up` and `down` buttons control the auto thermostat target, the `on/off` button exits auto mode.

- Press `up`: increase the auto thermostat target by 1 °F or 0.5 °C, listen for a quick rising tone
- Press `down`: decrease the auto thermostat target by 1 °F or 0.5 °C, listen for a quick falling tone
- Press `in/out`: toggle the fan direction between air in and air out
- Press `on/off`: return to manual mode from auto mode
- Press `open/close` (`up` and `down` together): *inoperable because the lid cannot be controlled in auto mode*
- Press `auto`: return to manual mode from auto mode
- Hold `auto` for 3 seconds: reset auto mode settings to the [default preset](#presets) (with the auto thermostat target set to 78 °F / 26 °C), listen for a quick rising, falling, and rising tone

## Using the Maxxfan 4 key wall remote

The Maxxfan 4 key wall remote only supports 4 speed manual fan operation.

### Button combinations

- Press `fan on`: turn fan on at its last configured manual fan speed if it was off, otherwise cycle through 4 increasing speeds of 10%, 30%, 70%, and 100% in a loop
- Hold `fan on` for 1 second: turn fan on at maximum speed
- Press `fan off`: turn fan off
- Press `open`: open lid
- Press `close`: close lid

## Using the Maxxfan infrared remote

Point the infrared remote at the transparent dome in the Maxxfan keypad and press buttons to control the fan, lid, and auto mode.

- Press `fan on/off`: toggle the fan off or turn it on at its last configured manual fan speed
- Press `fan speed up`: increase the fan speed by one step
- Press `fan speed down`: decrease the fan speed by one step
- Press `temperature up`: increase the auto thermostat target by one unit
- Press `temperature down`: increase the auto thermostat target by one unit
- Press `temperature up` and `temperature down` together: toggle the temperature units shown on the remote between Celsius and Fahrenheit
- Press `auto`: toggle between auto and manual mode
- Press `open/close` (`up` and `down` together): toggle the lid position open or closed
- Press `in/out`: toggle the fan direction between air in and air out

Sometimes when you press a button to do one thing (such as to change the fan speed) you may observe other changes too (such as the fan lid closing) as Minuet catches up to what the remote displays.  Communication from the remote to Minuet is strictly one-way so the remote may display inaccurate information.  Notably, the remote displays the ambient temperature measured by its built-in sensor; not by the sensor actually used by the auto mode thermostat.

Refer to the instructions originally provided with the Maxxfan infrared remote for more details.

# Features

## Auto mode

Minuet's auto mode feature provides ventilation when needed based on the ambient conditions including temperature, humidity, CO₂ (carbon dioxide) concentration, and AQI (air quality index).

Press the `auto` button on the [keypad](#using-the-built-in-keypad) to toggle between auto and manual mode.  The `auto` LED turns green when you activate auto mode and turns off when you activate manual mode.  You can also control auto mode with the [infrared remote](#using-the-maxxfan-infrared-remote).

In auto mode, an algorithm automatically controls the fan speed, fan direction, and lid position according to the ambient conditions and settings.  If you change the fan speed or lid position manually while auto mode is active, the device reverts to manual mode and returns control to you.

Auto mode consists of several functions that work together to provide ventilation in response to different conditions.  When multiple functions call for ventilation at the same time, the fan speed is determined by the greatest of their demands.

  - The [thermostat function](#thermostat-function) calls for ventilation when the ambient temperature is too high.
  - The [humidistat function](#humidistat-function) calls for ventilation when the ambient humidity is too high.
  - The [CO₂ monitor function](#co-monitor-function) calls for ventilation when the ambient CO₂ concentration is too high.
  - The [AQI monitor function](#aqi-monitor-function) pauses ventilation when the outdoor air quality is poor.

You can configure a few basic settings including the thermostat target, fan direction, and lid position with the keypad.  To access other settings and [presets](#presets), you must use an app.

### Common settings

The following settings apply to all auto mode functions.

| Setting name         | Default | Range                       | Where to configure     |
| -------------------- | ------- | --------------------------- | ---------------------- |
| `auto fan direction` | `AUTO`  | `AUTO`, `AIR OUT`, `AIR IN` | keypad, app            |
| `auto lid position`  | `AUTO`  | `AUTO`, `OPEN`, `CLOSED`    | keypad, app            |

| Auto fan direction | Behavior                                                     |
| ------------------ | ------------------------------------------------------------ |
| `AUTO`             | keep the same fan direction as was used in manual mode       |
| `AIR OUT`          | change the fan direction to air out when auto mode activates |
| `AIR IN`           | change the fan direction to air in when auto mode activates  |

| Auto lid position | Behavior                                                                   |
| ----------------- | -------------------------------------------------------------------------- |
| `AUTO`            | open the lid when auto mode calls for ventilation, close the lid otherwise |
| `OPEN`            | open the lid when auto mode activates and keep it open                     |
| `CLOSED`          | close the lid when auto mode activates and keep it closed                  |

### Thermostat function

The thermostat function calls for ventilation when the ambient temperature rises above the `auto thermostat target` temperature by the `auto thermostat hysteresis upper` threshold.  Conversely, it stops calling for ventilation when the ambient temperature drops below the `auto thermostat target` temperature by the `auto thermostat hysteresis lower`.

Enable or disable the thermostat function by setting `auto thermostat mode` to `COOL` or `OFF`.

When `auto thermostat fan mode` is `AUTO`, the thermostat sets the fan speed proportional to the difference between the ambient temperature and the `auto thermostat target` temperature and it achieves the `auto thermostat fan speed` when the difference meets or exceeds the `auto thermostat dynamic range`.  Proportional control helps cool the occupants faster because increasing air flow when it's hotter evaporates sweat from the skin more effectively.  When the fan mode is `ON`, the thermostat sets the fan speed to `auto thermostat fan speed` without proportional control.  When the fan mode is `OFF`, the thermostat keeps the fan off and may still open the lid for passive ventilation.

Minuet always uses Celsius temperature units for its thermostat calculations and converts temperatures from Fahrenheit to Celsius when needed.  Configure the `auto thermostat step` setting to choose whether the temperature changes in units of *1 °F* or *0.5 °C* when you adjust the target with the keypad controls or the IR remote.  The default step is *1 °F* to emulate the original Maxxfan controls more accurately.  We recommend changing the step to *0.5 °C* if you use Home Assistant.

By default, the thermostat measures the ambient temperature with the built-in thermistor that is embedded in the fan trim.  You can pick a different `auto temperature sensor` when a suitable accessory is installed.

| Setting name                        | Default        | Range                                        | Where to configure     |
| ----------------------------------- | -------------- | -------------------------------------------- | ---------------------- |
| `auto thermostat mode`              | `COOL`         | `COOL`, `OFF`                                | keypad, IR remote, app |
| `auto thermostat target`            | 26 °C / 78 °F  | -5 °C to 50 °C / 23 °F to 122 °F             | keypad, IR remote, app |
| `auto thermostat fan mode`          | `AUTO`         | `AUTO`, `ON`, `OFF`                          | keypad, app            |
| `auto thermostat fan speed`         | 10             | 0 to 10                                      | keypad, app            |
| `auto thermostat dynamic range`     | 5 °C           | 0 °C to 10 °C                                | app                    |
| `auto thermostat hysteresis upper`  | 0.5 °C         | 0 °C to 2 °C                                 | app                    |
| `auto thermostat hysteresis lower`  | 0.5 °C         | 0 °C to 2 °C                                 | app                    |
| `auto thermostat step`              | 1 °F           | 1 °F, 0.5 °C                                 | app                    |
| `auto temperature sensor`           | best available | built-in thermistor or installed accessories | app                    |

Note: In the API, the `mode`, `target`, and `fan mode` settings are part of the `auto thermostat` climate entity.

### Humidistat function

The humidistat function calls for ventilation when the ambient humidity rises above the `auto humidistat trigger threshold` while the ambient temperature is above the `auto humidistat minimum temperature`.  Conversely, it stops calling for ventilation when the ambient humidity drops below the `auto humidistat clear threshold` or the `auto humidistat maximum runtime` has elapsed.

Enable or disable the humidistat function by setting `auto humidistat mode` to `AUTO` or `OFF`.

The `auto humidistat fan speed` determines the fan speed.  Choose a fan speed, clear threshold, and runtime that is sufficient for removing moist air from the cabin without chilling the occupants.

The humidistat may be useful for automatically venting the cabin after showering indoors.  Set the humidistat's minimum temperature near what it would be while the cabin is occupied (and perhaps heated for comfort) to prevent the humidistat from calling for ventilation when it is foggy or freezing outside because relative humidity increases as ambient temperature decreases.  In especially humid climates, you may need to disable the humidistat to prevent false triggering.

You must install an accessory with a humidity sensor to use this function.

| Setting name                          | Default           | Range                                | Where to configure     |
| ------------------------------------- | ----------------- | ------------------------------------ | ---------------------- |
| `auto humidistat mode`                | `OFF`             | `AUTO` or `OFF`                      | app                    |
| `auto humidistat clear threshold`     | 60%               | 5% to 100%                           | app                    |
| `auto humidistat trigger threshold`   | 90%               | 5% to 100%                           | app                    |
| `auto humidistat fan speed`           | 3                 | 0 to 10                              | app                    |
| `auto humidistat minimum temperature` | 15 °C             | -5 °C to 50 °C / 23 °F to 122 °F     | app                    |
| `auto humidistat maximum runtime`     | 15 minutes        | 0 to 60 minutes                      | app                    |
| `auto humidity sensor`                | best available    | installed accessories                | app                    |

### CO₂ monitor function

Carbon dioxide accumulates in enclosed spaces occupied by people.  Elevated CO₂ concentration may indicate that the space has insufficient ventilation which may be harmful to the health of the occupants.

The CO₂ monitor function calls for ventilation when the ambient CO₂ concentration rises above the `CO₂ monitor level N threshold`.  You can configure threshold for two levels of increasing CO₂, each of which has an associated `auto CO₂ monitor level N fan speed`.  Conversely, the function stops calling for ventilation when the ambient CO₂ concentration falls below the `CO₂ monitor clear threshold`.

Enable or disable the CO₂ monitor function by setting `auto CO₂ monitor mode` to `AUTO` or `OFF`.

You must install an accessory with a CO₂ sensor to use this function.

| Setting name                         | Default           | Range                                | Where to configure     |
| ------------------------------------ | ----------------- | ------------------------------------ | ---------------------- |
| `auto CO₂ monitor mode`              | `OFF`             | `AUTO` or `OFF`                      | app                    |
| `auto CO₂ monitor clear threshold`   | 500 ppm           | 400 to 5000 ppm                      | app                    |
| `auto CO₂ monitor level 1 threshold` | 800 ppm           | 400 to 5000 ppm                      | app                    |
| `auto CO₂ monitor level 1 fan speed` | 0                 | 0 to 10                              | app                    |
| `auto CO₂ monitor level 2 threshold` | 1200 ppm          | 400 to 5000 ppm                      | app                    |
| `auto CO₂ monitor level 2 fan speed` | 3                 | 0 to 10                              | app                    |
| `auto CO₂ sensor`                    | best available    | installed accessories                | app                    |

### AQI monitor function

The [Air Quality Index (AQI)](https://en.wikipedia.org/wiki/Air_quality_index) is a measure of ambient air pollution to provide guidance about the health risk of airborne pollutants such as smoke and fine dust particles.  This auto mode function reduces contamination within the cabin by closing the vent when the air quality is poor.  It is particularly useful when the vehicle is unattended and you cannot react to close the vent yourself.

Minuet implements the US EPA AQI scale (which may differ from that of your local jurisdiction).  It is defined as follows:

| AQI Range  | Category                        |
| ---------- | ------------------------------- |
| 0 to 50    | Good                            |
| 51 to 100  | Moderate                        |
| 101 to 150 | Unhealthy for Sensitive Groups  |
| 151 to 200 | Unhealthy                       |
| 201 to 300 | Very Unhealthy                  |
| 301 to 500 | Hazardous                       |

The AQI monitor function inhibits ventilation (stops the fan and closes the lid) when the Air Quality Index (AQI) rises above the `AQI monitor trigger threshold` for at least `AQI monitor trigger duration`.  It resumes ventilation when the AQI falls below the `AQI monitor clear threshold` for at least `AQI monitor clear duration`.

Enable or disable the AQI monitor function by setting `auto AQI monitor mode` to `AUTO` or `OFF`.

You must install an accessory with an AQI sensor to use this function.  The sensor should be positioned so that it can sample the air outside of the vehicle at all times or at least while the lid is open.  When the sensor is positioned under the lid, we recommended setting a relatively long `AQI monitor clear duration` to prevent the lid from reopening soon after it closes and obstructs the sensor.  Similarly, if the AQI monitor function triggers while cooking indoors, consider extending the `auto AQI monitor trigger duration` to reduce its sensitivity.

| Setting name                         | Default           | Range                                | Where to configure     |
| ------------------------------------ | ----------------- | ------------------------------------ | ---------------------- |
| `auto AQI monitor mode`              | `OFF`             | `AUTO` or `OFF`                      | app                    |
| `auto AQI monitor clear threshold`   | 100               | 0 to 500                             | app                    |
| `auto AQI monitor clear duration`    | 120 minutes       | 0 to 1440 minutes                    | app                    |
| `auto AQI monitor trigger threshold` | 151               | 0 to 500                             | app                    |
| `auto AQI monitor trigger duration`  | 5 minutes         | 0 to 60 minutes                      | app                    |
| `auto AQI sensor`                    | best available    | installed accessories                | app                    |

### Presets

Minuet lets you customize four auto mode presets for common situations and quickly recall them with an app.  They are called `HOME`, `SLEEP`, `AWAY`, and `ECO`.  The `DEFAULT` preset applies the factory default settings and cannot be customized.

The following table shows default settings for each preset.

| Setting name                         | Preset `DEFAULT` | Preset `HOME` | Preset `SLEEP` | Preset `AWAY` | Preset `ECO`  |
| ------------------------------------ | ---------------- | ------------- | -------------- | ------------- | ------------- |
| `auto (preset) fan direction`        | `AUTO`           | `AUTO`        | `AUTO`         | `AUTO`        | `AUTO`        |
| `auto (preset) lid position`         | `AUTO`           | `OPEN`        | `OPEN`         | `AUTO`        | `AUTO`        |
| `auto (preset) thermostat on`        | `ON`             | `ON`          | `ON`           | `ON`          | `ON`          |
| `auto (preset) thermostat target`    | 26 °C / 78 °F    | 25 °C / 77 °F | 25 °C / 77 °F  | 30 °C / 86 °F | 35 °C / 95 °F |
| `auto (preset) thermostat fan mode`  | `AUTO`           | `AUTO`        | `AUTO`         | `ON`          | `OFF`         |
| `auto (preset) thermostat fan speed` | 10               | 10            | 3              | 3             | 1             |
| `auto (preset) humidistat on`        | `OFF`            | `ON`          | `ON`           | `OFF`         | `OFF`         |
| `auto (preset) CO₂ monitor on`       | `OFF`            | `ON`          | `ON`           | `OFF`         | `OFF`         |

> [!TIP]
> By default, the `HOME` and `SLEEP` presets keep the lid open for passive ventilation to minimize lid motor noise while the vehicle is presumed to be occupied.

## Rain sensor

Some Maxxfan models with a low profile lid have a rain sensor feature to close the lid in inclement weather.  The rain sensor is not installed (or needed) in models with a canopy style lid that inherently keeps the rain out.  *The rain sensor is enabled by default.*

To enable or disable the rain sensor, press the `rain sensor` button.  Look for the LED to turn red when the rain sensor is disabled as awarning that water could enter your vehicle if it rains.  Look for the LED to turn off when the rain sensor is enabled.

When the rain sensor detects moisture, it stops the fan, closes the lid, makes the LED flash red, and activates the rain sensor [safety lock](#safety-lock) to disallow operation.  Press the `rain sensor` button again to reset the flashing LED and release the rain sensor safety lock to allow operation.

## Battery monitor

The battery monitor checks whether the supply voltage is within Minuet's normal operating range.  If not, it stops the fan, closes the lid, and activates the battery [safety lock](#safety-lock) until the battery voltage recovers (with a hysteresis of 0.4 V).

The battery monitor has the following settings.

| Setting name                  | Default | Range                       | Where to configure     |
| ----------------------------- | ------- | --------------------------- | ---------------------- |
| `battery voltage low limit`   | 10.6 V  | 10.0 to 15.0 V              | app                    |
| `battery voltage high limit`  | 15.0 V  | 10.0 to 15.0 V              | app                    |

> [!IMPORTANT]
> The voltage that the battery monitor observes may be less than what you measure directly at the battery terminals because it accounts for the voltage drop in the wiring between the battery and the control board.  The observed voltage may be further reduced while the fan motor, lid motor, and accessories are operating and it could trigger the battery safety lock (because the voltage drop increases in proportion to the current consumed by the device).

## Safety lock

The safety lock feature closes the lid and prevents the fan and some accessories from operating in certain conditions.  When a safety lock condition blocks an action, you will hear three quick tones followed by a number of lower pitch tones as a warning.  Count the number of lower pitch tones and consult the following table to identify the cause.

| Safety lock | Condition                                                         | Resolution                                                                                                                     | Tones |
| ----------- | ----------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------ | ----- |
| Battery     | The battery voltage is too low to too high.                       | Wait for the battery voltage to return to the normal operating range or adjust the low or high battery voltage thresholds.     | 1     |
| Rain        | The rain sensor is enabled and detected moisture.                 | Press the `rain sensor` button to reset or turn off the rain sensor.                                                           | 2     |
| Accessory   | An accessory triggered the `LOCK` signal.                         | Consult the documentation of your accessories for details. For example, if you have a vent cover sensor then remove the cover. | 3     |
| Manual      | The [manual safety lock](#manual-safety-lock) is enabled.         | Disable the [manual safety lock](#manual-safety-lock).                                                                         | 4     |
| Automation  | The [automation safety lock](#automation-safety-lock) is enabled. | Disable the [automation safety lock](#automation-safety-lock).                                                                 | 5     |

### Manual safety lock

Use the manual safety lock to temporarily disallow use of the device.  It can help you prevent accidental usage to keep out dust and wildfire smoke in extreme conditions or discourage an inappropriately inquisitive child from turning on the fan.  *The manual safety lock is disabled by default.*

To toggle the manual safety lock, hold `on/off` and `in/out` together for 5 seconds.  Listen for two quick tones followed by a long high tone when the manual safety lock is enabled.  Listen for two quick tones followed by a long low tone when the manual safety lock is disabled.

### Automation safety lock

Use the automation safety lock to develop automations that temporarily disallow use of the device under software defined conditions.  Unlike [manual safety lock](#manual-safety-lock), the automation safety lock cannot be toggled using the keypad; it can only be toggled programmatically using an app.  *The automation safety lock is disabled by default.*

For example, you could configure your home automation system to enable the automation safety lock while driving to reduce road noise and fumes in the cabin then disable it once parked.

## Power on restore

The power on restore feature saves the fan speed, direction, and lid position whenever the fan is running under manual control.  When the device reboots (typically after a power loss) and the power on restore feature is enabled, it restores the saved state and continues operating as before; otherwise, it closes the lid and keeps the fan off.  *The power on restore feature is disabled by default.*

To toggle power on restore behavior, hold `on/off` and `up` together for 5 seconds.  Listen for a quick rising, falling, and rising tone followed by a long high tone when the power on restore feature is enabled.  Listen for a quick rising, falling, and rising tone followed by a long low tone when the power on restore feature is disabled.

## Suppress keypad indicators

The keypad indicators normally stay lit whenever they have something to tell you.  If you find them distracting (while you're trying to sleep at night), then you can use this feature to suppress them.  While suppressed, the keypad indicators will turn themselves off a few seconds instead of remaining lit.  Pressing any key on the keypad briefly reawakens the suppressed keypad indicators.  *The keypad indicators are unsuppressed by default.*

To toggle keypad indicator suppression, hold `on/off` and `open/close` (`up` and `down`) together for 5 seconds.  Look for the keypad indicators to slow blink twice then turn off when they are suppressed.  Look for the keypad indicators to slow blink three times then resume normal operation when they are unsuppressed.

Indicator meanings:

| Indicator | State           | Meaning                                                                           |
| --------- | --------------- | --------------------------------------------------------------------------------- |
| `auto`    | solid green     | auto mode is active                                                               |
| `auto`    | blinking green  | auto mode was manually overridden                                                 |
| `rain`    | solid red       | rain sensor is disabled (only for models with rain sensors)                       |
| `rain`    | blinking red    | rain sensor detected rain and stopped the fan (only for models with rain sensors) |

## Reboot

A reboot saves settings then restarts Minuet.  It can be useful while [provisioning](#provisioning) the device.

To reboot the device, hold `on/off`, listen for a beep after 5 seconds, then release the button and listen for two descending tones.

Alternatively, you can press the **Reset** button on the side of the Minuet circuit board or briefly disconnect then reconnect power at the fuse box.

## Factory reset

A factory reset erases all saved settings including provisioned credentials then restarts Minuet.  Upon restart, Minuet loads factory default settings from the firmware.  Note that the firmware itself is not affected by a factory reset (in case you have customized it).

To factory reset the device, hold `on/off`, listen for a beep after 5 seconds, keep holding the button for 10 more seconds, listen for four descending tones, then release the button.

## Fan motor health monitoring

Minuet monitors the health of the fan motor and automatically slows down or stops the fan when it detects a problem.  These problems should be rare and they are often resolved by waiting for the device to cool, starting the fan again, or by performing occasional cleaning and maintenance of the components.

Running the fan at high speeds for a long time in a hot environment can produce an overtemperature warning from the motor driver chip.  When this happens, Minuet will keep running the fan and temporarily limit its maximum speed.  If the chip keeps get hotter then eventually it may report an overtemperature fault and the fan will stop.

When a fan motor fault occurs, you will hear three quick tones.  The *fan status* entity in the app shows the cause of the fault and you may find additional information in the internal logs.

| Possible cause                    | Resolution                                                                     |
| --------------------------------- | ------------------------------------------------------------------------------ |
| fan motor disconnected            | ensure that the fan motor is plugged in and that its wires are intact          |
| fan motor stalled                 | ensure that the fan blade spins freely and is not obstructed                   |
| overcurrent fault                 | ensure that the fan motor wires are intact (no short-circuit)                  |
| overtemperature fault             | allow the device to cool then resume operation at a lower speed                |
| undervoltage or overvoltage fault | ensure that the power supply can provide at least 5 amps at 10 to 16 volts     |

If the issue persists, please ask for support.

## Lid motor health monitoring

Minuet monitors the health of the lid motor and automatically stops the lid when it detects a problem.  These problems should be rare and they are often resolved by performing occasional cleaning and maintenance of the components.

When a lid motor fault occurs, you will hear four quick tones.  The *lid status* entity in the app shows the cause of the fault and you may find additional information in the internal logs.

| Possible cause                    | Resolution                                                                     |
| --------------------------------- | ------------------------------------------------------------------------------ |
| lid motor disconnected            | ensure that the lid motor is plugged in and that its wires are intact          |
| lid stuck or movement too slow    | ensure that the lid can travel freely when you turn the knob                   |
| overcurrent fault                 | ensure that the lid motor wires are intact (no short-circuit)                  |

If the issue persists, please ask for support.

## Failsafe restart

Minuet monitors the state of its software components and automatically restarts when it detects a problem.  These problems should be rare.

When a software fault is detected, you will hear four quick tones and one long tone.  Minuet waits 3 minutes to allow you some time to collect diagnostic information, then you will the same tones again and the device will reboot.

If you have installed custom Minuet firmware, please review your changes and examine the internal logs.  If the issue persists, please ask for support.

# Connectivity

Minuet's low power radio offers convenience and connectivity for apps, Home Assistant integration, provisioning, and firmware updates.

  - Bluetooth 5 LE (low energy): Connects to nearby devices, used for provisioning
  - 2.4 GHz WiFi 6: Connects to your local WiFi network

With the Minuet app over Bluetooth, you can control Minuet from your devices when you are nearby.

With the Home Assistant integration over WiFi, you can control Minuet from your home automation dashboard and collect data from its sensors.  If you have configured Home Assistant for remote access then you can control Minuet with the Home Assistant app from anywhere.

> [!IMPORTANT]
> Minuet only ever communicates with apps running on nearby devices or on your local network; it never talks to the cloud on its own (even for firmware updates).  To obtain remote access, you must install suitable infrastructure to communicate with Minuet on your local network, such as Home Assistant.

## Radio mode

Minuet disables Bluetooth and WiFi initially, for security.  Using the keypad, you can turn the radios on when need connectivity and turn them off later when you don't.  Minuet remembers whether the radios are on or off and restores them to that state after reboots.

To toggle the radios on or off, hold `on/off` and `down` together, listen for a beep after 5 seconds, then release the button.  Listen for four quick tones followed by a long high tone when the radios are turned on.  Listen for four quick tones followed by a long low tone when the radios are turned off.

To turn the radios on and activate pairing mode, hold `on/off` and `down` together, listen for a beep after 5 seconds, keep holding the button for 3 more seconds, listen for four quick tones followed by a long high tone and a low and high tone when pairing mode activates, then release the button.  

Look for the auto indicator to flash quickly while pairing mode is active.  Pairing mode will remain active for 2 minutes.  While pairing mode is active, the device will accept Bluetooth connections from new devices and allow provisioning WiFi credentials over Bluetooth.

To erase all settings and forget all paired devices, perform a [factory reset](#factory-reset).

## Provisioning

Minuet is *unprovisioned* initially, for security.  Before you can connect Minuet to apps running on your local network, such for Home Assistant integration, you must *provision* WiFi network credentials and the API encryption key.

To erase all settings and return the device to an unprovisioned state, perform a [factory reset](#factory-reset).

### Setup WiFi

There are a few ways to connect Minuet to WiFi.  Choose an appropriate method for your situation.

> [!IMPORTANT]
> Never connect Minuet to public WiFi networks!

> [!TIP]
> After connecting Minuet to your local WiFi network, we recommend configuring your network router to assign Minuet a static DHCP entry so that it always receives the same host name and IP address.  This change makes it easier to connect to Minuet reliably.

#### Setup WiFi with Improv over Bluetooth LE (recommended)

1. Navigate to [www.improv-wifi.com](https://www.improv-wifi.com/) in a web browser.  Locate the button labeled *Connect device to WiFi* under *Improv over BLE*.  If this button is not available then try a different browser or one of the other methods.  Ensure that Bluetooth is enabled.

1. Use the keypad to [reboot](#reboot) Minuet and reopen the provisioning window for the next five minutes.

1. Use the keypad to [turn the radios on and activate pairing mode](#radio-mode) for the next two minutes.

1. In the web browser, *Connect device to WiFi* under *Improv over BLE*.

1. The web app will scan for nearby Bluetooth devices and show them in dialog.  Search for a device with a name like "Minuet-123456" and connect to it.

1. If the web app asks you to press the authorization button on the device then use the keypad to activate pairing mode again.

1. The web app will ask for your WiFi network SSID and password.  Provide them and wait for Minuet to connect.

1. Success!  Minuet is now connected to your local WiFi network.  Proceed to [setup API encryption](#setup-api-encryption).

#### Setup WiFi with Improv over serial

1. Navigate to [www.improv-wifi.com](https://www.improv-wifi.com/) in a web browser.  Locate the button labeled *Connect device to WiFi* under *Improv over serial*.  If this button is not available then try a different browser or one of the other methods.

1. Connect a long USB C cable from Minuet to the device your web browser is running on.

1. Use the keypad to [reboot](#reboot) Minuet and reopen the provisioning window for the next five minutes.

1. Use the keypad to [turn the radios on and activate pairing mode](#radio-mode) for the next two minutes.

1. In the web browser, *Connect device to WiFi* under *Improv over serial*.

1. The web app will ask for your WiFi network SSID and password.  Provide them and wait for Minuet to connect.

1. Success!  Minuet is now connected to your local WiFi network.  Proceed to [setup API encryption](#setup-api-encryption).

### Setup API encryption

Once you [setup WiFi](#setup-wifi) and Minuet is connected to your local WiFi network, you must use one of the [apps](#apps) to setup API encryption and thereby complete the provisioning process.

Use the keypad to [reboot](#reboot) Minuet and reopen the provisioning window for the next five minutes.

Follow the instructions for your chosen app on how to adopt a Minuet / ESPHome device and complete provisioning within the allotted time.  In general, when the app discovers an your provisioned Minuet device, it will offer to adopt the device and setup API encryption.  As a security precaution, Minuet will reject unencrypted connections from apps after the provisioning window closes (reboot Minuet to try again).

## Bluetooth pairing

To pair your phone or computer with Minuet over Bluetooth, use the keypad to [turn on the radio and initiate pairing mode](#radio-mode).

Following the instructions of your app or operating system, search for your Minuet device with a name like "Minuet-123456" and connect to it.  The name might be different if you have changed it.

# Apps

## Home Assistant

TODO

## ESPHome Device Builder

TODO

## Minuet app (help wanted)

TODO

If you'd like to help build an app to control Minuet over Bluetooth LE or the local WiFi network, please contact us!

# Accessories

## Light accessory

The light accessory provides illumination from a ring of LEDs around the fan.

### Using the built-in keypad

Use the built-in keypad to control the light as follows.

- Hold `in/out` for 1 second: toggle the light on or off, the light's default color is white
- Hold `in/out` and press `up`: increase the brightness by one step, does nothing if the light is off or is already at maximum brightness
- Hold `in/out` and press `down`: decrease the brightness by one step, does nothing if the light is off or is already at minimum brightness
- Hold `in/out` and press `open/close` (`up` and `down` together): cycle through preset modes, turns the light on if it is off

The preset modes are: white, red, violet, and rainbow.

### Using the 24-key RGBW LED infrared remote control

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

![24-key RGBW LED remote](./24%20key%20rgbw%20led%20remote.jpg)

## Environmental sensor accessory

The Minuet environmental sensor accessory measures CO₂, temperature, humidity, and barometric pressure.  With the environmental sensor installed, Minuet can provide additional ventilation when the humidity or CO₂ level within the cabin exceeds a threshold.  Refer to [auto mode](#auto-mode) for details.

You can also view the data from these sensors with an app.

## Cover sensor accessory

The Minuet cover sensor detects when you attach or detach a magnetic vent cover to the fan's trim ring.  It's easy to use and there are no buttons to push.

When you attach the magnetic vent cover, the sensor activates the accessory safety lock function and turns off the fan and the light.

When you remove the magnetic vent cover, the sensor deactivates the accessory safety lock function and returns the fan and the light to normal operation.

> [!TIP]
> The best way to use the cover sensor is to configure the auto lid position setting to keep the lid open when auto mode is active.  Then leave auto mode enabled all of the time.  When you get ready to drive to a new location, attach the magnetic vent cover to reduce road noise and fumes in the cabin.  And when you arrive at your destination, detact the magnetic vent cover for passive or active ventilation while you're occupying the vehicle.  It feels like magic and easily becomes second nature!

# Custom firmware

You can compile and install custom firmware on your Minuet device and take complete control over its behavior.  This is a great option for folks who are familiar with the ESPHome framework and want to do more!

Refer to the [Minuet firmware repository](https://github.com/brown-studios/minuet-firmware) for instructions.
