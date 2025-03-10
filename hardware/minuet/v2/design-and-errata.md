# Minuet hardware v2.2 (UNDER DEVELOPMENT)

**Status: UNDER DEVELOPMENT**

Version 2.x is the first feature complete realization of the Minuet fan controller.  Its goal is to do everything the original equipment could do and a little more.

[View the schematics in PDF format](minuet.pdf)

## Changes from v1

- More powerful BLDC motor controller to drive fan motors at up to 4 A (previously 1.5 A)
- Supports wired wall controls, IR remote controls, and the rain sensor if present
- Includes a buzzer for audible feedback that can be disabled in software or physically by cutting a jumper
- Senses the supply voltage to disable the fan when the battery voltage is low
- Can either use trim pots or fixed resistors to adjust motor current limits
- Better schematic readability
- Expanded the expansion port and developed a light accessory that plugs into it
- Optimized some of the part selection for production

## Design synopsis

The microcontroller is an [ESP32-C3](https://www.espressif.com/sites/default/files/documentation/esp32-c3-wroom-02_datasheet_en.pdf) with 4 MB of flash, a single core, and an integrated 2.4 GHz antenna.  It is ample for running ESPHome.

The cover motor driver is a [DRV8876](https://www.ti.com/lit/ds/symlink/drv8876.pdf).  It has built-in current limiting which is used to detect end-of-travel when the cover is completely opened or closed.

The fan motor driver is a [MCT8316Z](https://www.ti.com/lit/ds/symlink/mct8316z.pdf).  It supports sensored brushless DC motors with trapezoidal commutation and built-in current limiting.  The board has jumpers to configure the driver's behavior.

There is a [TCA9555](https://www.ti.com/lit/ds/symlink/tca9555.pdf) IO expander on-board to provide 16 additional IO pins with built-in pull-up resistors via I2C.

The GPIO expansion port enables accessories and factory programming.  It exposes two free GPIO pins that can be used for any purpose, the serial port, the I2C bus, the reset and bootloader signals, and the 3.3 V and 12 V power rails.  For example, with just a few components you could use the GPIO expansion port to attach an addressable LED strip for fancy lighting around the fan enclosure.

The QWIIC port allows readily available I2C accessories (such as environmental sensors) to be connected with ease.

## PCB assembly

The KiCad project contains the bill of materials.

Most of the components on the circuit board can be soldered by hand with the exception of a few ICs with QFN packages whose pads are unaccessible from the sides.  I'd recommend ordering a solder stencil and assembling the board with solder paste and a temperature controlled hot plate or a reflow oven.

All of the SMT components are on the front side of the board.  You may find it easier to solder these components first before moving on to the through hole components.

There are through hole components on both sides of the board.  Follow the silkscreen courtyard markings to determine the correct orientation.  Beware that labels for connectors appear on both sides of the board.

The 1x8 pin header labeled PANEL must have a sufficient mating contact length to securely attach the keypad's flex connector.  The BOM specifies a part with an 8.1 mm mating contact length that works well.  Shorter contacts may be fine but the connector could come loose under vibration so be sure to check the fit.

The IR receiver must be raised above the board as far as the leads can be extended (about 16 mm) to be visible through the clear window in the keypad.  Thus the IR receiver will need mechanical support to keep it propped up and to insulate the leads.  You can 3D print a suitable standoff from [this model](https://cad.onshape.com/documents/11f07c0bb608e7010778ac35/w/a82f75dceda39e564795dbd4/e/5949b73994c9747af7d1d4c9) or make your own using other materials such as cardboard.

There are test points on the board near the current limit trim potentiometers to help you measure the resistance as you make adjustments.

The board is designed with slightly enlarged "hand solder" footprints for resistors and zero-ohm jumpers that are meant to be manipulated during board set-up.

You can safely upgrade passive components to equivalent values with higher voltage or current ratings or more precise tolerances as long as the package size remains the same.

You can safely omit certain components that you don't need including the IR receiver, the 6P6C and 8P8C connectors for wired wall controls, the rain sensor circuitry, the buzzer, and the current limit trim potentiometers (if you add fixed resistors instead).

To improve the circuit board's moisture resistance, you can spray it with an insulative conformal coating after taking care to mask off all connectors before spraying so they don't get coated unintentionally.

## Notes

### IO scarcity

The ESP32-C3 microcontroller has relatively few GPIOs so they are assigned to components that need specific functions.

- `GPIO0` & `GPIO1`: Reserved for the GPIO expansion port (ADC, LEDC PWM, 32 kHz XTAL, and more functions)
- `GPIO2`:` IR receiver (RMT function), strapping pin
- `GPIO3`: Voltage sensor (ADC function)
- `GPIO4`: Thermistor (ADC function)
- `GPIO5`: Fan motor speed (LEDC PWM function)
- `GPIO6` & `GPIO7`: I2C bus
- `GPIO8`: Fan motor tachometer (PCNT function), strapping pin
- `GPIO9`: BOOT button, strapping pin
- `GPIO10`: Buzzer (LEDC PWM function)
- `GPIO18` & `GPIO19`: USB full-speed transceiver
- `GPIO20` & `GPIO21`: Serial port UART

Given the scarcity, I was tempted to reuse `GPIO9` for other purposes after booting up but I decided against it because glitches could result in the board mistakenly entering the bootloader after reset and rendering the device inoperable.  Perhaps `GPIO9` could be reused as a button input in an accessory.

The TCA9555 IO expander handles the remaining low speed digital logic functions.  These pins are designated `XIO` on the schematic.  All of the `XIO` pins have been assigned.  If needed in a subsequent revision, a few pins could be released by doubling-up functions (such as by combining the motor driver `NFAULT` signals or by reusing one of the keypad row pins to drive the thermistor).

### Rain sensor

The rain sensor detects a small current flowing between bare electrodes immersed in water.  The circuit has high impedance to protect itself from the environment especially because it is DC coupled to the sensing electrodes (just like the original equipment).  It might be interesting to explore AC coupling the rain sensor for immunity in a subsequent revision.

Due to IO scarcity, there are no available ADC pins to measure the voltage.  I considered assigning `GPIO1` for this purpose but it's more valuable to reserve for the GPIO expansion port.  Instead, I used a relatively inexpensive comparator to detect when the sensor's voltage crosses a fixed threshold.  You can omit this component if you don't need the rain sensor.

### Temperature sensor

The temperature sensor is driven by an IO pin to minimize resistive self-heating and power usage between samples.

### Piezo buzzer

The piezo buzzer is designed with politeness in mind which may be a matter of personal preference.

You can customize or disable the sounds it makes in software.  Refer to the [user guide](../../docs/user-guide.md) for details.

You can disable the buzzer altogether in hardware by cutting a jumper on the board.  Or you can make the buzzer louder by cutting and soldering the jumper to the 12 V position instead of the default 3.3 V position.  Refer to the [setup guide](../../docs/setup-guide.md) for details.

And if you want to make the fan play a cheerful jingle any time it turns on then you can change the firmware to do that with [RTTTL](https://en.wikipedia.org/wiki/Ring_Tone_Text_Transfer_Language).

## Fan motor configuration

### Current limit (`ILIM`)

The fan motor current limit protects Minuet and the motor from overcurrent which could generate excess heat and damage them.  Set this value with care after consulting the motor's datasheet.

The `ILIM` pads set the current limit either using a fixed resistor or a 5 Kohm variable resistor.  To set this value, measure the resistance across the variable resistor at the test point near `ILIM` and turn the potentiometer until you obtain the desired setpoint.

| Motor                       | Recommended limit | `ILIM` setpoint |
| --------------------------- | ----------------- | --------------- |
| StepperOnline 42BLR53-12-01 |               2 A |       1.82 Kohm |
| StepperOnline 57BYA54-12-01 |               4 A |       3.83 Kohm |

Determining an appropriate current limit can be a little tricky because it is bounded by several factors.

- The motor's datasheet specifies a current limit per motor phase and an overall power limit, neither of which must be exceeded.
- The MCT8316Z motor driver supports a maximum of 8 A peak current to the motor windings across all phases with built-in current limiting and overtemperature protection.  Internally the chip applies the current limit threshold to the sum of the current across all phases but at the workbench it's easier to measure the current of one motor phase at a time.  Tests show the current limit engages when the average current on one motor phase exceeds about 50-75% of the configured value.  Moreover, the chip appears to dissipate heat effectively through the PCB ground plane across the entire operating range.
- The traces on the Minuet circuit board are sized to handle 4 A average current from the battery and to each motor phase without heating more than 10 °C.  There is a wide safety margin because the average current through the traces is much less than their peak current.
- The wiring feeding Minuet is rated for 5 A, protected externally by a fuse, and protected internally by a 4 A polyfuse. The current drawn from the power supply is anywhere from 20-70% of what's circulating through one motor phase on average (more efficient at lower speeds) so even when a motor phase is drawing 3 A, the supply sees less than 2 A.  Circuit overload is unlikely.
- Motor current scales quadratically with fan speed and the plastic fan blade can only handle so much.  At very high speeds the fan wobbles and makes unpleasant sounds so there's no point setting the motor current limit higher than the fan can handle.

Formulas to calculate the current limit where `RV` is the value of the `ILIM` resistor in Kohms and `RF` = 14.0 Kohm:

- Ilim = 66 A * (0.5 - RF / (2 * RF + RV))
- RV = RF * (1 / (0.5 - Ilim / 66 A) - 2)

Approximate setpoints rounded to nearest E96 series value:

|  Ilim |      RV | Notes                    |
| ----- | ------- | ------------------------ |
|   0 A |     0 K | Current limit disabled   |
|   1 A | 0.887 K |                          |
| 1.5 A |  1.33 K |                          |
|   2 A |  1.82 K |                          |
| 2.5 A |  2.32 K |                          |
|   3 A |  2.80 K |                          |
| 3.5 A |  3.32 K |                          |
|   4 A |  3.83 K | Default for large motors |
| 4.5 A |  4.42 K |                          |
|   5 A |  4.99 K | Maximum supported        |

You can tune the `ILIM` setpoint while the fan is running.  Run the motor at full duty cycle and turn the potentiometer to observe the effect.  When you're satisfied, unplug Minuet, measure the `RV` that you obtained, then work backwards to the current limit.

### Advance lead angle (`ADV`)

The lead angle compensates for the phase delay in motor winding current and voltage due to its inductance.

The correct setting is the one that minimizes the current drawn on each motor phase divided by the motor RPM to ensure efficient operation of the motor driver.  A poor choice can result in the motor driver overheating.

Testing at the bench with the motor unloaded (no fan blade) showed that 0° was more efficient whereas increasing angles were progressively less efficient, and 30° drew 3 times as much current at the same RPM.

Results may be different when the motor is under load (with a fan blade).  More testing is warranted.

The `ADV` pads set the MCT8316Z advance angle level.  The `-` and `+` silkscreen designate the pads carrying `AGND` and `AVDD`.

| Angle | Setting                                    |
| ----- | ------------------------------------------ |
|    0° | `ADV` tied to `AGND` **(default)**         |
|    4° | `ADV` tied to `AGND` via 22 Kohm resistor  |
|   11° | `ADV` tied to `AGND` via 100 Kohm resistor |
|   15° | no connection (Hi-Z)                       |
|   20° | `ADV` tied to `AVDD` via 100 Kohm resistor |
|   25° | `ADV` tied to `AVDD` via 22 Kohm resistor  |
|   30° | `ADV` tied to `AVDD`                       |

References:

- [MCT8316Z datasheet](https://www.ti.com/lit/ds/symlink/mct8316z.pdf)
- [Texas Instruments lead angle adjustment video](https://www.ti.com/video/6257299020001)
- [Texas Instruments application report about tuning lead angle](https://www.ti.com/lit/an/slaa561/slaa561.pdf)

### Slew rate (`SLEW`)

The slew rate determines how quickly the motor driver switches states.  A low slew rate results in greater switching losses which wastes energy and produces heat.  A high slew rate improves thermal performance at the cost of increased EMI.

Testing so far hasn't shown EMI to be a problem so using the maximum slew rate is recommended by default.

The `SLEW` pads set the MCT8316Z slew rate.  The `-` and `+` silkscreen designate the pads carrying `AGND` and `AVDD`.

| Slew rate | Setting                                     |
| --------- | ------------------------------------------- |
|   25 V/uS | `SLEW` tied to `AGND`                       |
|   50 V/uS | no connection (Hi-Z)                        |
|  100 V/uS | `SLEW` tied to `AVDD` via 47 Kohm resistor  |
|  200 V/uS | `SLEW` connected to `AVDD` **(default)**    |

References:

- [MCT8316Z datasheet](https://www.ti.com/lit/ds/symlink/mct8316z.pdf)

### Commutation mode (`MODE`)

The commutation mode configures the switching behavior of the motor driver.  Testing so far hasn't shown any reason to change the default.

The `MODE` pads set the MCT8316Z commutation mode.  The `-` and `+` silkscreen designate the pads carrying `AGND` and `AVDD`.

| Mode | Setting                                     | Hall sensor |   Modulation | ASR & AAR |
| ---- | ------------------------------------------- | ----------- | ------------ | --------- |
|    2 | `MODE` tied to `AGND` via 22 Kohm resistor  |     digital | asynchronous |  disabled |
|    4 | no connection (Hi-Z)                        |     digital |  synchronous |  disabled |
|    7 | `MODE` tied to `AVDD` **(default)**         |     digital |  synchronous |   enabled |

References:

- [MCT8316Z datasheet](https://www.ti.com/lit/ds/symlink/mct8316z.pdf)

## Cover motor configuration

### Current limit (`IPROPI`)

The cover motor current limit lets Minuet detect when the motor has reached the end of its travel when opening or closing the cover.  It must be set high enough to allow the motor to overcome the torque demands of the cover mechanism and low enough to reliably detect stall at end of travel.

If your cover does not open or close fully, try increasing the cover motor current limit a little bit.

The `IPROPI` pads set the current limit either using a fixed resistor or a 5 Kohm variable resistor.  To set this value, measure the resistance across the variable resistor at the test point near `IPROPI` and turn the potentiometer until you obtain the desired setpoint.

Formulas to calculate the current limit where `RV` is the value of the `IPROPI` resistor in ohms.

- Itrip = 1000 * 3.3 V / RV
- RV = 1000 * 3.3 V / Itrip

**Recommended default: RV = 2.80 Kohms, Itrip = 1.18 A**

## Accessories

Refer to the schematics for the pinout of the `EXPANSION` and `QWIIC` ports.

## Errata

Corrected from v2.0 to v2.1:

- The `BOOT` and `RESET` buttons were hard to press.  Moved them closer to the board edge.
- The 6P6C jack for the 4 key remote was wired backwards.  Noted in the schematic that the rows are also used to detect key presses when undriven (tristate).
- The TCA9555 SCL and SDA pins were wired backwards.  The symbol for the very similar TCA9554 used in v1 lists the pins in the opposite order.  Caveat lector!
- Set the default lead angle to 0° after performing measurements to confirm that this setting is much more power efficient.
- The [MCT8315Z](https://www.ti.com/lit/ds/symlink/mct8315z.pdf) 4 A motor driver previously used in v2.0 got quite hot in operation so decided to replace it with the [MCT8316Z](https://www.ti.com/lit/ds/symlink/mct8316z.pdf) 8 A motor driver that has a lower RDSon and a larger surface area for heat dissipation.
- Swapped the X7R MLCC capacitors for X5R because they are smaller, cheaper, and Minuet won't be operated over 85 °C anyhow, adjusted capacitor voltage ratings to be more in line with what's needed.
- Increased the fan driver 10 uF capacitor to 22 uF to reduce voltage ripple near the motor driver.
- Replaced the aluminum electrolytic bulk capacitor with an aluminum polymer capacitor to improve resilience and reduce ESR.
- Widened the 4 A traces from 1.8 mm to 2.2 mm to reduce impedance because there was room to do so although these traces won't be pulling anywhere near that current continuously.
- Used via stitching to join large traces instead of one big via as new calculations with more accurate PCB plating thickness information showed a higher impedance than anticipated.
- Started optimizing the design for production by adding LCSC part numbers and substituting some components for more readily available parts.
- Replaced the [TPSM861253](https://www.ti.com/lit/ds/symlink/tpsm861253.pdf) buck converter with [TPS561201](https://www.ti.com/lit/ds/symlink/tps561201.pdf) which is cheaper, much more efficient at low load, and more readily available although it requires more auxiliary components than the previous module, [TPS561243](https://www.ti.com/lit/ds/symlink/tps561243.pdf) is newer and would be smaller and more efficient because it operates at higher frequencies but it isn't available on LCSC at this time.

Corrected from v2.1 to v2.2:

- The default 3 A current limit wasn't high enough for the 50 W motor to perform to its fullest.  Raised the default to 4 A and the maximum to 5 A.  Changed the fan current limit fixed resistor from 18.2 K to 14.0 K to provide that headroom and take into account the potentiometer tolerance.  My 5 K pots measured from 4.76 K to 4.93 K which was within the expected 10% tolerance.

Nothing yet...
