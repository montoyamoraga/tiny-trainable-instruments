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

//void Instrument0::setupSerial1() {
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

// send 3 byte midi message
//void Instrument0::midiCommand(byte cmd, byte data1, byte data2) {
//  Serial1.write(cmd);
//  Serial1.write(data1);
//  Serial1.write(data2);
//}
