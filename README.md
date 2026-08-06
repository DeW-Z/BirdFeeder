# BirdFeeder

BirdFeeder is a DIY bullet feeder for progressive reloading presses. Bulk projectiles are placed into the hopper, where the rotating collator plate orients them and feeds them into a drop tube leading to the press.

The project was designed around commonly available hardware, a NEMA 17 stepper motor, 3D-printed components, and a custom motor-control PCB.

## Project Status

BirdFeeder currently has two controller options:

| Option              | Status               |
| ------------------- | -------------------- |
| Original Controller | Stable and supported |
| Smart Controller    | Active development   |
| Planetary Gearbox   | Beta testing         |
| NEMA 23 Version     | Beta testing         | 

## Original BirdFeeder Controller

The original controller is a simple through-hole PCB that can be assembled using commonly available components.

Its main functions include:

* Adjustable stepper-motor speed
* NEMA 17 motor control
* Break-beam stopping
* Automatic restart when the feed tube clears
* Compact mounting directly on the feeder
* Quiet operation
* Mechanical slipper clutch protection

The original PCB, firmware, print files, and supporting documentation are fully open-source.

PCB manufacturing files are included in the repository and can be uploaded to a board manufacturer such as JLCPCB. These services normally require ordering several boards at once.

I will continue bulk-ordering and selling individual bare PCBs for builders who do not need a full batch. However, I am no longer producing assembled controllers or complete kits based on the original PCB.

Original PCB listing:

https://www.etsy.com/listing/4429151678/bullet-feeder-9mm-bullet-loader

## Smart Controller

The BirdFeeder Smart Controller is the newer ready-to-use controller option.

It uses an ESP32-S3 and TMC2209 stepper driver to provide easier setup, improved diagnostics, software-adjustable motor control, and electronic jam detection.

Key features include:

* Local browser-based control
* No mobile app or cloud account required
* Home Wi-Fi or standalone operation
* Physical speed-control knob
* Browser-based speed control
* Break-beam stopping and automatic restart
* StallGuard jam detection
* Adjustable jam sensitivity
* Status and diagnostic information
* Wireless firmware updates
* USB Type-C power input with compatible USB-PD supplies
* Physical start, stop, and direction controls

The controller hosts its own web interface and can function without an active internet connection.

The Smart Controller is still under active development and is not yet open-source. Hardware and firmware files will remain private until the design is further developed and tested.

Complete kits will only be offered with the Smart Controller going forward. Stock may be limited because component and manufacturing costs have increased significantly due to tariffs.

Smart Controller documentation:

[Smart Controller README](Smart%20Controller/README.md)

Smart Controller listing:

https://www.etsy.com/listing/4504139794/bullet-feeder-smart-controller

## High-Torque Testing

The standard BirdFeeder uses a NEMA 17 stepper motor and is intended to run with a reasonable amount of material in the hopper.

Some users have reported motor stalls when loading the hopper with more than approximately 100 projectiles. The exact limit varies based on:

* Projectile weight
* Collator plate design
* Printed-part friction
* Motor current
* Power-supply voltage
* Assembly alignment
* Hopper loading
* Material and print quality

Two higher-torque options are currently being evaluated.

### Planetary Gearbox

A planetary gearbox version is included as an additional MakerWorld print profile.

The gearbox increases output torque while retaining the standard NEMA 17 motor. The tradeoff is reduced output speed, additional printed components, and more mechanical complexity.

This design is currently considered beta. Builders should expect that revisions may be made as more testing and feedback are received.

### NEMA 23 Version

A separate NEMA 23 configuration is also under development.

The larger motor is intended for applications where the standard NEMA 17 does not provide enough torque, including heavier projectile types or higher-capacity configurations.

The NEMA 23 version is also considered beta and is not yet the standard recommended build.

## Hopper Capacity and Printed-Part Safety

Do not use the hopper as long-term bulk storage.

Increasing motor torque does not increase the strength of the printed hopper, mount, housing, or supporting hardware. A gearbox or larger motor may keep the collator moving, but the printed structure still supports the full static and dynamic load.

A printed part may appear to support a heavy load initially and still deform or fail after being stressed for hours, days, or weeks. This is especially important with materials that are susceptible to creep, elevated temperatures, weak layer adhesion, or insufficient wall thickness.

Recommended practices:

* Avoid filling the hopper beyond what is needed for the current loading session.
* Refill the hopper in smaller batches.
* Do not leave a heavily loaded hopper sitting between sessions.
* Use a suitable material and print orientation.
* Use adequate walls, top and bottom layers, and infill.
* Inspect the hopper, mount, motor housing, and fasteners regularly.
* Stop using any part that shows cracking, deformation, loose inserts, or damaged mounting points.

The gearbox and NEMA 23 versions are intended to address torque-related stalls. They should not be interpreted as approval to place unlimited weight in the hopper.

## Files and Documentation

The repository includes:

* Original PCB manufacturing files
* Original controller firmware
* Wiring and assembly documentation
* Smart Controller documentation
* Supporting images and reference material

3D-printable files and print profiles are hosted on MakerWorld:

https://makerworld.com/en/models/1252671-bullet-feeder-reloading-assistant#profileId-1697707

## Open-Source Status

### Currently Open-Source

* Original BirdFeeder mechanical design
* Original controller PCB
* Original controller firmware
* Manufacturing files
* Assembly documentation

### Not Yet Open-Source

* Smart Controller PCB design
* Smart Controller production files
* Smart Controller firmware source

The Smart Controller remains under active development. Its source files may be released later, but no release date is currently being promised.

## Safety

BirdFeeder is a DIY project and should be treated as experimental equipment.

Always inspect wiring, printed parts, motors, power supplies, sensors, and mechanical components before use. Do not operate the system unattended. Stop operation immediately if you notice overheating, damaged wiring, unusual noises, binding, cracked printed parts, or repeated motor stalls.

The builder and user are responsible for verifying that their completed assembly is appropriate for their equipment and intended use.
