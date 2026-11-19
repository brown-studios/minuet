# Minuet assembly guide

This guide explains how to assemble Minuet hardware.

## Fan controller

The Minuet fan controller board drives the show.

It is a complete drop-in replacement for the original Maxxfan circuit board, reuses the original fasteners in the same screw positions, and it supports all of the built-in Maxxfan hardware (except the fan motor because that's been replaced by a brushless motor).  Of course, it can do a whole lot more!

Install the Minuet factory firmware after assembling the board.

## Fan motor

Minuet uses a brushless DC motor to drive the fan instead of the original brushed DC motor.

We recommend choosing a known compatible motor because the process for tuning motors is challenging.

### Compatible motors

#### Minuet kit motor

**This is the only motor currently supported out-of-the-box by Minuet.  Other motors may require tuning.**

The Minuet kit includes a custom motor and adapters to fit the Maxxfan motor housing out-of-the-box.

The custom motor is based on the 57BYA54 but it has been upgraded for reliable quiet operation in a fan.  It has a longer shaft, stepped D profile, larger bearings, and a custom wire harness.

#### StepperOnline 57BYA54-12-01 ([supplier](https://www.omc-stepperonline.com/12v-3000rpm-0-16nm-50w-5-90a-57x57x53-5mm-brushless-dc-motor-57bya54-12-01))

If you can't obtain the Minuet kit motor then you can also use this one but it will require adapters.

- Runs quietly and continuously from about 100 RPM to over 1200 RPM.
- Readily available, compact, and inexpensive.
- Needs a shaft adapter to extend the shaft to reach the fan blade.
- Needs a mount adapter to compensate for the screw hole locations.
- The hall sensors are not needed and are not used by Minuet.

##### Specifications

- Rated voltage: 12 V
- Rated power: 50 W
- Rated current: 5.9 A
- Motor poles: 4
- Sensor type: 3 digital hall sensors with 30° placement
- Shaft diameter: 8 mm
- Shaft length: 21 mm
- Fastener: 4x M4 screws
- Dimensions: 57 mm diameter x 53.5 mm length

##### Wiring chart

- Phase A: fat yellow wire
- Phase B: fat green wire
- Phase C: fat blue wire
- The remaining wires are for the unused hall sensor and can be secured out of the way or cut off entirely

### Bringing up other motors

#### Motor selection guide

Choose a motor that runs quietly at low speed with minimum vibration.  It doesn't need a lot of torque.  For safety, it must be able to operate continously under load without overheating.  Look for motors that are designed for use in appliances (not for skateboards or model airplanes).

The motor must be brushless.  The 3 phases can be wired in either the wye or delta configuration (it doesn't matter which).

The motor should have a datasheet with published specifications so you know what you're getting.

The motor should have a suitable power rating, perhaps somewhere around 50 W, certainly not hundreds of watts.  Bigger is not better.  Big motors have big magnets and they experience significant [cogging torque](https://en.wikipedia.org/wiki/Cogging_torque) when operated at low speeds which results in excessive noise and vibration for a vent fan.

The motor should be designed for operation at a nominal 12 V.  The actual operating voltage will depend on the supply voltage.

The motor should have a minimum current rating of 5 A per phase.  You can use a smaller motor with a lower current rating but it may not be powerful enough to operate the fan at higher speeds.

The motor should not have hall sensors because the latest versions of Minuet do not use them.

You are unlikely to find a suitable off-the-shelf motor that is a perfect drop-in replacement for the original motor's dimensions.  That's just physics.  Brushless DC motors are generally more efficient than brushed DC motors of equivalent power so they tend to be smaller.  So you will likely need to make adapters to compensate for the different motor body size, mounting hole pattern, shaft diameter, shaft length, and shaft keying.

#### Motor tuning

Before you can operate a new motor with Minuet, you will need to configure many parameters for the [MCF8316D field-oriented control motor driver chip](https://www.ti.com/lit/ds/symlink/mcf8316d.pdf) in the firmware.  This step is required and there are no default settings that will work for all motors.

Those parameters include:

- Number of poles
- Winding resistance
- Winding inductance
- Back-EMF constant
- PID speed control loop KI and KP terms
- Current limit
- Open loop and closed loop acceleration
- Initial position detection
- Operating speed table

Some of these parameters can be measured or estimated directly by the motor driver chip using the built-in Motor Parameter Extraction Tool.  Other parameters require experimentation to determine optimal values for reliable operation.  It is helpful to have a [TI MCF8316D-EVM development board](https://www.ti.com/tool/MCF8316DEVM) and the [TI Motor Studio software](https://www.ti.com/tool/MOTORSTUDIO).

If the motor spins the wrong direction (e.g. air in instead of air out), swap any two motor phases.

Explaining the process of motor tuning in detail is beyond the scope of this guide.

### Motor wiring

Here's how to attach a connector to your fan motor if it doesn't already have one that's compatible with Minuet.

Supplies:

- [JST VH series wire-to-board connectors](https://www.jst.com/products/crimp-style-connectors-wire-to-board-type/vh-connector/)
  - 1x JST VH series VHR-3M housing
  - 3x JST VH series SVH-41T-P1.1 contacts plus a few spares just in case
  - If your wires are too short (see instructions)
    - 18 AWG wire, heat shrink tubing, and soldering supplies
  - A crimping tool

Instructions:

1. Locate the wiring chart for your motor and note the color of the A, B, and C phases.
1. Measure your wires.  The wires need to be about 16-20" or 40-50 cm long to comfortably reach from the motor to the circuit board within the fan housing.  If your wires are too short then you can solder on some additional 18 AWG wire.
1. Strip the wires back about 1.5 mm.
1. Crimp the pins onto each wire.
1. Note the numbers or index markings on the side of the connector housings to determine the pin order.
1. Assemble the 3-pin motor connector as follows:
    - pin 1: Phase A
    - pin 2: Phase B
    - pin 3: Phase C
1. Give the wires a gentle tug to ensure they have been fully seated and latched into the housing.

### Motor shaft adapter

The original fan motor has a 40 mm long, 8 mm diameter D-shaped shaft, with a flat face on one side where the fan blade attaches with a 26 mm deep hub.  Your motor's shaft is probably different so you will need a shaft adapter to achieve the necessary length and diameter.

Here are some ways to assemble a suitable shaft adapter.

#### Rigid coupler and dowel pin shaft adapter

This adapter consists of two parts, a rigid coupler to match the shaft diameter and an 8 mm dowel pin to extend its length to fit the fan blade.

Supplies:

- Rigid coupler.  The inner diameter of one end of the coupler must match the diameter of your motor shaft and the other end must be 8 mm to match the dowel pin.
  - [5 mm to 8 mm inner diameter, 22 mm long stainless steel coupler](https://www.amazon.com/gp/product/B07P82D36N/)
  - [8 mm to 8 mm inner diameter, 22 mm long stainless steel coupler](https://www.amazon.com/gp/product/B07P5YZKY5/)
- Dowel pin.  The exposed length of the dowel pin must be at least 26 mm for the fan blade plus enough to insert into the shaft coupler.  A dowel pin with 40 mm overall length works well with the couplers linked above.
  - [8 mm x 40 mm stainless steel dowel pin](https://www.amazon.com/gp/product/B07Z6GC2TR/)

Instructions:

1. Optional: File a shallow flat face into one end of the dowel pin about 15 mm long.  The flat face helps to prevent the fan blade's grub screw from slipping on the shaft although it doesn't seem to make much difference so you can skip this step.
1. Seat the 8 mm dowel pin up to the midpoint of the coupler such that about 26 to 30 mm of the shaft (flattened end) sticks out.  Gently tighten the coupler's grub screws onto the dowel pin.
1. Insert the coupler onto the motor shaft.  Gently tighten the coupler's grub screws onto the dowel pin.

#### 3D printed shaft adapter

Here's a [model for a 3D printed shaft adapter](https://cad.onshape.com/documents/c87749ce3cf87a164617aa11/w/1134a70d634f5c16dbb7ae0d/e/a048a32f956bb78ccd364397).  You can configure the model for whatever motor shaft diameter you need.  Attach the adapter to the motor shaft with a pair of M4 grub screws.

> [!IMPORTANT]
> This method is only suitable for short term experimentation.  The shaft adapter experiences significant torque while running the fan so there's a risk that the fan blade might break off the shaft and hurt someone.  Consider making a shaft adapter from more robust materials.  Please be careful!

## Fan motor mount

You will need a mount to securely attach your new fan motor to the Maxxfan's housing which was originally designed for a motor with different dimensions.

The mount has three essential features:

- Two M5 screws spaced 50 mm apart across the diameter of the motor for mounting the motor to the housing, just like the original motor.
- Screw holes for fastening the new motor to the mount.
- Spacers to backset the new motor from the housing to compensate for the excess length of the shaft adapter so the fan blade fits properly.  Without them, the fan blade will stick out too far to fit behind the insect screen.

The Minuet kit includes a metal plate with press-fit studs.  You can also make a mount of other materials.

### 3D printed mount

Here's a [configurable model](https://cad.onshape.com/documents/11f07c0bb608e7010778ac35/w/a82f75dceda39e564795dbd4/e/9979bb27f5cf3d9f46ddfa29) that you can use as a starting point.  It has integrated spacers and stiffening ribs to backset the motor so the shaft sticks out just the right amount for the fan blade to attach.

Use a strong plastic with good heat and UV resistance such as PETG.

Supplies:

- 2x M5 x 14 mm cap screws (a little longer is ok) and washers
- Screws for your motor and shaft adapter combination
  - For 57BYA54 with a rigid coupler and dowel pin shaft adapter, use 4x M4 x 22 mm socket head cap screws and washers

Instructions:

1. Tap the M5 screw holes into the plate.
1. Screw the M5 screws through the mount from the side on which the motor is installed.  Tighten only until snug to avoid stripping the plastic threads.  Do not use threadlocker.
1. Screw the motor to the plate.  Add a washer on each screw between the screw head and the plate.

## Wire passage cover

The notch in the original wire passage cover is too small to fit over the motor wires.

You can modify the original wire passage cover to fit, make a new cover, or omit the cover (increasing the risk of water intrusion).

### 3D printed cover

Here's a [configurable model](https://cad.onshape.com/documents/c87749ce3cf87a164617aa11/w/1134a70d634f5c16dbb7ae0d/e/c150dd1f03cfafd0dbefc852) that you can use as a starting point.

Use a strong plastic with good heat and UV resistance such as PETG.

## Power cable

The power cable uses a [JST VH series wire-to-board connector](https://www.jst.com/products/crimp-style-connectors-wire-to-board-type/vh-connector/).

- Pin 1 is negative (ground)
- Pin 2 is positive (+12 V DC nominal)

Supplies:

- 1x JST VH series VHR-2M housing
- 2x JST VH series SVH-41T-P1.1 contacts plus a few spares just in case
- 18 AWG wire, preferably in distinct colors to help identify positive (red) and negative (black)
- wire crimping tools

Instructions:

- Cut two pieces of wire long enough to make the connection from the fan housing where the circuit board will be installed to the electrical supply.  About 12" or 30 cm should be plenty.  Alternatively, you can crimp the contacts directly to the electrical supply wire.
- Strip 2 mm off the end of the wire.
- Crimp the JST VH contacts to the wires.
- Insert the contacts into the JST VH housing paying attention to the polarity chart shown above.

## Lid motor cable

This cable adapts the lid motor's [Molex 1625 series wire-to-wire connector](https://www.molex.com/en-us/products/series-chart/1625) to Minuet's [JST XH series wire-to-board connector](https://www.jst.com/products/crimp-style-connectors-wire-to-board-type/xh-connector/).

Supplies:

- 1x Molex 1625 series 03061023 (1625-2R3) receptacle
- 2x Molex 1625 series 02061101 contacts plus a few spares just in case
- 1x JST XH series XHP-2 2-pin housing
- 2x JST XH series SXH-001T-P0.6(N) contacts plus a few spares just in case
- 22 AWG 2 conductor ribbon cable
- wire crimping tools

Instructions:

1. Cut a section of ribbon cable approximately 12" or 30 cm long.
1. Strip 1.5 mm off from each end of each wire.
1. Crimp a Molex 1625 series pin to one of each wire and a JST XH series pin to the other end.
1. Insert the pins into their respective housings such that pin 1 of the Molex 1625 series connector connects to pin 1 of the JST XH series connector.  Likewise, pin 2 connects to pin 2.

## Light accessory

The Minuet light accessory lets you attach a light to your fan.  It plugs into the Minuet `EXPANSION` port.

You can use this accessory as a break-out board for your own circuits and it includes a prototyping area for mounting through-hole components.

### LED strip

This section section describes how to build an addressable LED strip with a connector that works with Minuet out-of-the-box.  You can use a different LED strip instead but you may need to customize the firmware to interface with it correctly.

Supplies:

- 1 meter of [BTF Lighting SK6812 RGBWW, IP65, 60 LEDs/meter, 12 V](https://www.btf-lighting.com/products/dc12v-sk6812-rgbw-led-strip-individual-addressable?variant=46547794854114) or similar
- 1x JST XH series XHP-3 3-pin housing
- 3x JST XH series SXH-001T-P0.6(N) contacts plus a few spares just in case
- 22 AWG 3 conductor ribbon cable
- wire crimping tools
- heat shrink tubing

Instructions:

1. Cut a section of ribbon cable approximately 12" or 30 cm long.
1. Cut a section of 57 pixels from the LED strip.  This is enough to fit around the inner circumference of the fan housing.
1. Solder one end of each wire to the `GND`, `DIN`, and `12V` terminals of the LED strip.
1. Install a short section of heat shrink tubing over the solder joint.
1. Strip 1.5 mm off from the other end of each wire.
1. Crimp a JST XH series pin to one end of each wire.
1. Insert the pins into the JST XH series housing such that pin 1 connects to `GND`, pin 2 connects to `DIN`, and pin 3 connects to `12V`.

## Environment sensor accessory

The Minuet environmental sensor accessory measures CO₂, temperature, humidity, and barometric pressure.  It is designed to start the fan for ventilation when it gets stuffy inside.  An elevated CO₂ measurement often indicates inadequate ventilation in occupied spaces.

The surface mount parts used in this accessory require special handling and soldering so it's not practical to assemble by hand.

You'll need a long QWIIC I2C cable to connect the sensor to the board.

## Air quality sensor accessory

The Minuet air quality sensor accessory measures particulate matter.  It contains a [PMSA003I breakout board](https://www.adafruit.com/product/4632) from Adafruit.

You'll need a long QWIIC I2C cable to connect the sensor to the board.

## Cover sensor accessory

The cover sensor accessory detects when you have installed an insulated vent cover and engages the safety lock to turn off the fan and the light.

It's a normally-open reed switch that plugs into the `LOCK` connector.  The reed switch closes the circuit when a magnet on the cover is adjacent to it.

Supplies:

- 1x normally-open reed switch with axial leads, such as [this one](https://www.amazon.com/dp/B07YFBQ4HS)
- 1x JST XH series XHP-2 2-pin housing
- 2x JST XH series SXH-001T-P0.6(N) contacts plus a few spares just in case
- 30 AWG 2 conductor ribbon cable
- wire crimping tools
- heat shrink tubing

Instructions:

1. Cut a section of ribbon cable approximately 24-30" or 60-75 cm long.  It needs to be long enough to reach from the fan controller to the fan ceiling flange where it can sense the magnet on the cover.
1. Bend one lead of the reed switch over so that both leads point the same direction.
1. Solder one end of each wire to each lead of the reed switch.  To keep things tidy, it helps to trim the wire and the leads so they lay flat before soldering.
1. Install a section of heat shrink tubing over the reed switch and its leads.
1. Strip 1.5 mm off from the other end of each wire.
1. Crimp a JST XH series pin to one end of each wire.
1. Insert the pins into the JST XH series housing.  The pin order doesn't matter.
