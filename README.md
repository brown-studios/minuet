# Minuet fan controller

Minuet is a smart brushless DC motor controller for the [MAXXAIR Maxxfan](https://www.maxxair.com/products/fans/maxxfan-deluxe/).

* No more squeaking motor! Replace your fan's original brushed motor with a quieter low maintenance brushless motor.
* Install Minuet with simple hand tools: it is a complete drop-in replacement that does not require making any irreversible modifications so you can easily revert back to the original equipment later if you want.
* Control your fan using your phone, Home Assistant, the built-in keypad, a wired Maxxfan wall controller, and/or the Maxxfan IR remote.
* Set the thermostat to automatically run the fan at your chosen temperature setpoint, fan speed, and direction.
* Customize the [ESPHome](https://esphome.io/) configuration to add new features that better meet your needs.
* Connect lights to your fan with the [Minuet Light Accessory board](hardware/light/design-and-errata.md).
* Use the safety lock feature to disable operation when a vent fan cover is installed or while driving.
* Connect your own environmental sensors and accessories to Minuet's [QWIIC](https://www.sparkfun.com/qwiic) I2C port and GPIO expansion port.
* The hardware and software is open source: help make it better and share your improvements with others.

## Author's note and project status

As the author of Minuet, I want to give you a sense of what to expect from this project now and in the near future.

Minuet is currently in active development. After further testing and refinement of the prototypes, I plan to make a hardware kit available for sale in low volume including the circuit board, cables, and BLDC fan motor. Because the hardware and software is open source, you can also assemble your own kit from scratch and customize the design to your liking (although I suggest reviewing the published errata in detail and waiting for a production-ready revision to be proven out).

Here's a brief history of the project's development.

- [v1](hardware/minuet/v1/design-and-errata.md) proved out the basic operation of the BLDC fan motor, lid motor, built-in keypad, and integration with Home Assistant, while omitting non-essential functions for simplicity. I used an off-the-shelf BLDC fan motor, made adapters to mount it in the fan housing, hand-assembled the PCB, and installed the components in my van. It worked! This revision encouraged me to polish the design further and share it with others.

- [v2](hardware/minuet/v2/design-and-errata.md) achieved feature parity with the original Maxxfan control board. It added support for the an IR remote control, wire wall controls, rain sensor, thermistor, piezo buzzer for (polite and configurable) audible feedback, and had a more powerful BLDC fan motor driver. I implemented thermostat controls, designed an optional lighting accessory, and the fan really came to life!

- [v3](hardware/minuet/v3/design-and-errata.md) is the current revision, now in testing. It adds a safety lock feature and uses a different BLDC fan motor driver with field-oriented control with the goal of improving the acoustic performance of the fan. This revision takes a big step towards production readiness and can be fabricated by JLCPCB's PCBA service.

As a former software engineer, I have no prior experience designing open source hardware and delivering it to end-users so I'm figuring this out as I go along. If you have experience in these areas and would like to help develop the Minuet project, please consider joining the project as a contributor.

## Prototype in action

Here are some early videos of Minuet in action.

[Link to Minuet playlist on YouTube](https://www.youtube-nocookie.com/embed/videoseries?si=fa14cJ42dhqO0x0U&amp;list=PL8ZnNA3SFfE8v-qSholF0Ovc9Exv59-uN)

## Compatibility

Minuet v3 is anticipated to be compatible with the following Maxxfan models.

- Maxxfan Deluxe 7500K (verified)
- Maxxfan Deluxe 7000K (not yet tested)
- Maxxfan Deluxe 6200K (not yet tested)
- Maxxfan Deluxe 5100K (not yet tested)
- Maxxfan Plus 4500K (not yet tested)

Minuet might also work with other Maxxfan models that have similar electronics. Please contact the author if you would like to volunteer to help test Minuet with models that have yet to be tested.

## Getting started

Read these guides to learn how to build, install, and use Minuet.

1. [Hardware guide](docs/hardware-guide.md): All about Minuet's circuit board
1. [Fan motor guide](docs/fan-motor-guide.md): How to choose a brushless DC fan motor for Minuet, wire it up, and make adapters for installing it
1. [Setup guide](docs/setup-guide.md): How to configure Minuet for your motor, network, automation, and accessories
1. [Installation guide](docs/installation-guide.md): How to install Minuet into your Maxxfan
1. [User guide](docs/user-guide.md): How to use Minuet once it has been installed

Good luck and enjoy your fan!

## Acknowledgements

Thanks to [skypeachblue](https://github.com/skypeachblue) and [wingspinner](https://github.com/wingspinner) for publishing information about their [reverse engineering](https://github.com/skypeachblue/maxxfan-reversing) of the Maxxfan IR remote control protocol.  It helped me create the [esphome-maxxfan-protocol](https://github.com/j9brown/esphome-maxxfan-protocol) component for this project.

## Notice

The Minuet software, documentation, design, and all copyright protected artifacts are released under the terms of the [MIT license](LICENSE).

The Minuet hardware is released under the terms of the [CERN-OHL-W license](hardware/LICENSE).
