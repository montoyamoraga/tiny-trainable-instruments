# Instrument0

## About

The instrument0 is based on the k-NN algorithm.

k-NN stands for k-nearest neighbors.

The instrument0 gathers data from its sensors, uses it to train the k-NN algorithm, and then allows you to control audiovisuals.

This instrument currently uses k-NN for classification, not regression.

The instrument can run on batteries and only needs the computer to upload the code to it.

All the training happens on the instrument, and it can be easily retrained by turning on and off the microcontroller.

## Bill of materials

* Necessary:
  * 1x microcontroller, Arduino Nano 33 BLE Sense
  * 1x Micro USB cable
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

Follow the instructions on [installation.md]

## Wiring

Follow the instructions on [wiring.md]

## Code

### inst0Blink

Upload this sketch to check that your Arduino is working correctly.

This sketch cycles between all the different LED lights available on the microcontroller.

### inst0GyroscopeMidi

Upload this sketch to control the pitch of a piezo buzzer with your gyroscope.

### inst0GyroscopeMidi

Upload this sketch to control a MIDI instrument with your gyroscope.

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
