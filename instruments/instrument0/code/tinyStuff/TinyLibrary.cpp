// local libraries included with ""
#include "TinyLibrary.h"

// constructor for the TinyTrainable class
TinyTrainable::TinyTrainable()
{
  _serialDebugging = true;  // hardcoded for now
}

// sets up the LEDS on the Arduino Nano 33 BLE Sense
void TinyTrainable::setupLED()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDB, OUTPUT);

  // start with everything off
  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(LEDR, HIGH);
  digitalWrite(LEDG, HIGH);
  digitalWrite(LEDB, HIGH);
}

// TODO - note which pins
// sets up Serial1 (serial output over pins)
void TinyTrainable::setupSerial1() {
  Serial1.begin(9600);

  // desired baudrate
  uint32_t baudrate = 0x800000;

  // pointer to the memory address that stores the baudrate
  uint32_t *pointerBaudrate = ( uint32_t * )0x40002524;

  // replace the value at the pointer with the desired baudrate
  *pointerBaudrate = baudrate;
}

// sets the color of the built in LED on the Arduino Nano 33 BLE Sense
void TinyTrainable::setColorBuiltInLED(Colors color) {
  // turn everything off
  digitalWrite(LEDR, HIGH);
  digitalWrite(LEDG, HIGH);
  digitalWrite(LEDB, HIGH);

  if (color == red) {
    digitalWrite(LEDR, LOW);
  } else if (color == green) {
    digitalWrite(LEDG, LOW);
  } else if (color == blue) {
    digitalWrite(LEDB, LOW);
  }
}

// send 3 byte midi message over Serial1 (pins)
// 'midiNote' is the midi note number in decimal
// midi channel and note velocity are preset
void TinyTrainable::midiCommand(byte midiNote) {
  Serial1.write(_midiChannelDec);
  Serial1.write(midiNote);
  Serial1.write(_midiVelocity);
}
