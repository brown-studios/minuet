# Minuet project history

Minuet has come a long way!

I started Minuet as a little rainy day project to save me from the madness of my squeaking Maxxfan motor and to learn about making consumer electronics.  The project has been successful on both counts!  And it's grown beyond my original goals to become a consumer product and not just a simple one-off build.

Here's a taste of how Minuet has evolved over time.

You might also be interested in the [Minuet build log](https://vimeo.com/showcase/11858950).

## November 2024: Early motivation

That month, it rained a lot and I had to pause my campervan build.  Eager to find something to do, I turned my attention to my Maxxfan.

I had been sketching out designs for a home automation interface that would plug into the Maxxfan's remote control ports.  It seemed like I could make some hardware to simulate key presses.  Several folks had made devices similar to this already and I wanted to experiment with passively scanning the keypad to monitor when the user pressed keys so that I could keep the home automation system in sync with manual actions on the fan keypad.  It was getting a bit complicated and I wasn't satisfied with the inherent limitations of that approach.

It was the squeaking that did it.  My Maxxfan fan motor made an awful squeaking noise while running.  Two or three times a second, squeak-squeak-squeak.  It drove me mad!  I had cleaned the motor a couple of times but the squeaking never went away for long.

It occurred to me that I could solve both problems at once with an ESP32 microcontroller and a brushless fan motor...

## December 2024: Minuet v1

I wasn't sure this idea was going to work so I tried to keep it simple.

The [Minuet v1 circuit board](https://github.com/brown-studios/minuet/blob/v2.x/hardware/minuet/v1/design-and-errata.md) proved out the basic operation of the BLDC fan motor, lid motor, built-in keypad, and integration with Home Assistant, while omitting non-essential functions like remote controls.

I initially used an off-the-shelf 15 W BLDC motor for the fan.  I made a laser cut aluminum adapter plate with standoffs to mount the motor into the Maxxfan fan housing and I added a shaft coupling and dowel to extend the shaft as required.  I tediously hand-assembled the PCB, programmed the ESPHome firmware, and bodged around hardware bugs.  And it worked great!

Now that I had solved my problem, I started telling people about Minuet on forums.  Lots of folks seemed to want one too and that encouraged me to continue iterating on the design.

Since I wanted to share my designs and I knew they weren't perfect, I recorded my errata alongside the hardware design files in case someone might try to build one themselves.  One thing that didn't work so well was the DRV10970 motor driver chip: it was underpowered and the quieter sinusoidal modulation didn't work properly when driving the motor in reverse.  So I iterated.

## January 2025: Minuet v2.0

Now that I had floated the idea of making kits, I decided to flesh out the Minuet feature set to meet the needs of more people.

The [Minuet v2.0 circuit board](https://github.com/brown-studios/minuet/blob/v2.x/hardware/minuet/v2/design-and-errata.md) achieved feature parity with the original Maxxfan control board. It added support for the an IR remote control, wire wall controls, rain sensor, thermostat, piezo buzzer for (polite and configurable) audible feedback, and had a more powerful BLDC fan motor driver.  The new MCT8315 motor driver chip really was significantly more powerful and I upgraded to a 50 W BLDC motor.  For fun, I included a little easter egg for the audible feedback (can you find it?).

The [Light and load accessory v2 circuit board](https://github.com/brown-studios/minuet/blob/v2.x/hardware/load/design-and-errata.md) added lights to the fan.  It was designed to control two independent or one addressable LED strip with voltage selection jumpers.  Unfortunately, there were hardware issues and it couldn't drive the data line fast enough for the addressable LED strip.  I decided to scrap this design and focus only on lighting for the next version.

Now that Minuet was feature complete, the fan really came to life!  (With some bugs...)

## February 2025: Minuet v2.1

The next version was an incremental improvement.

The [Minuet v2.1 circuit board](https://github.com/j9brown/minuet/blob/v2.x/hardware/light/v2/design-and-errata.md) upgraded the MCT8315 motor driver chip to MCT8316 that could handle twice the current and it fixed a bunch of hardware bugs.

The [Light accessory v2.5 circuit board](https://github.com/j9brown/minuet/blob/v2.x/hardware/light/v2/design-and-errata.md) superseded the earlier light and load accessory to only focus on driving a PWM or addressable LED light.  This much simpler design worked much better and finally I could make rainbow colors dance around my fan.

Minuet v2.1 worked very well except that the motor wasn't operating as quietly as I liked.  It didn't squeak but it make a soft ticking sound due to uneven torque produced by trapezoidal commutation.  I felt that I needed to solve this problem if I was going to claim that Minuet really was a quiet fan upgrade.

## May 2025: Minuet v3.0 (current release)

Minuet v3 is a big step towards making a real product that can be manufactured and continues improving beyond the feature set of the original Maxxfan.  This is the first version of Minuet to be fabricated with JLCPCB's PCBA service (no more tedious hand-soldering).

The [Minuet v3 circuit board](../hardware/minuet/v3/design-and-errata.md) uses a MCF8316D fan motor driver with field-oriented control that makes the fan motor run much quieter than before.  It solves the commutation noise problem and it no longer needs hall effect sensors so a wider range of motors can be used.  The expansion port has been expanded with more GPIO pins for accessories.  The new safety lock feature stops the fan and shuts off the light when engaged.

The [Light accessory v3 circuit board](../hardware/light/v3/design-and-errata.md) is an incremental upgrade to the previous light accessory for the new expansion port and it added a small through-hole prototyping area for customization.

The cover sensor accessory detects that an insulated vent cover has been attached using a normally-open reed switch attached to the safety lock port.  It is very convenient!

Overall, Minuet v3.0 is approaching the quality of a finished product.

## What comes next

Our next tasks are finalizing the design, working with manufacturers to fabricate kits with everything you will need to upgrade your Maxxfan, and planning for order fulfillment.  We are also investigating the possibility of manufacturing custom brushless fan motors that will fit into the fan housing with fewer adapters.

Please contact us if you would like to contribute your manufacturing experience to this project.
