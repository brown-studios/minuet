# Minuet fan controller

Minuet is a smart brushless DC motor controller for the [MAXXAIR Maxxfan Deluxe vent fan](https://www.maxxair.com/products/fans/maxxfan-deluxe/).

* No more squeaking motor! Replace your fan's original brushed motor with a quieter low maintenance brushless motor.
* Install Minuet with simple hand tools: it is a complete drop-in replacement that does not require making any irreversible modifications so you can easily revert back to the original equipment later if you want.
* Control your fan using your phone, Home Assistant, the built-in keypad, and/or a wired Maxxfan wall controller.
* Set the thermostat to automatically run the fan at your chosen temperature setpoint, fan speed, and direction.
* Customize the [ESPHome](https://esphome.io/) configuration to add new features that better meet your needs.
* Connect your own environmental sensors and peripherals to Minuet's built-in [QWIIC](https://www.sparkfun.com/qwiic) I2C port and GPIO expansion header.
* The hardware and software is open source: help make it better and share your improvements with others.

## Author's note and project status

**Minuet is in early development.  It is not ready for use by the general public yet.  You cannot buy the hardware pre-assembled; you have to make it yourself.  These statements will change as the project matures.**

As the author of Minuet, I want to give you a sense of what to expect from this project now and in the near future.

The first revision of the Minuet hardware is installed in my campervan and it works somewhat well.  I do not recommend building this revision of the hardware due to schematic errata noted in the accompanying documentation.  It is after all a prototype.

The second revision of the Minuet hardware will address the known errata and will use a different brushless motor driver chip to run a bigger motor with a higher current limit.  It will likely take further revisions to stabilize the design for production in quantity.

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

## Limitations

Minuet currently supports the following Maxxfan models.  Please contact the author if you would like to volunteer to help test Minuet with other models.

- Maxxfan Deluxe 7500K
- Maxxfan Deluxe 7000K

Minuet v2 supports Maxxfan wall controls with an 8P8C connector.

Minuet does not (yet) support IR remote controls.  Please contact the author if you would like to volunteer to develop the necessary circuitry and software to receive and decode IR signals from the remote control.

## Getting started

Read these guides to learn how to build, install, and use Minuet.

1. [Hardware guide](docs/hardware-guide.md): All about Minuet's custom circuit board
1. [Fan motor guide](docs/fan-motor-guide.md): How to choose a brushless DC fan motor for Minuet, wire it up, and make adapters for installing it
1. [Setup guide](docs/setup-guide.md): How to configure Minuet for your motor, network, automation, and peripherals
1. [Installation guide](docs/installation-guide.md): How to install Minuet into your Maxxfan
1. [User guide](docs/user-guide.md): How to use Minuet once it has been installed

Good luck and enjoy your fan!
