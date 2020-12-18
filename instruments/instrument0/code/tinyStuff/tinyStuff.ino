#include "TinyLibrary.h"
#include "Inst0.h"
#include "Inst1.h"

TinyTrainable myTiny;
Inst0 myInst0;
Inst1 myInst1;

void setup() {
  // put your setup code here, to run once:

  myTiny.debugPrint();

  myInst0.debugPrint();
  myInst0.print0();

  myInst1.debugPrint();
  myInst1.print1();

}

void loop() {
  // put your main code here, to run repeatedly:

}
