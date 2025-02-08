# Minuet hardware v2 (UNDER DEVELOPMENT)

**Status: UNDER DEVELOPMENT**

The v2 revision is the second prototype of the Minuet fan controller.

[View the schematics in PDF format](minuet.pdf)

## Changes from v1

- More powerful BLDC motor controller to drive fan motors at up to 4 A (previously 1.5 A)
- Supports wired wall controls, IR remote controls, and the rain sensor if present
- Includes a buzzer for audible feedback that can be disabled in software or physically by cutting a jumper
- Senses the supply voltage to disable the fan when the battery voltage is low
- Can either use trim pots or fixed resistors to adjust motor current limits
- Better schematic readability
- Expanded the expansion port

## Design synopsis

The microcontroller is an [ESP32-C3](https://www.espressif.com/sites/default/files/documentation/esp32-c3-wroom-02_datasheet_en.pdf) with 4 MB of flash, a single core, and an integrated 2.4 GHz antenna.  It is ample for running ESPHome.

The cover motor driver is a [DRV8876](https://www.ti.com/lit/ds/symlink/drv8876.pdf).  It has built-in current limiting which is used to detect end-of-travel when the cover is completely opened or closed.

The fan motor driver is a [MCT8315Z](https://www.ti.com/lit/ds/symlink/mct8315z.pdf).  It supports sensored brushless DC motors with trapezoidal commutation modes and built-in current limiting.  The board has jumpers to configure the driver's behavior.

There is a [TCA9555](https://www.ti.com/lit/ds/symlink/tca9555.pdf) IO expander on-board to provide 16 additional IO pins with built-in pull-up resistors via I2C.

The expansion port enables custom peripherals and factory programming.  It exposes two free GPIO pins that can be used for any purpose, the serial port, the I2C bus, the reset and bootloader signals, and the 3.3 V and 12 V power rails.  For example, with just a few components you could use the expansion port to attach an addressable LED strip for fancy lighting around the fan enclosure.

The QWIIC port allows readily available I2C peripherals (such as environmental sensors) to be connected with ease.

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

The ESP32-C3 microcontroller has relatively few GPIOs so they are assigned to peripherals that need specific functions.

- `GPIO0` & `GPIO1`: Reserved for the expansion port (ADC, LEDC PWM, 32 kHz XTAL, and more functions)
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

Given the scarcity, I was tempted to reuse `GPIO9` for other purposes after booting up but I decided against it because glitches could result in the board mistakenly entering the bootloader after reset and rendering the device inoperable.  Perhaps `GPIO9` could be reused as a button input in a custom expansion.

The TCA9555 IO expander handles the remaining low speed digital logic functions.  These pins are designated `XIO` on the schematic.  All of the `XIO` pins have been assigned.  If needed in a subsequent revision, a few pins could be released by doubling-up functions (such as by combining the motor driver `NFAULT` signals or by reusing one of the keypad row pins to drive the thermistor).

### Rain sensor

The rain sensor detects a small current flowing between bare electrodes immersed in water.  The circuit has high impedance to protect itself from the environment especially because it is DC coupled to the sensing electrodes (just like the original equipment).  It might be interesting to explore AC coupling the rain sensor for immunity in a subsequent revision.

Due to IO scarcity, there are no available ADC pins to measure the voltage.  I considered assigning `GPIO1` for this purpose but it's more valuable to reserve for the expansion port.  Instead, I used a relatively inexpensive comparator to detect when the sensor's voltage crosses a fixed threshold.  You can omit this component if you don't need the rain sensor.

### Temperature sensor

The temperature sensor is driven by an IO pin to minimize resistive self-heating and power usage between samples.

### Piezo buzzer

The piezo buzzer is designed with politeness in mind which may be a matter of personal preference.

You can customize or disable the sounds it makes in software.  Refer to the [user guide](../../docs/user-guide.md) for details.

You can disable the buzzer altogether in hardware by cutting a jumper on the board.  Or you can make the buzzer louder by cutting and soldering the jumper to the 12 V position instead of the default 3.3 V position.  Refer to the [setup guide](../../docs/setup-guide.md) for details.

And if you want to make the fan play a cheerful jingle any time it turns on then you can change the firmware to do that with [RTTTL](https://en.wikipedia.org/wiki/Ring_Tone_Text_Transfer_Language).

## Errata

Nothing yet...

## References

[Remote control IR protocol](https://github.com/skypeachblue/maxxfan-reversing)
