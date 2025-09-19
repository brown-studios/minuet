# Minuet hardware guide

This guide explains how to build Minuet hardware.

- [Project organization](#project-organization)
- [Main parts](#main-parts)
  - [Fan controller](#fan-controller)
  - [Fan motor and adapters](#fan-motor-and-adapters)
  - [Power cable](#power-cable)
  - [Lid motor cable](#lid-motor-cable)
- [Accessories](#accessories)
  - [Light accessory](#light-accessory)
  - [Cover sensor accessory](#cover-sensor-accessory)
  - [Making your own accessories](#making-your-own-accessories)

> [!TIP]
> Consider buying a Minuet kit when they become available to save yourself time and money.  And read on to learn about the hardware!

# Project organization

## Circuit board designs

The [hardware](../hardware/) folder contains all of the Minuet circuit board designs.

Each circuit board major revision resides in its own subfolder and includes a KiCad project, design document with errata, PDF plot of the schematics, and 3D renderings.  Refer to the `design-and-errata.md` for each circuit board to learn how it's supposed work, how the design has evolved through each minor revision, what was learned from that revision, and workarounds for known issues.

- [Minuet v3 design and errata](../hardware/minuet/v3/design-and-errata.md)
- [Light accessory v3 design and errata](../hardware/light/v3/design-and-errata.md)

## Fabricating circuit boards

Refer to each circuit board's design document for specific fabrication notes.

This repository does not contain fabrication files; you can generate them from the KiCad project in whatever format you need.

The KiCad projects contain part numbers and placement information for the JLCPCB PCBA service.  Use the [Fabrication Toolkit](https://github.com/bennymeg/Fabrication-Toolkit) plugin for KiCad to generate the fabrication files for JLCPCB including the gerber files, bill of materials, and part positions.  Many of the parts in the design were selected to reduce fabrication cost at JLCPCB.  At the time of this writing, the MCF8316D motor driver chip had to be sourced from the global supply chain because was not a regularly stocked item at JLCPCB.

If you're using a different PCBA service, you'll need to select equivalent parts.

Some of the SMT parts have fine pitch QFN pads that are not accessible to a soldering iron.  You may need a solder stencil and reflow equipment to assemble these parts reliably.

You may find it more cost effective to have the factory assemble front-side SMT and through-hole parts and then install the remaining back-side through-hole parts by hand.

## Circuit board design guidelines

Here are a few guidelines to consider when contributing to the Minuet circuit board designs:

- Do not check in fabrication files because they're hard to keep in sync with the design files.
- Include links to datasheets for each chip in the KiCad symbols.
- Prefer two-layer boards to keep the designs accessible for hobbyists.
- Prefer SMT parts no smaller than 0603 and keep the layout somewhat sparse to facilitate hand assembly.
- Place SMT parts on the front side of the board only.
- Place through-hole parts on either side as needed for mechanical reasons.
- Place prominent silk screen labels next to each connector and reference it in the documentation.
- Assign net classes to nets that carry high current.
- Record errata in the design document.

# Main parts

## Fan controller

The Minuet fan controller circuit board drives the show.

It is a drop-in replacement for the original Maxxfan circuit board with the original fasteners in the same screw positions and it supports all of the built-in Maxxfan hardware (except the fan motor because that's been replaced by a brushless motor).  Of course, it can do a whole lot more in the same space!

This circuit board has special assembly instructions for the infrared receiver and for adjusting the lid motor current limit trim potentiomer.

Circuit board details: [Minuet v3 design and errata](../hardware/minuet/v3/design-and-errata.md)

Once you've fabricated the circuit board, install the [Minuet firmware](https://github.com/brown-studios/minuet-firmware).

## Fan motor and adapters

Minuet uses a brushless DC motor to drive the fan instead of the original brushed DC motor.

Here's how to choose a fan motor and make adapters to fit the motor to the fan housing.  We recommend choosing a known compatible motor if possible because the process for tuning motors is somewhat challenging.

### Compatible motors

#### StepperOnline 57BYA54-12-01 ([supplier](https://www.omc-stepperonline.com/12v-3000rpm-0-16nm-50w-5-90a-57x57x53-5mm-brushless-dc-motor-57bya54-12-01))

**This is the only motor currently supported out-of-the-box by Minuet.**

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
- Mount screws: 4x M4
- Dimensions: 57 mm diameter x 53.5 mm length

##### Wiring chart

- Phase A: fat yellow wire
- Phase B: fat green wire
- Phase C: fat blue wire
- The remaining wires are for the unused hall sensor and can be secured out of the way or cut off

### Bringing up other motors

#### Motor selection guide

Choose a motor that runs quietly at low speed with minimum vibration.  It doesn't need a lot of torque.  For safety, it must be able to operate continously under load without overheating.  Look for motors that are designed for use in appliances (not for skateboards or model airplanes).

The motor must be brushless.  The 3 phases can be wired in either the wye or delta configuration.

The motor should have a datasheet with published specifications so you know what you're getting.

The motor should have a suitable power rating, perhaps somewhere around 50 W, certainly not hundreds of watts.  Bigger is not better.  Big motors have big magnets and they experience significant [cogging torque](https://en.wikipedia.org/wiki/Cogging_torque) when operated at low speeds which results in excessive noise and vibration for a vent fan.

The motor should be designed for operation at a nominal 12 V.  The actual operating voltage will depend on the supply voltage.

The motor should have a minimum current rating of 4 A per phase.  You can use a smaller motor with a lower current rating but it may not be powerful enough to operate the fan at higher speeds.

The motor should not have hall sensors.  It's ok to have them but Minuet v3 does not use them (previous versions of Minuet did).

You are unlikely to find a suitable motor that is a perfect drop-in replacement for the original motor's dimensions.  That's just physics.  Brushless DC motors are generally more efficient than brushed DC motors of equivalent power so they tend to be smaller.  So you will likely need to make adapters to compensate for the different motor body size, mounting hole pattern, shaft diameter, shaft length, and shaft keying.

#### Motor tuning

Before you can operate a new motor with Minuet, you will need to add the motor to a [table in the Minuet firmware](https://github.com/brown-studios/minuet-firmware/blob/main/minuet/fan_driver.h) and tune a large number of parameters for the [MCF8316D field-oriented control motor driver chip](https://www.ti.com/lit/ds/symlink/mcf8316d.pdf).

Those parameters include:

- Number of poles
- Winding resistance
- Winding inductance
- Back-EMF constant
- Speed control loop terms
- Current limit
- Open loop and closed loop acceleration
- Initial position detection
- Operating speed table

Some of these parameters can be measured or estimated directly by the motor driver chip using the built-in Motor Parameter Extraction Tool.  Other parameters require experimentation to determine optimal values for reliable operation.  It is helpful to have a TI MCF8316D-EVM development board and the TI Motor Studio software.

If the motor spins the wrong direction (e.g. intake when it should be exhaust), swap any two motor phases and record that in your wiring chart.

Explaining the process of motor tuning in detail is beyond the scope of this guide.

### Motor wiring

Here's how to attach a connector to your fan motor if it doesn't already have one that's compatible with Minuet.

##### Supplies

- [JST VH series wire-to-board connectors](https://www.jst.com/products/crimp-style-connectors-wire-to-board-type/vh-connector/)
  - 1x JST VH series VHR-2M housing
  - 3x JST VH series SVH-41T-P1.1 contacts plus a few spares just in case
  - If your wires are too short (see instructions)
    - 18 AWG wire, heat shrink tubing, and soldering supplies
  - A crimping tool

##### Instructions

- Locate the wiring chart for your motor and note the color of the A, B, and C phases.
- Measure your wires.  The wires need to be about 16-20" or 40-50 cm long to comfortably reach from the motor to the circuit board within the fan housing.  If your wires are too short then you can solder on some additional 18 AWG wire.
- Strip the wires back about 1.5 mm.
- Crimp the pins onto each wire.
- Note the numbers or index markings on the side of the connector housings to determine the pin order.
- Assemble the 3-pin motor connector as follows:
  - pin 1: Phase A
  - pin 2: Phase B
  - pin 3: Phase C
- Give the wires a gentle tug to ensure they have been fully seated and latched into the housing.

### Motor shaft adapter

The original fan motor has a 40 mm long, 8 mm diameter D-shaped shaft, with a flat face on one side where the fan blade attaches with a 26 mm deep hub.  Your motor's shaft is probably different so you will need a shaft adapter to achieve the necessary length and diameter.

Here are some ways to assemble a suitable shaft adapter.

#### Rigid coupler and dowel pin shaft adapter

This adapter consists of two parts, a rigid coupler to match the shaft diameter and an 8 mm dowel pin to extend its length to fit the fan blade.

TODO: Add a photo

##### Supplies

- Rigid coupler.  The inner diameter of one end of the coupler must match the diameter of your motor shaft and the other end must be 8 mm to match the dowel pin.
  - [5 mm to 8 mm inner diameter, 22 mm long stainless steel coupler](https://www.amazon.com/gp/product/B07P82D36N/)
  - [8 mm to 8 mm inner diameter, 22 mm long stainless steel coupler](https://www.amazon.com/gp/product/B07P5YZKY5/)
- Dowel pin.  The exposed length of the dowel pin must be at least 26 mm for the fan blade plus enough to insert into the shaft coupler.  A dowel pin with 40 mm overall length works well with the couplers linked above.
  - [8 mm x 40 mm stainless steel dowel pin](https://www.amazon.com/gp/product/B07Z6GC2TR/)

##### Instructions

1. Optional: File a shallow flat face into one end of the dowel pin about 15 mm long.  The flat face helps to prevent the fan blade's grub screw from slipping on the shaft although it doesn't seem to make much difference so you can skip this step.
1. Seat the 8 mm dowel pin up to the midpoint of the coupler such that about 26 to 30 mm of the shaft (flattened end) sticks out.  Gently tighten the coupler's grub screws onto the dowel pin.
1. Insert the coupler onto the motor shaft.  Gently tighten the coupler's grub screws onto the dowel pin.

#### 3D printed shaft adapter

Here's a [model for a 3D printed shaft adapter](https://cad.onshape.com/documents/11f07c0bb608e7010778ac35/w/a82f75dceda39e564795dbd4/e/27885f49708c85d9a551c0f1).  You can configure the model for whatever motor shaft diameter you need.  Attach the adapter to the motor shaft with a pair of M4 grub screws.

**Safety notice**: The shaft adapter experiences significant torque while running the fan so there's a risk it might break or slip off the shaft and hurt someone.  Consider making a shaft adapter from more robust materials.  Please be careful!

TODO: Add a photo

### Motor mount

You will need a mount to securely attach your new fan motor to the Maxxfan's housing which was originally designed for a motor with different dimensions.

The mount has three essential features:

- Two M5 screws spaced 50 mm apart across the diameter of the motor for mounting the motor to the housing, just like the original motor.
- Screw holes for fastening the new motor to the mount.
- Spacers to backset the new motor from the housing to compensate for the excess length of the shaft adapter so the fan blade fits properly.  Without them, the fan blade will stick out too far to fit behind the insect screen.

Here are some ways to assemble a suitable mount.

#### 3D printed mount

Here's a [configurable model](https://cad.onshape.com/documents/11f07c0bb608e7010778ac35/w/a82f75dceda39e564795dbd4/e/9979bb27f5cf3d9f46ddfa29) that you can use as a starting point.  It has integrated spacers and stiffening ribs to backset the motor so the shaft sticks out just the right amount for the fan blade to attach.

Use a strong plastic with good heat and UV resistance such as PETG.

TODO: Add a photo

##### Supplies

- 2x M5 x 14 mm cap screws (a little longer is ok)
- Screws for your motor and shaft adapter combination
  - For 57BYA54 with a rigid coupler and dowel pin shaft adapter, use 4x M4 x 22 mm cap screws
- Washers for the M5 screws and the motor screws

##### Instructions

1. Tap the M5 screw holes into the plate.
1. Screw the M5 screws through the mount from the side on which the motor is installed.  Tighten only until snug to avoid stripping the plastic threads.  Do not use threadlocker.
1. Screw the motor to the plate.  Add a washer on each screw between the screw head and the plate.

## Power cable

The power cable uses a [JST VH series wire-to-board connector](https://www.jst.com/products/crimp-style-connectors-wire-to-board-type/vh-connector/).

- Pin 1 is negative (ground)
- Pin 2 is positive (+12 V DC nominal)

TODO: Add a photo

##### Supplies

- 1x JST VH series VHR-2M housing
- 2x JST VH series SVH-41T-P1.1 contacts plus a few spares just in case
- 18 AWG wire, preferably in distinct colors to help identify positive (red) and negative (black)
- wire crimping tools

##### Instructions

- Cut two pieces of wire long enough to make the connection from the fan housing where the circuit board will be installed to the electrical supply.  About 12" or 30 cm should be plenty.  Alternatively, you can crimp the contacts directly to the electrical supply wire.
- Strip 2 mm off the end of the wire.
- Crimp the JST VH contacts to the wires.
- Insert the contacts into the JST VH housing paying attention to the polarity chart shown above.

## Lid motor cable

This cable adapts the lid motor's [Molex 1625 series wire-to-wire connector](https://www.molex.com/en-us/products/series-chart/1625) to Minuet's [JST XH series wire-to-board connector](https://www.jst.com/products/crimp-style-connectors-wire-to-board-type/xh-connector/).

TODO: Add a photo

##### Supplies

- 1x Molex 1625 series 03061023 (1625-2R3) receptacle
- 2x Molex 1625 series 02061101 contacts plus a few spares just in case
- 1x JST XH series XHP-2 2-pin housing
- 2x JST XH series SXH-001T-P0.6(N) contacts plus a few spares just in case
- 22 AWG 2 conductor ribbon cable
- wire crimping tools

##### Instructions

- Cut a section of ribbon cable approximately 8" or 20 cm long.
- Strip 1.5 mm off from each end of each wire.
- Crimp a Molex 1625 series pin to one of each wire and a JST XH series pin to the other end.
- Insert the pins into their respective housings such that pin 1 of the Molex 1625 series connector connects to pin 1 of the JST XH series connector.  Likewise, pin 2 connects to pin 2.

# Accessories

## Light accessory

The Minuet light accessory lets you attach a light to your fan.  It plugs into the Minuet `EXPANSION` port.

You can use this accessory as a break-out board for your own circuits and it includes a prototyping area for mounting through-hole components.

Circuit board details: [Minuet light accessory v3 design and errata](../hardware/light/v3/design-and-errata.md)

### LED strip

This section section describes how to build an addressable LED strip with a connector that works with Minuet out-of-the-box.  You can use a different LED strip instead but you may need to customize the firmware to interface with it correctly.

TODO: Add a photo

##### Supplies

- 1 meter of [BTF Lighting SK6812 RGBWW, IP65, 60 LEDs/meter, 12 V](https://www.btf-lighting.com/products/dc12v-sk6812-rgbw-led-strip-individual-addressable?variant=46547794854114) or similar
- 1x JST XH series XHP-3 3-pin housing
- 3x JST XH series SXH-001T-P0.6(N) contacts plus a few spares just in case
- 22 AWG 3 conductor ribbon cable
- wire crimping tools
- heat shrink tubing

##### Instructions

- Cut a section of ribbon cable approximately 12" or 30 cm long.
- Cut a section of 57 pixels from the LED strip.  This is enough to fit around the inner circumference of the fan housing.
- Solder one end of each wire to the `GND`, `DIN`, and `12V` terminals of the LED strip.
- Install a short section of heat shrink tubing over the solder joint.
- Strip 1.5 mm off from the other end of each wire.
- Crimp a JST XH series pin to one end of each wire.
- Insert the pins into the JST XH series housing such that pin 1 connects to `GND`, pin 2 connects to `DIN`, and pin 3 connects to `12V`.

## Cover sensor accessory

The cover sensor accessory detects when you have installed an insulated vent cover and engages the safety lock to turn off the fan and the light.

It's a normally-open reed switch that plugs into the `LOCK` connector.  The reed switch closes the circuit when a magnet on the cover is adjacent to it.

TODO: Add a photo

##### Supplies

- 1x normally-open reed switch with axial leads, such as [this one](https://www.amazon.com/dp/B07YFBQ4HS)
- 1x JST XH series XHP-2 2-pin housing
- 2x JST XH series SXH-001T-P0.6(N) contacts plus a few spares just in case
- 22 AWG 2 conductor ribbon cable
- wire crimping tools
- heat shrink tubing

##### Instructions

- Cut a section of ribbon cable approximately 24-30" or 60-75 cm long.  It needs to be long enough to reach from the fan controller to the fan ceiling flange where it can sense the magnet on the cover.
- Bend one lead of the reed switch over so that both leads point the same direction.
- Solder one end of each wire to each lead of the reed switch.  To keep things tidy, it helps to trim the wire and the leads so they lay flat before soldering.
- Install a section of heat shrink tubing over the reed switch and its leads.
- Strip 1.5 mm off from the other end of each wire.
- Crimp a JST XH series pin to one end of each wire.
- Insert the pins into the JST XH series housing.  The pin order doesn't matter.

## Making your own accessories

Minuet gets better when you take advantage of its place in the middle of your vehicle's roof for accessories.

- Attach many off-the-shelf [QWIIC](https://www.sparkfun.com/qwiic) compatible I2C peripherals to Minuet with just a wire.
- Use the [Light accessory](#light-accessory) as a break-out board for your own circuits and it includes a prototyping area for mounting through-hole components.
- Make your own circuit board that plugs into the `EXPANSION` port.

Refer to the [Minuet v3 design and errata](../hardware/minuet/v3/design-and-errata.md) and schematics for the electrical parameters of these ports.

> [!TIP]
> You will likely need to customize the [Minuet firmware](https://github.com/brown-studios/minuet-firmware) for your accessory.  We recommend consulting the list of [ESPHome components](https://esphome.io/components/) to help choose your peripherals so you won't need to write as much code to get them working.

Here are some ideas of stuff you could build:

- Add a CO₂, temperature, humidity sensor: [scd4x sensor](https://esphome.io/components/sensor/scd4x.html)
- Add a temperature, pressure sensor, humidity, gas sensor: [bmp680 sensor](https://esphome.io/components/sensor/bme680)
- Add a button near the fan to trigger something: [gpio binary sensor](https://esphome.io/components/binary_sensor/gpio)
- Add a relay to do something when the fan is running: [gpio switch](https://esphome.io/components/switch/gpio)
- Detect when humans are present: [dfrobot sen0395](https://esphome.io/components/dfrobot_sen0395)

Consider sharing your new accessory with others! ❤️
