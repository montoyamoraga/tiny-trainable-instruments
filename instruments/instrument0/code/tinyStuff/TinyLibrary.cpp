#include "TinyLibrary.h"

TinyTrainable::TinyTrainable() {

}

void TinyTrainable::debugPrint() {
  Serial.begin(9600);
  while (!Serial);
  Serial.println("this a TinyTrainable");
}
