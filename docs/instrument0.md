# tiny-trainable instruments / instrument0

## About

The instrument0 is based on the k-NN algorithm.

k-NN stands for K-nearest neighbors.

The instrument0 gathers data from its sensors, uses it to train the k-NN algorithm, and then allows you to control audiovisuals.

This instrument currently uses k-NN for classification, not regression.

The instrument can run on batteries and only needs the computer to upload the code to it.

All the training happens on the instrument, and it can be easily retrained by turning on and off the microcontroller.

## Bill of materials

* Necessary:
  * 1x microcontroller, Arduino Nano 33 BLE Sense
  * 1x Micro USB cable
  * 1x USB power supply or battery
  * 1x computer for uploading the code to the microcontroller
* Optional:
  * 1x solderless breadboard
  * 10x breadboard jumper cables
  * 1x piezo buzzer
  * 1x 220 Ohm resistor
  * 1x audiovisual instrument with MIDI input
  * 1x MIDI DIN cable
  * 1x MIDI breadboard jack

## Software

* Download the Arduino IDE to your computer
* Install the neccesary drivers for the Arduino Nano 33 BLE Sense, more info here [https://www.arduino.cc/en/Guide/NANO33BLESense]()

## Code

### inst0Blink

Upload this sketch to check that your Arduino is working correctly.

This sketch cycles between all the different LED lights available on the microcontroller.

### inst0GyroscopeMidi

Upload this sketch to control the pitch of a piezo buzzer with your gyroscope.

### inst0GyroscopeMidi

Upload this sketch to control a MIDI instrument with your gyroscope.
