# Minuet fan controller

Minuet is a smart brushless DC motor controller for the [MAXXAIR Maxxfan Deluxe vent fan](https://www.maxxair.com/products/fans/maxxfan-deluxe/).

* No more squeaking motor! Replace your fan's original brushed motor with a quieter low maintenance brushless motor.
* Install Minuet with simple hand tools: it is a complete drop-in replacement that does not require making any irreversible modifications so you can easily revert back to the original equipment later if you want.
* Control your fan using your phone, Home Assistant, the built-in keypad, a wired Maxxfan wall controller, and/or the Maxxfan IR remote.
* Set the thermostat to automatically run the fan at your chosen temperature setpoint, fan speed, and direction.
* Customize the [ESPHome](https://esphome.io/) configuration to add new features that better meet your needs.
* Connect lights to your fan with the lighting and load accessory board.
* Connect your own environmental sensors and accessories to Minuet's [QWIIC](https://www.sparkfun.com/qwiic) I2C port and GPIO expansion port.
* The hardware and software is open source: help make it better and share your improvements with others.

## Author's note and project status

**Minuet is in early development.  It is not ready for use by the general public yet.  You cannot buy the hardware pre-assembled; you have to make it yourself.  These statements will change as the project matures.**

As the author of Minuet, I want to give you a sense of what to expect from this project now and in the near future.

The first revision of the Minuet hardware is installed in my campervan and it works somewhat well.  I do not recommend building this revision of the hardware due to schematic errata noted in the accompanying documentation.  It is after all a prototype.

The second revision of the Minuet hardware is feature complete.  It supports more powerful fan motors, IR remote control, wall controls, rain sensor, thermistor, piezo buzzer for (polite and configurable) audible feedback.  I've ordered the circuit boards and hopefully the design works well and is closer to a final version that I can send to folks.

If there is sufficient interest, I would like to commission a small manufacturing run of a hardware kit to make it easier for people to install Minuet.

As a former software engineer, I have no prior experience designing open source hardware and delivering it to end-users.  It is certainly the case that I don't know what I don't know at this stage in the project.  If you're interested in helping this project along, please consider becoming a contributor.

I'm looking for folks to assist in lots of ways:

- Reviewing circuit board schematics and layouts for EMC, safety, and correctness.
- Polishing the control systems and user interface.
- Writing end-user documentation.
- Creating videos to show folks how to install and use Minuet.
- Testing prototypes in different environments.
- Making custom parts.
- Optimizing the bill of materials for production.
- Preparing manufacturing artifacts and engaging suppliers.
- Selecting packaging materials and shipping methods.
- Everything else that I haven't thought of that would make this project more useful to more people!

## Prototype in action

[Link to Minuet playlist on YouTube](https://www.youtube-nocookie.com/embed/videoseries?si=fa14cJ42dhqO0x0U&amp;list=PL8ZnNA3SFfE8v-qSholF0Ovc9Exv59-uN)

## Compatibility

Minuet v1, the initial prototype, has been tested and works well with the following Maxxfan models though it does not support the IR remote control or wired wall controls.

- Maxxfan Deluxe 7500K

Minuet v2, the feature complete revision, should work with most Maxxfan Deluxe and Maxxfan Plus models, the IR remote control, and wired wall controls.  This section will be updated once testing is underway.

Please contact the author if you would like to volunteer to help test Minuet with other models.

## Getting started

Read these guides to learn how to build, install, and use Minuet.

1. [Hardware guide](docs/hardware-guide.md): All about Minuet's circuit board
1. [Fan motor guide](docs/fan-motor-guide.md): How to choose a brushless DC fan motor for Minuet, wire it up, and make adapters for installing it
1. [Setup guide](docs/setup-guide.md): How to configure Minuet for your motor, network, automation, and accessories
1. [Installation guide](docs/installation-guide.md): How to install Minuet into your Maxxfan
1. [User guide](docs/user-guide.md): How to use Minuet once it has been installed

Good luck and enjoy your fan!

## Acknowledgements

Thanks to [skypeachblue](https://github.com/skypeachblue/maxxfan-reversing) for helping to reverse engineer the Maxxfan IR remote control protocol.

## Notice

The Minuet software, documentation, design, and all copyright protected artifacts are released under the terms of the [MIT license](LICENSE).

The Minuet hardware is released under the terms of the [CERN-OHL-W license](hardware/LICENSE).
