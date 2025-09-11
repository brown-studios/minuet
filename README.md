# Minuet fan controller

Minuet upgrades your [MAXXAIR Maxxfan](https://www.maxxair.com/products/fans/maxxfan-deluxe/) with a brushless DC motor, home automation features, and accessories.

Improve your quality of life in your campervan, RV, trailer, or truck!

* Replace your fan's original motor with a quieter brushless motor. No more cleaning squeaky motor brushes!
* Install Minuet with simple hand tools. You can revert back to the original equipment later if you want.
* Connect your fan to your home automation system if you have one. Works with your original infrared remote control and wired wall controls too.
* Install the light accessory to add a ring of lights to your fan for illumination and ambiance.
* Install the cover sensor accessory to stop the fan and turn off the lights automatically when you attach an insulated vent cover.
* Enjoy a more polished user experience with enhanced thermostat controls and less beeping.
* Customize your fan as you like because the firmware and hardware are open source!
  * Expand the [ESPHome](https://esphome.io/)-based [firmware](https://github.com/brown-studios/minuet-firmware).
  * Connect off-the-shelf I2C environmental sensors and devices to the [QWIIC](https://www.sparkfun.com/qwiic) port.
  * Make your own hardware accessories for the EXPANSION port.
  * Share your work with the community!

## Get to know Minuet

Watch Minuet in action and follow along with how it was made with these videos:

* [Minuet showcase](https://vimeo.com/showcase/11857354)
* [Minuet build log](https://vimeo.com/showcase/11858950)

## Project status

Minuet is in active development.

The latest prototype is feature complete, works well, and is being tested by a few volunteers.

Our next tasks are finalizing the design, working with manufacturers to fabricate kits with everything you will need to upgrade your Maxxfan, and planning for order fulfillment.  We are also investigating the possibility of manufacturing custom brushless fan motors that will fit into the fan housing with fewer adapters.  Please contact us if you would like to contribute your manufacturing experience to this project.

Watch this space for updates on our progress.  We're thrilled by your interest in Minuet and we look forward to offering you a great upgrade for your Maxxfan!

See [project history](./docs/project-history.md) for the story of how we got here.

## Author's note

Hey folks, I'm Jeff!

I started building my campervan in 2023 after some delightful adventures in New Zealand.  Like many of you, I installed a Maxxfan in my campervan because it was the most popular fan for van builders.  It worked well for a while but less than a year after I installed it, the fan started making some awful squeaking noises.  I tried the usual advice: clean the motor brushes, replace the bearings, run the motor on high for a day, and nothing helped for long.  I tried to ignore the problem.

When the winter rainy season arrived and interrupted my van build, I started the squeaking fan again.  I had already started designing a circuit board to synchronize the Maxxfan with my home automation system and I found it tedious to work around the existing logic of the Maxxfan circuit board.  It occurred to me that it might be easier to design my own controller from scratch... and then I could use a brushless fan motor and solve my fan squeaking problem too!

So here we are.  I've made several prototypes, enjoyed the quiet, added quality of life features, made some friends, and learned a lot along the way.  I'm satisfied with how Minuet has improved my comfort and I hope you'll like it too.

## Getting started

Read these guides to learn how to build, install, and use Minuet and its accessories.

1. [Hardware guide](docs/hardware-guide.md): How to build Minuet hardware.
1. [Installation guide](docs/installation-guide.md): How to install Minuet into your Maxxfan.
1. [User guide](docs/user-guide.md): How to use Minuet.

Good luck and enjoy your fan!

## Compatibility

Minuet is anticipated to be compatible with the following Maxxfan models.

- Maxxfan Deluxe 7500K (verified)
- Maxxfan Deluxe 7000K (not yet tested)
- Maxxfan Deluxe 6200K (not yet tested)
- Maxxfan Deluxe 5100K (not yet tested)
- Maxxfan Plus 4500K (not yet tested)

Minuet may work with other Maxxfan models that have similar electronics.

## Acknowledgements

Thanks to [skypeachblue](https://github.com/skypeachblue) and [wingspinner](https://github.com/wingspinner) for publishing information about their [reverse engineering](https://github.com/skypeachblue/maxxfan-reversing) of the Maxxfan IR remote control protocol.  It helped me create the [esphome-maxxfan-protocol](https://github.com/brown-studios/esphome-maxxfan-protocol) component for this project.

## Notice

The Minuet software, documentation, design, and all copyright protected artifacts are released under the terms of the [MIT license](LICENSE).

The Minuet hardware is released under the terms of the [CERN-OHL-W license](hardware/LICENSE).
