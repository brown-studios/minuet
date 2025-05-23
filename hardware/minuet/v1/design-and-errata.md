# Minuet hardware v1.0 (OBSOLETE)

**Status: OBSOLETE - SUPERSEDED BY V2 TO REMEDY [ERRATA](#errata)**

Version 1.x is the initial prototype of the Minuet fan controller.  It supports basic operation of the fan and cover with the keypad and over WiFi.

[View the schematics in PDF format](minuet.pdf)

## Design

The microcontroller is an [ESP32-C3](https://www.espressif.com/sites/default/files/documentation/esp32-c3-wroom-02_datasheet_en.pdf) with 4 MB of flash, a single core, and an integrated 2.4 GHz antenna.  It is ample for running ESPHome.

The cover motor driver is a [DRV8876](https://www.ti.com/lit/ds/symlink/drv8876.pdf).  It has built-in current limiting which is used to detect end-of-travel when the cover is completely opened or closed.

The fan motor driver is a [DRV10970](https://www.ti.com/lit/ds/symlink/drv10970.pdf).  It supports sensored brushless DC motors with either sinusoidal or trapezoidal commutation modes and built-in current limiting.  The board has jumpers to configure the driver's behavior.  By default, it has been set to sinusoidal mode to reduce noise (in theory).

There is a [TCA9554](https://www.ti.com/lit/ds/symlink/tca9554.pdf) on-board to provide additional GPIOs via I2C.  It has built-in pull-up resistors that are always active on input pins.  On reset, all pins are intialized to input mode so any GPIOs used for output must tolerate the presence of a weak pull-up resistor until the chip is initialized by the microcontroller.  It is mainly used by the keypad matrix.

To thermistor is powered from a GPIO pin to minimize self-heating while not performing a reading.  To save on GPIO pins, the thermistor is powered by one of the keypad matrix row strobe lines since it can be turned off most of the time.

## Errata

### Incorrect silkscreen for the GPIO expansion port

The labels for 3.3 V and GND are swapped on the silkscreen.  Be careful!

### Fan motor driver configuration, current limit, and minimum duty cycle

The DRV10970 sinusoidal control mode doesn't work correctly with motors that have a 30° hall sensor placement.  The motor driver gets confused by the phase of the hall sensor pulses when reversing the motor direction because it only pays attention to the U_HALL sensor and it expects that sensor to be clocked 30° ahead of the motor winding back EMF.  Upon reversing, the W_HALL sensor is now the one that's clocked 30° ahead, not the U_HALL sensor.  So the motor judders badly.

Originally, it seemed like a 1.5 A current limit was sufficient for the fan motor but in practice it is unable to match the power of the original Maxxfan motor.  It's fine for ventilation but not as effective for exhausting cooking fumes.

It turns out the RETRY timer is important for reversing motor directions too, not just stalls.  The driver waits for the motor to come to a stop or until tRETRY elapses before switching directions.  Having disabled the RETRY timer, this doesn't happen and the driver eventually reports a stall.  The microcontroller can handle these stalls with its own heuristics but it adds unnecessary complexity.

- Set CMTMOD to floating for trapezoidal control with 30° hall sensor placement
- Replace R303 with 20 Kohm for the maximum 1.5 A current limit
- Replace R304 with a suitable capacitor to configure the RETRY timer correctly

The DRV10970 has a minimum 10% duty cycle which prohibits operation of the fan at extremely low speeds.  It's probably fine as-is although it limits the dynamic range of the fan.

Overall, it would be better to replace the DRV10970 with a different motor driver that can handle more current and that doesn't have a minimum duty cycle, such as the [MCT8315ZH](https://www.ti.com/lit/ds/symlink/mct8315z.pdf).

### Fan motor PWM driver pin should be pulled down

The DRV10970 internally pulls the PWM pin high and interprets this state as a request to drive the motor full-on.  At power-on reset, the microcontroller initializes this pin to Hi-Z and the motor jolts for a moment while it boots.

### Missing pull-up resistors on the hall sensors

There should be a 10 Kohm pull-up resistor on each hall sensor logic input.

### Rename lid motor to cover motor

The lid open/close control is represented as a cover entity in ESPHome so, for ease of explanation, the circuit board might as well use the same nomenclature.

### Cover motor current limit too low

The IPROPI current limit is too low and the cover motor stalls too easily under load.  On the schematic, R402 is set to 6.8 K which yields a 0.5 A current limit.

Replace R402 with a 3 K resistor to set a 1.1 A current limit which seems to work reliably.  Note that 3.3 K is too high and the motor stalls prematurely so 3 K seems to be in the right ballpark for accurately detecting end-of-travel.  Perhaps 2.7 K would work well too and ensure a little more headroom in case some cover motors are more ornery.

### Cover motor driver EN pin can be hardwired

The brake function isn't needed so the EN pin could be held active to free up a GPIO pin for something else.

### Fan and cover motor drivers could share a single fault pin

The fan and cover motor don't need to be operated simultaneously and the microcontroller could ensure that they are properly sequenced.  Then since both drivers have open-drain outputs to report faults, they could be combined to free up a GPIO pin for something else.

### Missing audible or visual feedback

Although beeps are annoying during normal operation, not having a beeper at all makes the control panel harder to use.  Minuet could let users configure the audible feedback to their taste.  Alternatively, perhaps it could illuminate an LED behind the IR dome for visual feedback.

### Missing battery voltage sensing

Minuet should be able to stop the fan automatically on low battery.
