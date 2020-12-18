// installed libraries included with <>
// include Arduino library for proximity sensor
// more information at
// https://www.arduino.cc/en/Reference/ArduinoAPDS9960
#include <Arduino_APDS9960.h>

// local libraries included with ""
#include "Inst0.h"

// constructor for the Inst0 class, using USB serial output
// if 'serialDebugging' is true, debugPrint() statements will be printed over Serial
Inst0::Inst0(bool serialDebugging) : _myKNN(3)
{
  _serialDebugging = serialDebugging;
  _outputMode = usbOut;
}

// sets up Serial
void Inst0::setupInstrument() {
  if (_serialDebugging || _outputMode == usbOut) {
    Serial.begin(9600);
    while (!Serial);
  }
}
