# CCORE-Arduino
Arduino support for CCORE A5 series MCUs. 

A simple implementation of Arduino 3rd party hardware spec. View https://github.com/arduino/Arduino/wiki/Arduino-IDE-1.5-3rd-party-Hardware-specification for details.

* Must work with bootloader https://github.com/djytw/CCORE-A5-bootloader. Flash the bootloader first with official ccore ide.

* Then extract mcore-elf-* toolchain from official IDE, and put them here.

* Supports normal compile & flash function in Arduino IDE, when connect DTS and reset with a 1μF capacitor
