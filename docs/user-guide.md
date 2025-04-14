# Minuet user guide

TODO: keypad, captive portal web interface, Home Assistant


## Getting started



## Using the built-in keypad and the 6 key wall remote

Minuet supports two different control schemes for the built-in keypad and the 6 key wall remote.  After all, why not improve on the fan controls when you're already replacing its brains!

Choose whichever scheme you prefer and follow the instructions to activate them.

### Standard controls

The standard controls mimic the original Maxxfan controls with a few *bonus* convenience features.

The buttons behave differently depending on whether the fan is in manual or in auto mode.  You might find the behavior confusing if you don't check what mode the fan is in before you start pressing buttons.

When using the standard controls, you cannot change the fan speed or open/close the cover while auto mode is active.  If Minuet receives a command from the ESPHome web app or API to change the fan speed or open/close the cover while auto mode is active, then returns to manual mode before performing the requested action.  This behavior differs from the [enhanced controls](#enhanced-controls) where such changes are allowed and override the behavior of the thermostat.

*To enable the standard controls, press and hold `auto` and `down` simultaneously for 5 seconds.  Minuet confirms with three quick tones followed by a long low tone.*

#### Buttons in manual mode (`auto` indicator is unlit)

In manual mode, the up/down buttons control the fan speed and the on/off button toggles the fan on or off.

- Press `up`: increase the fan speed by one
- Hold `up` for 1 second: increase the fan speed to maximum *(bonus)*
- Press `down`: decrease the fan speed by one
- Hold `down` for 1 second: decrease the fan speed to minimum *(bonus)*
- Press `open/close` (`up` and `down` together): toggle the cover open or closed
- Press `in/out`: toggle the fan direction between air in and air out
- Press `on/off`: toggle the fan off or turn it on at its last configured manual fan speed
- Press `auto`: enter auto mode

#### Buttons in auto mode (`auto` indicator is lit)

In auto mode, the up/down buttons control the thermostat temperature setpoint, the on/off button exits auto mode, and the thermostat controls the fan speed based on the ambient temperature.  The thermostat will turn the fan on in the direction it last operated in.

- Press `up`: increase thermostat temperature setpoint by 1 °F (~ 0.5 °C)
- Press `down`: decrease thermostat temperature setpoint by 1 °F (~ 0.5 °C)
- Press `open/close` (`up` and `down` together): *inoperable in this mode*
- Press `in/out`: toggle the fan direction between air in and air out
- Press `on/off`: return to manual mode, turn fan off, close cover
- Press `auto`: return to manual mode, turn fan off, close cover
- Hold `auto` for 3 seconds: reset thermostat temperature setpoint to 78 °F (~ 25.5 °C)

### Enhanced controls

The enhanced controls let you keep the automatic thermostat enabled while you manually override its behavior for particular situations like when you need extra ventilation for cooking indoors.  The buttons always behave the same way regardless of whether the thermostat is enabled.

While the thermostat is disabled, the `auto` indicator is unlit and the buttons control the fan state similar to the standard controls.

While the thermostat is enabled, the `auto` indicator is lit and the thermostat controls the fan state automatically based on the ambient temperature.  However, if you press a button or use the ESPHome web app or API to change the state of the fan change then your manual settings **override* the behavior of the thermostat.  This behavior differs from the [standard controls](#standard-controls) where such changes are disallowed unless the thermostat is disabled.

While the thermostat is overridden, the `auto` indicator blinks and the buttons control the fan state similar to the standard controls.  The thermostat will remain overridden state by your manual settings until you press `auto` to re-engage the thermostat.

Hold the `auto` button and press other buttons as described below to configure the thermostat's temperature setpoint, fan direction, and fan state.  By setting the thermostat controlled fan state to off you can make the thermostat open the cover for passive ventilation instead of running the fan.

*To enable the enhanced controls, press and hold `auto` and `up` simultaneously for 5 seconds.  Minuet confirms with three quick tones followed by a long high tone.*

#### Buttons

- Press `up`: increase the fan speed by one
- Hold `up` for 1 second: increase the fan speed to maximum *(bonus)*
- Press `down`: decrease the fan speed by one
- Hold `down` for 1 second: decrease the fan speed to minimum *(bonus)*
- Press `open/close` (`up` and `down` together): toggle the cover open or closed
- Press `in/out`: toggle the fan direction between air in and air out
- Press `on/off`: toggle the fan off or turn it on at its last configured manual fan speed
- Press `auto`: enable the thermostat if it is disabled, re-engage the thermostat if it is overridden, otherwise disable the thermostat
- Hold `auto` and press `up`: increase thermostat temperature setpoint by 1 °F (~ 0.5 °C), Minuet confirms with a quick rising tone
- Hold `auto` and press `down`: decrease thermostat temperature setpoint by 1 °F (~ 0.5 °C), Minuet confirms with a quick falling tone
- Hold `auto` and press `open/close` (`up` and `down` together): reset thermostat temperature setpoint to 78 °F (~ 25.5 °C), Minuet confirms with a quick turn
- Hold `auto` and press `in/out`: toggle thermostat controlled fan direction between same as manual, air in, and air out, Minuet confirms air in with a quick descending scale, air out with a quick rising scale, and same with two quick tones
- Hold `auto` and press `on/off`: toggle thermostat controlled fan state to be on or off (with the cover open in either case), Minuet confirms with a long rising tone for on or a long falling tone for off

### Rain sensor (only some models)

Press the `rain sensor` button to toggle the rain sensor on or off.

When the rain sensor is disabled, the LED will turn red to warn that water could enter your vehicle if it rains.

When the rain sensor detects moisture, it turns off the fan, closes the cover, and makes the LED flash red.  Press the `rain sensor` button again to reset the flashing LED.

### Lighting accessory (if installed)

Hold `in/out` for 1 second to toggle the light on or off.

Note: To dim the light, change its color, or activate effects, use the Minuet web app or your home automation app.  (Or try to implement better lighting controls in the Minuet firmware.  Perhaps holding `in/out` together with `up`, `down`, or `on/off` could change the state of the light.  Or maybe stick a rotary encoder or a custom keypad somewhere for better control.)

### Enable or disable WiFi

Hold `on/off` and `down` together for 5 seconds to toggle WiFi on or off.  By default, WiFi is enabled.

When WiFi is enabled, Minuet confirms with two quick tones followed by a long high tone.

When WiFi is disabled, Minuet confirms with two quick tones followed by a long low tone.

### Power on restore

Hold `on/off` and `up` together for 5 seconds to toggle power on restore behavior.  By default, power on restore is disabled.

When power on restore is enabled, Minuet will restore the fan operating state, speed, direction, and cover open/close state when it is connected to power.  It confirms this setting with a quick turn followed by a long high tone.

When power on restore is disabled, Minuet will leave the fan off and close the cover when it is connected to power.  It confirms this setting with a quick turn followed by a long low tone.

### Factory reset

Hold `on/off` for 15 seconds to turn the fan off and perform a factory reset.  Minuet confirms with four descending tones then erases all of its settings including saved WiFi credentials.  Follow the [Getting started](#getting-started) guide to get started again.

## Using the 4 key wall remote

The 4 key wall remote has some limitations compares to the built-in keypad and 6 key wall remote.

Because it is designed for a 4 speed fan whereas Minuet supports 10 speeds, the rmeote cycles through 10%, 30%, 70%, and 100%.

When you press any button on the remote while the automatic thermostat is enabled, the remote disables (when using [standard controls](#standard-controls)) or overrides (when using [enhanced controls](#enhanced-controls)) the thermostat before performing the requested action.

### Buttons

- Press `fan on`: turn fan on at its last configured manual fan speed if it was off, otherwise cycle through 4 increasing speeds then back to the lowest speed
- Hold `fan on` for 1 second: turn fan on at maximum speed *(bonus)*
- Press `fan off`: turn fan off
- Press `open`: open cover
- Press `close`: close cover

## Using the infrared remote

Please refer to the instructions originally provided with the remote.

Minuet sets the fan state to match everything that you see on the screen in the remote.  The remote has its own memory of the fan's settings and it may not be completely in sync with the fan.  Sometimes when you press a button to do one thing (such as to change the fan speed) you may observe other settings change too (such as the fan cover closing) because that's what the remote thinks the state should be.

Consequently, there is no difference in the remote's behavior regardless of your choice of [standard](#standard-controls) and [enhanced](#enhanced-controls) controls.

What you see is what you get.

## Using the web app and API

(TODO)
