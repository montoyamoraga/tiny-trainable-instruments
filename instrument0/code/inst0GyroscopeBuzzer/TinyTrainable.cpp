#include "Arduino.h"
#include "TinyTrainable.h"

// constructor function
TinyTrainable::TinyTrainable() {
  int x = 5;
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
