# Instrument0

## About

Instrument0 is an instrument that uses its sensors for measuring gestures, color, light intensity and proximity, to train a k-NN (k-nearest neighbors) algorithm. This allows you to control different multimedia outputs.

The instrument can be programmed with a computer and then run as a standalone instrument, or you can use its serial port to communicate with your computer for debugging or interfacing with other software.

All the training happens on the instrument, and it can be easily retrained by restarting it (press the button once).

## Bill of materials

* Required:
  * 1x [Arduino Nano 33 BLE Sense](https://store.arduino.cc/usa/nano-33-ble-sense)
  * 1x Micro USB to USB cable
  * 1x USB power supply or battery
  * 1x computer with the Arduino IDE installed, for uploading the code to the microcontroller
* Optional:
  * 1x solderless breadboard
  * 10x breadboard jumper cables
  * 1x piezo buzzer
  * 1x 220 Ohm resistor
  * 1x audiovisual instrument with MIDI input
  * 1x MIDI DIN cable
  * 1x MIDI breadboard jack

## Installation

Follow the instructions on [installation.md](installation.md)

## Wiring

Follow the instructions on [wiring.md](wiring.md)

## Code examples

(inst0_blink?) hello_tiny_world: Cycles through all the LEDs and their colors.

inst0_(pin?)_buzzer: Outputs sounds using a buzzer.

## Documentation
