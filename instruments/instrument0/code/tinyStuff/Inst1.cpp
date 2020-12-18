#include "Inst1.h"

Inst1::Inst1() {
  
}

void Inst1::print1() {
  Serial.begin(9600);
  while (!Serial);
  Serial.println("this a Inst1");
}
