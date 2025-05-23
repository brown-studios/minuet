# Minuet lighting and load accessory (ABANDONED)

**Status: ABANDONED - SUPERSEDED BY THE SIMPLER 'LIGHT' ACCESSORY TO REMEDY [ERRATA](#errata)**

The Minuet lighting and load accessory adds the capability to drive up to two independent loads attached to the fan.  The accessory can be configure to drive each independent load at 12 V, 5 V, or 3.3 V.

Suggested applications:

- Drive up to two independent loads such as LED lights with ON/OFF or PWM control.
- Drive one addressable LED strip (WS2811, WS2812B, WS2814, SK6812, or similar), attach it to the inside of the fan cowling to make it light up pretty colors.
- Drive one warm white LED strip with PWM control for dimming as one load and a drive motorized disco ball with ON/OFF control as the second load, just for fun!
- Use it as a breakout board with access to all of the GPIO expansion port signals and power for making your own accessories.

Depending on your application, you may need to modify the Minuet ESPHome firmware YAML configuration to control the loads in the manner you desire.

The board gets its power from the Minuet fan controller board.  Please consider these specifications to appropriately size your loads to the available supply.

- 12 V supply is unregulated, 1 A current available
- 5 V supply is regulated, 150 mA current available
- 3.3 V supply is regulated, 600 mA current available

[View the schematics in PDF format](load.pdf)

## Design synopsis

The board consists of a pair of high side P-Channel MOSFET drivers.  This configuration lets both drivers be used in tandem at different voltages while maintaining a common ground reference (unlike a low side driver) which is necessary for driving addressable LED lights.

The on-board 5 V voltage regulator has an extremely small quiescent current: 1.12 uA when shutdown, 71 uA with no load, 750 uA at full load.  Perfect for not draining the battery.

The board is laid out to be amenable to hand soldering.  The components are fairly small to fit within the allotted space but the pads are large and fully exposed.

## Configuring the loads

The board can drive up to two independent loads, designated `LOAD0` and `LOAD1`.  When `GPIO0` is high, then `LOAD0` will be activated.  Similarly, when `GPIO1` is high, then `LOAD1` will be activated.  Both loads are fully independent and can be driven at different voltages.

Here's how to set the solder jumpers to configure the board for your application.

- `5V EN`: Solder this jumper closed to enable the 5 V regulator.  Only needed when you will drive loads at 5 V.
- `LOAD0` / `LOAD1`: Each load has a set of 3 jumpers to set the voltage at which to drive the load.  Solder closed at most one of these jumpers.
  - `3V3`: Solder this jumper closed to drive the load at 3.3 V.
  - `5V`: Solder this jumper closed to drive the load at 5 V.
  - `12V`: Solder this jumper closed at 12 V.
  - None: If none of the jumpers are closed then the load will not be driven.

To drive an addressable LED strip, close `5V EN`, set `LOAD0` to `12V` or `5V` to power the strip according to its voltage requirement, and set `LOAD1` to `5V` for the data signal (data is always 5 V even for 12 V strips).

The output for the loads appears at the [JST XH](https://www.jst.com/wp-content/uploads/2021/01/eXH-new.pdf) ports labeled `LOAD0`, `LOAD1`, and `DUAL`.

- `LOAD0` / `LOAD1` pinout
  - pin 1 is ground
  - pin 2 is power (at the voltage that you configured for the load)
- `DUAL` pinout
  - pin 1 is ground
  - pin 2 is `LOAD1` power (addressable LED strip data signal as described above)
  - pin 3 is `LOAD0` power (addressable LED strip power as described above)

## The 12 V supply may not actually be 12 V

Be aware that the 12 V supply is unregulated and will reflect the voltage of whatever the fan is connected to, such as a battery whose voltage may vary widely by a few volts as it charges and discharges.  Bear that in mind when you configure your loads for `12V` operation if they are sensitive to voltage swings.

Typically, LED lights won't mind being driven a few volts more or less than 12 V but they will dissipate more heat at higher voltages and could potentially be damaged if operated as full brightness that way for a long time.

If you need voltage regulation for your load, consider connecting a 12 V DC buck-boost converter either upstream of the fan or downstream of the load terminal.

## How many addressable LED pixels can I use?

It depends on the LED strip that you use.  Here's some general guidance.  If you're not already familiar with addressable LEDs, I suggest looking for a more thorough tutorial.

As a rough estimate, a typical RGB LED pixel draws 0.3 W when red, green, and blue are at full brightness and a typical RGBW LED pixel draws an extra 0.1 W when the white channel is also lit at full brightness.  It adds up quickly when you multiply by the number of pixels!

In practice, you can drive a lot more LEDs if you don't run them at full brightness.  If you run them at 50% intensity uses about 1/4 the power, they're still plenty bright, and they will last longer because they produce less waste heat.

Addressable LED strips are often sold in 12 V and 5 V variants (and others).

- Using 12 V strips: With 12 W of power available at 12 V, you should be able to light about 40 RGB pixels at full brightness and a few times more when operated at a reduced brightness.  Plenty for lighting up the fan cowling or part of the ceiling.

- Using 5 V strips: The on-board 5 V regulator is rated to supply about 750 mW which is enough for maybe 3 pixels at full brightness and perhaps a dozen at 50% brightness.  Because the linear regulator dissipates excess energy as heat, it's not very efficient.  Alternatively, you can configure `LOAD0` for 12 V and connect it to a 12 V to 5 V DC buck converter to drive up to 12 W of pixels at 5 V.

Recommendation: Use RGBW addressable LED strips with a warm white or cold white channel to improve [color rendering](https://en.wikipedia.org/wiki/Color_rendering_index) when used for white light general illumination.  Mixing RGB to produce white without a dedicated white channel makes everything look weird.

## Errata

Corrected from v2.0 to v2.1:

- Changed the `5V EN` jumper to disconnect the LDO's power supply so that the disable input is not left floating.
- Corrected the orientation of the P-Channel MOSFETs on the schematics.
- Reduced the MOSFET pull-up resistor to 10 Kohm from 100 Kohm to increase drive current.

Remaining errors in v2.1:

- The `DUAL` output cannot be used to drive addressable LED strips because there is nothing driving the data line low fast enough for 800 KHz signalling.
- The NPN transistor base should not be left floating in case the GPIO is tristate.
- THe MOSFET gate needs a resistor to limit the switching current.

Decided to abandon this design because it is overly complex and doesn't work with addressable LEDs as intended.  It would be better to design simpler boards for each use-case instead of having lots of jumpers.
