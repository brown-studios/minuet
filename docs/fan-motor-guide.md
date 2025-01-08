# Minuet fan motor guide

This guide explains how to choose a brushless DC fan motor and adapt it for use with Minuet.

## Steps

1. Choose a fan motor from the list of [compatible motors](#compatible-motors) or follow the [motor selection guide](#motor-selection-guide).
1. Make a [wire harness](#wire-harness) for your fan motor.
1. Assemble a [shaft adapter](#shaft-adapter) for your fan motor.
1. Assemble a [mount](#mount) for your fan motor.

## Compatible motors

### StepperOnline 42BLR53-12-01 ([supplier](https://www.omc-stepperonline.com/12v-3000rpm-0-048nm-15w-1-9a-round-%D1%8442x53mm-brushless-dc-motor-42blr53-12-01))

This small motor runs smoothly with minimal vibration.  It has an ample power rating for day-to-day ventilation but it can't quite match the air flow of the original motor at high speed.

#### Specifications

- Rated voltage: 12 V
- Rated power: 15 W
- Rated current: 1.9 A
- Sensor type: 3 digital hall sensors with 30° placement
- Shaft diameter: 5 mm
- Shaft length: 20 mm
- Mount screws: 4x M3
- Dimensions: 42 mm diameter x 53 mm length

#### Wiring chart

- Motor winding connections
  - U phase: orange wire
  - V phase: green wire
  - W phase: brown wire
- Hall sensor connections
  - Ground: black wire
  - U hall: white wire
  - V hall: blue wire
  - W hall: yellow wire
  - Power: red wire

### StepperOnline 57BYA54-12-01 ([supplier](https://www.omc-stepperonline.com/12v-3000rpm-0-16nm-50w-5-90a-57x57x53-5mm-brushless-dc-motor-57bya54-12-01))

This motor is somewhat larger than 42BLR53-12-01 and run smoothly though it has a bit more vibration at low speeds.  It has a sufficiently high power rating for maximum air flow and continuous operation.  There's no need to use a motor any more powerful than this one: its current rating already exceeds Minuet's current limit.

### Specifications

- Rated voltage: 12 V
- Rated power: 50 W
- Rated current: 5.9 A
- Sensor type: 3 digital hall sensors with 30° placement
- Shaft diameter: 8 mm
- Shaft length: 21 mm
- Mount screws: 4x M4
- Dimensions: 57 mm diameter x 53.5 mm length

### Wiring chart

- Motor winding connections
  - U phase: fat yellow wire
  - V phase: fat blue wire
  - W phase: fat green wire
- Hall sensor connections
  - Ground: thin black wire
  - U hall: thin yellow wire
  - V hall: thin blue wire
  - W hall: thin green wire
  - Power: thin red wire

## Motor selection guide

### How to choose a motor

Choose a motor that runs quietly at low power with minimum vibration.  It doesn't need a lot of torque.  For safety, it must be able to operate continously without overheating.  Look for motors that are designed for use in appliances (not for skateboards or model airplanes).

The motor must be brushless.  The 3 phases can be wired in either the wye or delta configuration.

The motor should have a suitable power rating, perhaps somewhere between 15 W and 50 W, certainly not hundreds of watts.  Bigger is not better.  Big motors have big magnets and they experience significant [cogging torque](https://en.wikipedia.org/wiki/Cogging_torque) when operated at low speeds which results in excessive noise and vibration for a vent fan.

The motor should be designed for operation at a nominal 12 V.  The actual operating voltage will depend on the supply voltage.

The motor should have a minimum current rating of 1.5 A per phase.  You will need to configure the current limit of your Minuet board to not exceed your motor's current rating.  The v1 hardware supports a maximum of 1.5 A and the v2 hardware supports a maximum of 3 A.  You can use a motor with a higher current rating than Minuet supports but beyond a certain point you are at greater risk of having problems operating the fan quietly at low speeds.

The motor must have digital hall sensors, prefereably with 30° placement (refers to the electrical phase angle of the signals produced by the motor's hall sensors relative to the back EMF of the motor coils).  Unfortunately, this information may not be in the datasheet so you'll just have to try it out.

You are unlikely to find a suitable motor that is a perfect drop-in replacement for the original motor's dimensions.  That's just physics.  Brushless DC motors are generally more efficient than brushed DC motors of equivalent power so they tend to be smaller.  Refer to the Minuet documentation to make adapters for the different motor body size, mounting hole pattern, shaft diameter, shaft length, and shaft keying as required.

### How to determine the wiring chart for an unknown motor

The following method uses trial and error to determine the correct wiring order for the motor phases and hall sensors of an unknown motor.  If you have the know-how, you can use a multi-channel oscilloscope instead to observe the electrical phase angles.

Start by reading the motor's datasheet if you have one.  The datasheet should indicate which wires are for the motor and which wires are for the hall sensors although their labels may not match the conventions used by Minuet so you must test them to ensure correct operation.

If you don't have a datasheet, then you can make an educated guess.  The three motor phase wires are typically thicker than the five hall sensor wires.  If you measure the resistance between any pair of motor phases with a multimeter, it should be about the same and in the range of a few ohms.  For the hall sensor wires, with any luck the Power wire is red, the Ground wire is Black, and the remaining three wires are the hall sensor signals.  Your motor might have an additional connection for temperature sensing which you can ignore (and is more typical for much larger motors than you should be using with Minuet).

1. Temporarily label the wires for the motor windings U, V, and W in some arbitrary order.
1. Identify the wires for the hall sensor Power (+5 V DC) and Ground.  Then temporarily label the remaining hall sensor wires U', V', and W' in some arbitrary order.
1. Securely mount the motor on your workbench in a vise.  Do not attach the fan blade during this test!  Please take care to prevent damage or injury.
1. Choose a method for safely making temporary connections to Minuet's motor and sensor ports for test purposes.  For example, you could attach alligator clips with Dupont female connectors to the pins within the connector sockets; or you could make a jumper cable, twist the bare wires together, and insulate them with tape; or you could use Wago terminals.
1. Following your temporary labels, make the following connections:
    - Motor port: pin 1 to U, pin 2 to V, pin 3 to W
    - Sensor port: pin 1 to Ground, pin 2 to U', pin 3 to V', pin 4 to W', pin 5 to Power
1. Apply 12 V DC electricity to Minuet, ideally with a current limited bench power supply set to at least 1.5 A.
1. Start the fan at the lowest speed in the *Forward aka. Intake aka. Clockwise direction*.  Observe what happens for a moment then stop it.
    - If the motor spins in the wrong direction, swap the V and W phases.  Try again.
    - If the motor jerks then stalls or judders, swap the V' and W' hall sensors.  Try again.  If that doesn't work, then try all 6 possible combinations of the U', V', and W' hall sensors until the motor does spin up properly.  If after trying all combinations the motor still judders, then you may need to configure the board for a different hall sensor placement such as 0°.
    - If the motor does not start at all, stop.  Recheck your connections.  Listen to the motor, it might be trying to start it but doesn't have enough current.  Consider testing the motor using an off-the-shelf electronic speed controller to make sure it works at all.  If all else fails, the motor might simply not be compatible with Minuet.
1. Next start the fan at the lowest speed in the *Reverse aka. Exhaust aka. Counter-clockise direction*.  Observe what happens for a moment then stop it.
    - If the motor spins in the wrong direction, stalls, judders, or runs at a different speed in the reverse direction than it was in the forward direction, then keep trying hall sensor combinations until you find one that works properly both forwards and in reverse.
1. Finally try operating the fan in each direction and at different speeds.  The motor should run smoothly and symmetrically in each direction.
1. Now that you have identified the correct wiring for your motor, update your labels based on how you have wired the motor and sensor ports.

Congratulations!  You now have a wiring chart from which to make a wiring harness for your motor.

Please share your results with the Minuet project. ❤️

## Wire harness

Here's how to make a Minuet compatible wire harness with [JST XH series wire-to-board connectors](https://www.jst.com/products/crimp-style-connectors-wire-to-board-type/xh-connector/).

### Supplies

- 1x JST XH series XHP-3 3-pin housing
- 1x JST XH series XHP-5 5-pin housing
- 8x JST XH series SXH-001T-P0.6(N) contacts plus a few spares just in case
- A micro connector crimping tool such as [iCrimp IWS-3220M](https://www.amazon.com/gp/product/B078WPT5M1/)
- If your motor wires are too short (see instructions):
  - JST XH extension cables such as these [3-pin](https://www.amazon.com/gp/product/B07QLYCVK3/) / [5-pin](https://www.amazon.com/gp/product/B07Q29TG24/)
  - 22 AWG wire, heat shrink tubing, and soldering supplies

### Instructions

- Locate the wiring chart for your motor.
- Measure your wires.  The wires need to be about 16-20" or 40-50 cm long to comfortably reach from the motor to the circuit board within the fan housing.  If your wires are too short then you can solder on some additional wire (22 AWG minimum) or use JST XH extension cables to make up the difference.
- Strip the wires back about 1.5 mm.
- Crimp the pins onto each wire.
- Sort the wires into two groups: those for the motor windings and those for the hall sensors based on the wiring chart.
- Note the numbers or index markings on the side of the connector housings to determine the pin order.
- Assemble the 3-pin motor connector as follows:
  - pin 1: U phase
  - pin 2: V phase
  - pin 3: W phase
- Assemble the 5-pin hall sensor connector as follows:
  - pin 1: Ground
  - pin 2: U hall
  - pin 3: V hall
  - pin 4: W hall
  - pin 5: Power
- Give the wires a gentle tug to ensure they have been fully seated and latched into the housing.

## Shaft adapter

The original fan motor has a 40 mm long, 8 mm diameter D-shaped shaft, with a flat face on one side where the fan blade attaches with a 26 mm deep hub.  Your motor's shaft is probably different so you will need a shaft adapter.

Here are some ways to assemble a suitable shaft adapter.

### Rigid coupler and dowel pin shaft adapter

(TODO: Add a photo)

This adapter consists of two parts, a rigid coupler to match the shaft diameter and an 8 mm dowel pin to extend its length to fit the fan blade.

#### Supplies

- Rigid coupler.  The inner diameter of one end of the coupler must match the diameter of your motor shaft (such as 5 mm) and the other end must be 8 mm to match the dowel pin.
  - [5 mm to 8 mm inner diameter, 22 mm long stainless steel coupler](https://www.amazon.com/gp/product/B07P82D36N/)
  - [8 mm to 8 mm inner diameter, 22 mm long stainless steel coupler](https://www.amazon.com/gp/product/B07P5YZKY5/)
- Dowel pin.  The length of the dowel pin must be at least 26 mm for the fan blade plus enough to insert into the shaft coupler.  40 mm works well with the couplers linked above.
  - [8 mm x 40 mm stainless steel dowel pin](https://www.amazon.com/gp/product/B07Z6GC2TR/)

#### Instructions

1. Optional: File a shallow flat face into one end of the dowel pin about 15 mm long.  The flat face helps to prevent the fan blade's grub screw from slipping on the shaft although it isn't strictly necessary so you can skip this step.
1. Seat the 8 mm dowel pin into the coupler such that about 26 to 30 mm of the shaft (flattened end) sticks out.
1. Insert the coupler onto the motor shaft.
1. Tighten the coupler's grub screws firmly but not so tightly as to risk damaging them.

### 3D printed shaft adapter

(TODO: Add a photo)

Here's a [model for a 3D printed shaft adapter](https://cad.onshape.com/documents/11f07c0bb608e7010778ac35/w/a82f75dceda39e564795dbd4/e/27885f49708c85d9a551c0f1).  You can configure it for whatever motor shaft diameter you need.  Attach it to the motor shaft with a pair of M4 grub screws.

**Safety notice**: The shaft adapter is subjected to significant torque while running the fan so there's a risk it might break or slip off the shaft and hurt someone.  Consider making a more robust shaft adapter once you're satisfied with your tests.  Please be careful!

## Mount

You will need a mount to securely attach your new fan motor to the Maxxfan's housing which was originally designed for a motor with different dimensions.

The mount has three essential features:

- Two M5 screws spaced 50 mm apart across the diameter of the motor for mounting the motor to the housing, just like the original motor.
- Screw holes for fastening the new motor to the mount.
- Spacers to backset the new motor from the housing to compensate for the excess length of the shaft adapter so the fan blade fits properly.  Without them, the fan blade will stick out too far to fit behind the insect screen.

Here are some ways to assemble a suitable mount.

### Metal plate or 3D printed mount

(TODO: Add a photo)

Here's a [configurable model](https://cad.onshape.com/documents/11f07c0bb608e7010778ac35/w/a82f75dceda39e564795dbd4/e/9979bb27f5cf3d9f46ddfa29) that you can use as a starting point.  You can either manufacture it as a metal plate with spacers to backset the motor or 3D print it with integrated spacers and stiffening ribs.

The metal plate variant is designed to be laser cut from 3 mm aluminum but steel would be fine too.  If you are having your plate manufactured by an online service, save time by asking them to tap the two M5 screw holes.

The 3D printed variant should be made from a strong plastic with good heat and UV resistance such as PETG.

#### Supplies

- 2x M5 x 14 mm screws (a little longer is ok)
- Screws (both variants) and spacers (for the metal plate variant) for your motor and shaft adapter combination
  - For 42BLR53 with a rigid coupler and dowel pin shaft adapter, use 4x M3 x 22 mm screws with [M3 x 15 mm spacers](https://www.amazon.com/gp/product/B0CQF68HRC/)
  - For 57BYA54 with a rigid coupler and dowel pin shaft adapter, use 4x M4 x 22 mm screws with M4 x 15 mm spacers
- Washers for the M5 screws and the motor screws (for the 3D printed variant)

#### Instructions

1. Tap the M5 screw holes.
1. Screw the motor to the plate.
    - Metal plate variant: Add a spacer on each screw between the plate and the motor.
    - 3D printed variant: Add a washer on each screw between the screw head and the plate.
1. Screw the M5 screws through the mount from the side on which the motor is installed.
    - Metal plate variant: Apply threadlocker to each screw.
    - 3D printed variant: Add a washer on each screw between the screw head and the plate.

## Further reading

- [Setup guide](setup-guide.md)
- [Installation guide](installation-guide.md)
- [User guide](user-guide.md)
