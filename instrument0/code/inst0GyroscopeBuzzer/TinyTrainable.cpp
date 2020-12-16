#include <Arduino.h>
#include <Arduino_KNN.h>
#include "TinyTrainable.h"

// constructor function
// peter proposed the syntax for this constructor
// where the myKNN is initialized here
// TODO: add docs for what initialization lists are
TinyTrainable::TinyTrainable(int number, int inputs, int K): _myKNN(3)  {
  _number = number;
  _inputs = inputs;
  _K = K;
  //  _myKNN.KNNClassifier(3);
}

void TinyTrainable::setupSerial() {
  Serial.begin(9600);
  while (!Serial);
}

void TinyTrainable::setupSerial1() {
  Serial1.begin(9600);

  // desired baudrate
  uint32_t baudrate = 0x800000;

  // pointer to the memory address that stores the baudrate
  uint32_t *pointerBaudrate = ( uint32_t * )0x40002524;

  // replace the value at the pointer with the desired baudrate
  *pointerBaudrate = baudrate;
}

void TinyTrainable::setupBuiltInLED() {
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

void TinyTrainable::setColorBuiltInLED(int color) {
  // turn everything off
  digitalWrite(LEDR, HIGH);
  digitalWrite(LEDG, HIGH);
  digitalWrite(LEDB, HIGH);

  // 0 red
  if (color == 0) {
    digitalWrite(LEDR, LOW);
  }
  // 1 green
  else if (color == 1) {
    digitalWrite(LEDG, LOW);
  }
  // 2 blue
  else if (color == 2) {
    digitalWrite(LEDB, LOW);
  }
  // 3 yellow = red + green
  else if (color == 3) {
    digitalWrite(LEDR, LOW);
    digitalWrite(LEDG, LOW);
  }
  // 4 magenta = red + blue
  else if (color == 4) {
    digitalWrite(LEDR, LOW);
    digitalWrite(LEDB, LOW);
  }
  // 5 cyan = green + blue
  else if (color == 5 ) {
    digitalWrite(LEDG, LOW);
    digitalWrite(LEDB, LOW);
  }
}

void TinyTrainable::readInertia() {
  float inertiaX, inertiaY, inertiaZ, proximity, inertiaTotal = 0.0;

  // Wait for the object to move close
  while (!APDS.proximityAvailable() || APDS.readProximity() > 0) {}

  // Sample if color is available and object is close
  while (!IMU.accelerationAvailable());

  // Read color and proximity
  IMU.readAcceleration(inertiaX, inertiaY, inertiaZ);
  inertiaTotal = (inertiaX + inertiaY + inertiaZ);

  _inertia[0] = inertiaX;
  _inertia[1] = inertiaY;
  _inertia[2] = inertiaZ;

  if (_outputDebug) {
    Serial.println(inertiaTotal);
    Serial.print(_inertia[0]);
    Serial.print(",");
    Serial.print(_inertia[1]);
    Serial.print(",");
    Serial.println(_inertia[2]);
  }
}

void TinyTrainable::addNewExample(int currentClass) {
  _myKNN.addExample(_inertia, currentClass);
}

int TinyTrainable::classifyInput() {
  // TODO: why does this line not work :(
  //  return _myKNN.classify(_inertia, _K);
  return 0;
}
