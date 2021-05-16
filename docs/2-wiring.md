# Wiring

## Conventions

Wires:
* Red = 3.3 V power from Arduino
* Green = Ground from Arduino

## Breadboard

Breadboards are built so that within each of the rows, the 5 tie points in the columns labelled "a-e" are electrically connected inside the board and act as a single electrical node, and same with f-j. In addition, there are two columns to each side of the breadboard; for a fullsize breadboard like we recommend, the top 25 tie points of each column are connected, and the bottom 25 tie points of each column are connected. Conventionally, we connect the positive terminal to the columns labelled `+`, and the ground to the columns labelled `-`.

A full breadboard guide is available at [https://learn.adafruit.com/breadboards-for-beginners/breadboards](https://learn.adafruit.com/breadboards-for-beginners/breadboards).

## Arduino microcontroller

The Nano BLE 33 Sense has 30 pins in total, 15 on each side. The official pinout is available at [https://content.arduino.cc/assets/Pinout-NANOsense_latest.pdf](https://content.arduino.cc/assets/Pinout-NANOsense_latest.pdf).

## Getting started

We recommend placing the microcontroller at the top of the breadboard (C1 to G15) with the USB Micro B port facing up, like this:

![Arduino placement](../docs/images/2-arduino-placement.png "Arduino on breadboard")

Note that the microcontroller should be flush with the breadboard; none of the headers should be visible!

![Arduino flush with breadboard](../docs/images/2-arduino-sideview.png "Arduino sideview")

This is all you need for the first example, hello_tiny_world! In theory, we didn't even need the breadboard, but it's good practice to put the Arduino on one so we're ready to add more connections. Now, connect it to your computer with the USB A to USB Micro B cable, load the example, and you should see the Arduino cycling its RGB LEDs!

## Outputs

### Buzzer

For the next example, inst0_buzzer, we'll need to install a piezo buzzer. First, notice that the 14th pin on the left side and the 12th pin on the right side are labelled with white paint; this marks the grounded leads, which are also identified on the pinout. Take a wire (preferably green or black, by convention for ground) and connect it from I12 to anywhere on the top righthand negative rail (the upper 25 pins), like so:

![Connecting the ground wire](../docs/images/2-ground-wire.png "Ground wire")

Next, connect one of the legs of the piezo buzzer to the node labelled D8 on the pinout (which should be row 5 on the breadboard). Connect the other leg to the ground rail. Your wiring should look like this:

![Installing the piezo buzzer](../docs/images/2-piezo-buzzer-placement.png "Piezo buzzer on breadboard")

Now you're good to go! Upload inst0_buzzer to the microcontroller, open the serial monitor (top right button in the Arduino IDE), and follow the instructions from there!

### LED

### MIDI

MIDI Din jack

5 pins, only 3 are used.

### Printer

We are using a thermal printer from Adafruit.

https://www.adafruit.com/product/2753

It has 5 cables:

VH - red - connect to the power supply 5V - 9V
DTR - yellow - connect to GND on the Arduino
TX - green - data out of the printer
RX - blue - data in to the printer
GND - black - connect to GND on the Arduino

We use a power supply, whose ground  is connected to the one on the Arduino.

The power supply is 9V, center positive.
Here is one available:
https://www.adafruit.com/product/276
