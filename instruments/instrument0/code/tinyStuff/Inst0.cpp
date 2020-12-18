#include "Inst0.h"

Inst0::Inst0() {
  
}

void Inst0::print0() {
  Serial.begin(9600);
  while (!Serial);
  Serial.println("this a Inst0");
}
