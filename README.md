# Minuet hardware

[Minuet](https://minuet.brownstudios.dev) upgrades your [MAXXAIR Maxxfan](https://www.maxxair.com/products/fans/maxxfan-deluxe/) with a brushless DC motor, home automation features, and accessories.

This repository contains the Minuet hardware design files.  You are welcome to modify the Minuet firmware and hardware subject to the [license terms](#notice) and we encourage you to make your own accessories.  We welcome your thoughtful contributions.

*Refer to the [Minuet website](https://minuet.brownstudios.dev) for documentation and project updates.*

*Refer to the [Minuet firmware repository](https://github.com/brown-studios/minuet-firmware) for the source code.*

## Project status

Please support this project by subscribing to our funding campaign at [CrowdSupply](https://www.crowdsupply.com/brown-studios/minuet) and by pre-ordering a Minuet upgrade kit once they become available. 💜

> [!IMPORTANT]
> Minuet is in active development and it is not yet ready for production.  There may still be bugs and some features may not work as intended.  We do not recommend assembling your own kit from scratch at this time.

## Printed circuit boards

### Design files

The [hardware](./hardware/) directory contains all of the Minuet printed circuit board designs.

Each board major revision resides in its own subdirectory and includes a [KiCad](https://www.kicad.org/) project, design document with errata, PDF plot of the schematics, and 3D renderings of the PCBs.  Refer to the `design-and-errata.md` for each board to learn how it's supposed work, how the design has evolved through each minor revision, what was learned from that revision, and workarounds for known issues.

- [Minuet fan controller v4 design and errata](./hardware/minuet/v4/design-and-errata.md)
- [Light accessory v4 design and errata](./hardware/light/v4/design-and-errata.md)
- [Environment accessory v4 design and errata](./hardware/environment/v4/design-and-errata.md)

> [!IMPORTANT]
> Always read the errata.

### Design guidelines

Here are a few guidelines to consider when contributing design files:

- Do not check in fabrication files because they're hard to keep in sync with the design files.
- Include links to datasheets for each chip in the KiCad symbols.
- Prefer two-layer or four-layer boards to keep the designs accessible for hobbyists.
- Prefer SMT parts no smaller than 0603 and keep the layout somewhat sparse to facilitate hand assembly.
- Place SMT parts on the front side of the board only.
- Place through-hole parts on either side as needed for mechanical reasons.
- Place prominent silk screen labels next to each connector and reference them consistently in the documentation.
- Assign net classes to nets that need special consideration when routing.
- Record test results and errata in the design document along the way.

### KiCad requirements

To edit the hardware projects, you will need the following:

- KiCad version 9.0 or newer
- KiCad add-ons installed using the Plugin and content manager
  - [Espressif Library](https://github.com/espressif/kicad-libraries): symbols and footprints
  - [JLCPCB Fabrication Toolkit](https://github.com/bennymeg/Fabrication-Toolkit): exports files for manufacturing

### Fabrication

Refer to each board's design document for specific fabrication notes.

This repository does not contain fabrication files (such as gerbers); you can generate them from the KiCad project in whatever format your fab needs.

The KiCad projects contain part numbers and placement information for the [JLCPCB](https://jlcpcb.com/) PCBA service.  Use the [Fabrication Toolkit](https://github.com/bennymeg/Fabrication-Toolkit) plugin for KiCad to generate the fabrication files for JLCPCB including the gerber files, bill of materials, and part positions.  Many of the parts in the design were selected to reduce fabrication cost at JLCPCB.  At the time of this writing, the MCF8316D motor driver chip had to be sourced from the global supply chain because it was not a regularly stocked item at JLCPCB.

If you're using a different PCBA service, you'll need to select equivalent parts.

Some of the SMT parts on the main circuit board have fine pitch QFN pads that are not accessible to a soldering iron.  You may need a solder stencil and reflow equipment to assemble these parts reliably.  You may find it more cost effective to have the factory assemble front-side SMT and through-hole parts and then install the remaining back-side through-hole parts by hand.

## Making your own accessories

Minuet's place in the middle of you vehicle's ceiling makes it a great platform for installing smart accessories.

- Attach many off-the-shelf [QWIIC](https://www.sparkfun.com/qwiic) compatible I2C peripherals to Minuet with just a wire.
- Use the light accessory as a break-out board for your own circuits and it includes a prototyping area for mounting through-hole components.
- Make your own circuit board that plugs into the `EXPANSION` port of the main fan controller board.

> [!TIP]
> We recommend choosing peripherals that are already supported by [ESPHome components](https://esphome.io/components/) to save time when customizing the [Minuet firmware](https://github.com/brown-studios/minuet-firmware) to support your accessory.

## Documentation

- [Assembly guide](./docs/assembly-guide.md)

## Development

This project uses [pre-commit](https://pre-commit.com/) for linting.

To install the git hooks:

```bash
uv run pre-commit install
```

To check all files:

```bash
uv run pre-commit run --all-files
```

## Contributing to Minuet

There's a lot you can do when you have control over your appliances and we welcome your thoughtful contributions.

Please use the Github issue tracker to suggest improvements to Minuet and consult the project maintainers for guidance before sending large pull requests.  We reserve the right to refuse contributions for any reason.

> [!IMPORTANT]
> We will not accept contributions that have been substantially produced with generative AI tools.  As an open-source project, we expect you to warrant that your contributions are your own work and that they comply with all applicable licenses.

## Notice

The Minuet software, documentation, design, and all copyright protected artifacts are released under the terms of the [MIT license](LICENSE).

The Minuet hardware is released under the terms of the [CERN-OHL-W license](hardware/LICENSE).
