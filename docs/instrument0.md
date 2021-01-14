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

## Code

### inst0Blink

Upload this sketch to check that your Arduino is working correctly.

This sketch cycles between all the different LED lights available on the microcontroller.

### inst0GyroscopeMidi

Upload this sketch to control the pitch of a piezo buzzer with your gyroscope.

### inst0GyroscopeMidi

Upload this sketch to control an external MIDI instrument with your gyroscope.

## Documentation

### Public

`enum OutputMode {usbOut, midiOut, pinOut}`

`Inst0();`

`void setupInstrument(OutputMode mode, bool serialDebugging);`

`void setupMidi(byte midiChannelDec, byte midiVelocity);`

`void setupPin(int outputPin, long noteDuration);`

`void setNotes(int note1, int note2, int note3);`

`void setLabels(String object1, String object2, String object3);`

`void trainKNN(int k, int examplesPerClass, float colorThreshold);`

`void identify();`

### Private

Note: Though you won't have access to these variables and methods as a normal user, the documentation is included here in case users wish to fork and edit the library themselves.

`void readColor(float color[]);`

`OutputMode _outputMode;`

`KNNClassifier _myKNN;`

`long _noteDuration;`

`int _notes[3];`

`int _previousClassification;`

`String _labels[3];`

`int _k;`

`float _colorThreshold;`

`float _colorReading[3];`
