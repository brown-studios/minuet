# Minuet hardware guide

This guide describes Minuet's custom circuit board.

## Overview

Minuet entirely replaces the Maxxfan's original circuit board within the fan housing using the original screws.  It has complete control over the fan's operation and can be programmed to work however you like.

Minuet has the following major components:

- Brushless DC motor driver for the fan
- Brushed DC motor driver for the cover
- Connections for the built-in Maxxfan keypad and thermistor
- ESP32-C3 microcontroller with integrated WiFi antenna
- RESET button to reset the microcontroller
- BOOT button to enter the bootloader
- USB-C connector for programming
- QWIIC I2C bus connector
- GPIO expansion header
- Switching power supply for the electronics
- Self-resetting polyfuse for overcurrent protection
- Jumpers for configuring the hardware as described in the [setup guide](setup-guide.md)

## Design artifacts

Each revision lives in its own [hardware subfolder](../hardware/) and consists of a design document (with errata), a KiCad project, and a plot of the schematics in PDF format.

- [v1 design and errata](../hardware/v1/design-and-errata.md): Initial prototype
- [v2 design and errata](../hardware/v2/design-and-errata.md): Higher current brushless motor driver

The gerber files and bill of materials are not checked into the repository.  Generate them from KiCad in whatever format you need for manufacture and assembly.

The circuit board has two copper layers.  The front side of the circuit board has all of the SMT components.  The back side of the circuit board has most of the connectors and silkscreen labels that can be read by end users without dismounting the circuit board from the control panel.

All of the SMT components should be at least 0603 dimension and the overall layout is somewhat sparse so they can be placed by hand with tweezers or a vacuum pump and a steady hand (under a microscope).

Some (QFP) chip pads are not accessible to a soldering iron.  You may need a solder stencil and reflow hot plate or oven to assemble these components.

The schematic assigns net classes to nets that carry more current.  Pay special attention to these nets when laying out their traces on the PCB, especially near the closely spaced motor driver pads.

You'll find the datasheets for the various chips linked within the KiCad schematics.

## Further reading

- [Fan motor guide](fan-motor-guide.md)
- [Setup guide](setup-guide.md)
- [Installation guide](installation-guide.md)
- [User guide](user-guide.md)
