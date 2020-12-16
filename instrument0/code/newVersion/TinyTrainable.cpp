#include "Arduino.h"
#include "TinyTrainable.h"

// include Arduino KNN library
#include <Arduino_KNN.h>

// include Arduino library for proximity sensor
// more information at
// https://www.arduino.cc/en/Reference/ArduinoAPDS9960
#include <Arduino_APDS9960.h>

// constructor mode for the instrument
// the only parameter is a boolean to turn on / off serial debugging
// myKNN(3) is a initializer list for instancing a KNN classifier with 3 inputs
TinyTrainable::TinyTrainable(bool serialDebugging) : _myKNN(3)
{
  // set the serialDebugging
  _serialDebugging = serialDebugging;
  
  // default output is usb
  _outputMode = usb;
  
  //    setupInstrument();
}

//TinyTrainable::TinyTrainable(bool serialDebugging, byte midiChannelHex, byte midiVelocity, int midiNote1, int midiNote2, int midiNote3)  : _myKNN(3)
//{
//    _serialDebugging = serialDebugging;
//    _outputMode = midiOut;
//    _midiChannelHex = midiChannelHex;
//    _midiVelocity = midiVelocity;
//    _notes[0] = midiNote1;
//    _notes[1] = midiNote2;
//    _notes[2] = midiNote3;
//    setupInstrument();
//    setupSerial1();
//}
//
//TinyTrainable::TinyTrainable(bool serialDebugging, int outputPin, long noteDuration, int noteFreq1, int noteFreq2, int noteFreq3)  : _myKNN(3)
//{
//    _serialDebugging = serialDebugging;
//    _outputMode = pin;
//    _outputPin = outputPin;
//    _noteDuration = noteDuration;
//    _notes[0] = noteFreq1;
//    _notes[1] = noteFreq2;
//    _notes[2] = noteFreq3;
//    setupInstrument();
//}


void TinyTrainable::setupInstrument() {
  // open the usb serial port if we are debugging or if the output mode is usb
  if (_serialDebugging || _outputMode == usb) {
    Serial.begin(9600);
    while (!Serial);
  }

  // turn on the sensor
  if (!APDS.begin()) {
    while (1);
  }

  // set the pins on output mode
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDB, OUTPUT);

  // start with everything off
  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(LEDR, HIGH);
  digitalWrite(LEDG, HIGH);
  digitalWrite(LEDB, HIGH);

  // initialie previous classification to -1
  _previousClassification = -1;
}

//void TinyTrainable::setupSerial1() {
//  Serial1.begin(9600);
//
//  // desired baudrate
//  uint32_t baudrate = 0x800000;
//
//  // pointer to the memory address that stores the baudrate
//  uint32_t *pointerBaudrate = ( uint32_t * )0x40002524;
//
//  // replace the value at the pointer with the desired baudrate
//  *pointerBaudrate = baudrate;
//}
//
//void TinyTrainable::setLabels(String object1, String object2, String object3) {
//  _label[0] = object1;
//  _label[1] = object2;
//  _label[2] = object3;
//}

//void TinyTrainable::trainKNN(int k, int examplesPerClass, float colorThreshold) {
//  _k = k;
//  _colorThreshold = colorThreshold;
//
//  for (int currentClass = 0; currentClass < 3; currentClass++) {
//
//    setColorBuiltInLED(currentClass);
//
//    // Ask user to show examples of each object
//    for (int currentExample = 0; currentExample < examplesPerClass; currentExample++) {
//
//      debugPrint("Show me an example of:");
//      debugPrint(_label[currentClass]);
//
//      // Wait for an object then read its color
//      readColor(_colorReading);
//
//      // Add example color to the k-NN model
//      _myKNN.addExample(_colorReading, currentClass);
//    }
//    // Wait for the object to move away again
//    while (!APDS.proximityAvailable() || APDS.readProximity() == 0) {}
//  }
//}

//void TinyTrainable::setColorBuiltInLED(int color) {
//  // turn everything off
//  digitalWrite(LEDR, HIGH);
//  digitalWrite(LEDG, HIGH);
//  digitalWrite(LEDB, HIGH);
//
//  if (color == 0) {
//    digitalWrite(LEDR, LOW);
//  } else if (color == 1) {
//    digitalWrite(LEDG, LOW);
//  } else if (color == 2) {
//    digitalWrite(LEDB, LOW);
//  }
//}

//void TinyTrainable::identify() {
//  // Wait for the object to move away again
//  while (!APDS.proximityAvailable() || APDS.readProximity() == 0) {}
//
//  debugPrint("Let me guess your object");
//
//  // Wait for an object then read its color
//  readColor(_colorReading);
//
//  // Classify the object
//  int classification = _myKNN.classify(_colorReading, _k);
//
//  debugPrint("You showed me:");
//  debugPrint(_label[classification]);
//
//  setColorBuiltInLED(classification);
//
//  if (classification != _previousClassification) {
//    switch (_outputMode) {
//      case usb:
//        debugPrint(classification);
//        break;
//      case midiOut:
//        midiCommand(_midiChannelHex, _notes[classification], _midiVelocity);
//        break;
//      case pin:
//        tone(_outputPin, _notes[classification], _noteDuration);
//        break;
//    }
//
//    _previousClassification = classification;
//  }
//}

//void TinyTrainable::readColor(float colorReading[]) {
//  int red, green, blue, proximity, colorTotal = 0;
//
//  // Wait for the object to move close
//  while (!APDS.proximityAvailable() || APDS.readProximity() > 0) {}
//
//  // Wait until we have a color bright enough
//  while (colorTotal < _colorThreshold) {
//    // Sample if color is available and object is close
//    if (APDS.colorAvailable()) {
//
//      // Read color and proximity
//      APDS.readColor(red, green, blue);
//      colorTotal = (red + green + blue);
//
//      _colorReading[0] = red;
//      _colorReading[1] = green;
//      _colorReading[2] = blue;
//
//      debugPrint(colorTotal);
//      debugPrint(_colorReading[0]);
//      debugPrint(", ");
//      debugPrint(_colorReading[1]);
//      debugPrint(", ");
//      debugPrint(_colorReading[2]);
//      debugPrint("\n");
//    }
//  }
//}

// send 3 byte midi message
//void TinyTrainable::midiCommand(byte cmd, byte data1, byte data2) {
//  Serial1.write(cmd);
//  Serial1.write(data1);
//  Serial1.write(data2);
//}
