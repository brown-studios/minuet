# Minuet installation guide

This guide explains how to install Minuet into your Maxxfan.

## Supplies

- Minuet circuit board
- [Brushless DC fan motor with wire harness, shaft adapter, and motor mount](fan-motors-guide.md)
- Cover motor cable or supplies to make one (see [cover motor connection](#cover-motor-connection))
- Power cable or supplies to make one (see [power connection](#power-connection))
- #2 Philips screwdriver
- 7/64" allen key

## Setup

Follow the [setup guide](setup-guide.md) to configure your Minuet circuit board for your fan motor and to install the firmware.

## Safety check

Confirm that your Maxxfan's electrical supply meets these requirements:

- Voltage: 12 V DC nominal and absolute maximum range from 9 to 16 V DC
- Wiring: minimum 18 AWG (0.8 mm²)
- Circuit protection: 5 A fuse or circuit breaker

## Disassembling the Maxxfan

Start by clearing some space below the fan to work.  You do not need to remove the fan from the roof of your vehicle because all of the necessary fasteners are accessible from inside.

1. Disconnect the electrical supply from the fan (such as by removing its fuse and setting it aside).  Confirm that the fan is non-operational by attempting to turn it on.
1. Remove the insect screen by turning the posts that retain it to the fan body until they unlatch.
1. Remove the fan blade from the motor shaft using a 7/64" allen key to loosen the grub screw until it the fan blade slides off the shaft.
1. Fully open the cover by turning the cover knob counter-clockwise.
1. Reach up and trace the fan motor wires from the back of the fan motor down to where they are zipties to the housing.  Cut the zipties.
1. Continue feeling along the fan motor wires to where they pass under a narrow plastic weatherguard that obstructs the opening through which the wires enter the fan housing.  Removing the weatherguard is a little tricky because of the limited clearance for tools under the cover (even when fully opened).  Feel around the weatherguard to locate a screw head on each side of it.  Use a short #2 Philips screwdriver to remove those screws and the weatherguard.
1. Remove the cover knob using a #2 Philips screwdriver.
1. Remove the 4 screws that hold the control panel in place using a #2 Philips screwdriver.  These screws were previously hidden under the insect screen.
1. Assess whether you have enough clearance to access the wiring within the fan housing.  If your electrical supply wires or wall control cables are tight then you may need to remove the trim ring and parts of your ceiling to provide some slack.  Proceed with the next step once you're able to move the control panel a handspan away from the body of the fan.
1. Disconnect the wall control, if present.
1. Disconnect the cover motor and the fan motor.
1. Disconnect (or cut) the electrical supply.  If you choose to cut these wires, make sure to leave enough slack on both ends to reconnect them later should you have need.
1. Now the control panel should be completely free of the body, set it aside.
1. Use a 8 mm socket screwdriver to remove the M5 nuts that hold the fan motor to the housing and pay attention to the washers under the nuts so you don't lose them!
1. Remove the fan motor and put it away, you won't be needing it anymore but keep the washers and nuts.

That's it with disassembly.

## Installing the new fan motor

Assemble the fan motor wire harness, shaft adapter, and mounting plate before proceeding.

1. Follow the fan motor shaft adapter instructions to attach the shaft adapter to the fan motor.
1. Follow the fan motor mount instructions to attach the fan motor to its mount.
1. Raise the fan motor and its mount into position in the center of the fan housing.  Align the mount's two M5 screws with the mount holes in the housing and seat the mount into place.
1. Secure the mount in place with the original washers and M5 nuts using an 8 mm socket screwdriver.  Do not overtighten.
1. Drape the fan motor wire harness along the plastic spoke that supports the motor.  Pass the connector ends through the opening in the housing above the area where the control panel sits.  Use zip ties to secure the wires to the spoke.

Now you have the option of reinstalling the weatherguard over the opening in the housing (the one that was so tricky to disassemble).  It may help keep condensation out of the electronics but otherwise it doesn't seem to do much and might not worth the trouble.

To reinstall the weatherguard:

1. The weatherguard has a notch that fits over the wires where they pass through it.  This notch originally only needed to be big enough for 2 wires but now there are 8 so it needs to be expanded to fit.  Carefully away excess plastic around the notch until it fits over the fan motor wire harness without crimping them.
1. Fully open the cover by turning the cover knob counter-clockwise.
1. Preinstall the screws into the weatherguard then seat it into place over the wire harness.
1. Tighten down the screws a little bit at a time while checking to ensure that the wires pass through the notch and don't get crimped by the plastic.

Now you can close the cover by turning the cover knob clockwise.

## Connecting the cover motor

Attach the Minuet cover motor cable to the cover motor.  Leave the other end loose.

### How to make the cover motor cable

The cable adapts the cover motor's [Molex 1625 series wire-to-wire connector](https://www.molex.com/en-us/products/series-chart/1625) to Minuet's [JST XH series wire-to-board connector](https://www.jst.com/products/crimp-style-connectors-wire-to-board-type/xh-connector/).

#### Supplies

- 1x Molex 1625 series 03061023 (1625-2R3) receptacle
- 2x Molex 1625 series 02061101 contacts plus a few spares just in case
- 1x JST XH series XHP-2 2-pin housing
- 2x JST XH series SXH-001T-P0.6(N) contacts plus a few spares just in case
- 22 AWG wire
- wire crimping tools

#### Instructions

- Cut two pieces of wire approximately 10" or 25 cm long.
- Strip 1.5 mm off from each end of each wire.
- Crimp a Molex 1625 series pin to one of each wire and a JST XH series pin to the other end.
- Insert the pins into their respective housings such that pin 1 of the Molex 1625 series connector connects to pin 1 of the JST XH series connector.  Likewise, pin 2 connects to pin 2.

## Connecting power

Attach the Minuet power cable to your electrical supply.

Pay carefully attention to the polarity!  The Maxxfan's original wires are (confusingly) white for negative and black for positive.  Make sure you know which is which if you intend to reuse these wires.  When in doubt, check your electrical supply with a multi-meter before making new connections and label them accordingly.

### How to make the power cable and identify its polarity

The power cable uses a [JST VH series wire-to-board connector](https://www.jst.com/products/crimp-style-connectors-wire-to-board-type/vh-connector/).

- Pin 1 is negative (ground)
- Pin 2 is positive (+12 V DC)

#### Supplies

- 1x JST VH series VHR-2M housing
- 2x JST VH series SVH-41T-P1.1 contacts plus a few spares just in case
- 18 AWG wire, preferably in distinct colors to help identify positive and negative
- wire crimping tools

#### Instructions

- Cut two pieces of wire long enough to make the connection from the fan housing where the circuit board will be installed to the electrical supply.  Alternatively, you can crimp the contacts directly to the electrical supply wire.
- Strip 2 mm off the end of the wire.
- Crimp the JST VH contacts to the wires.
- Insert the contacts into the JST VH housing paying attention to the polarity chart shown above.

## Removing the original circuit board from the control panel

Remove the original circuit board from the control panel.

1. Unplug the thermistor (and rain sensor if you have one) from the original circuit board.
1. Remove the 3 screws and plastic washers that hold the original circuit board to the control panel.
1. Gently unplug the flexible cable for the built-in keypad from the original circuit board.
1. Now the original circuit board should be free of the control panel, put it away since you won't be needing it anymore.  Keep the screws and plastic washers.

## Installing the Minuet circuit board into the control panel

Ensure that you have completed the set-up process for your minuet circuit board before installing it.

1. Orient the Minuet circuit board with the header labeled **PANEL** facing down into the control panel.  Make sure that the 3 mounting holes line up with the plastic standoffs on the control panel.
1. Gently plug the flexible cable for the built-in keypad to the header labeled **PANEL**.
1. Screw the board into place with the 3 screws and plastic washers that were used for the original circuit board.
1. Plug the thermistor connector into the socket labeled **THERMISTOR**.
1. If you have a peripheral that plugs into the **EXPANSION** header, configure it according to its documentation then plug it into the socket.  Take care to orient the peripheral to fit within the outline of the main board and ensure that its pins are fully seated.
    - [Lighting and load accessory board](../hardware/load/design-and-errata.md)
1. If you have a peripheral with a QWIIC interface, plug it into the **QWIIC** connector using a QWIIC cable.

## Reassembling the Maxxfan

For reassembly, it may help to have a second pair of hands to support the control panel while screwing it back into place.

1. Hold the control panel near the unit.
1. Plug the cover motor connector into the socket labeled **LID** (v1 hardware) or **COVER** (v2 hardware).
1. Plug the fan motor connector into the socket labeled **FAN MOTOR**.
1. Plug the fan motor hall sensor connector into the socket labeled **FAN SENSOR**.
1. Plug the Maxxfan wall control cable into the socket labeled **WALL CONTROL**, if you have one (v2 hardware only).
1. Plug the power connector into the socket labeled **POWER**.
1. Raise the control panel into place while guiding and gently tucking the wires into the open space within the housing behind it so they don't get pinched.
1. Screw the control panel into place with the 4 original screws using a #2 Philips screwdriver.
1. Screw the cover knob into place using a #2 Philips screwdriver.
1. Press the fan blade onto the shaft and tighten the grub screw with a 7/64" allen key.  Make sure it spins freely.
1. Install the insect screen and turn the posts that retain it until they latch into place.
1. Reconnect the electrical supply (reinstall the 5 A fuse).

Congratulations, you have finished installing Minuet!

## Further reading

- [User guide](user-guide.md)
