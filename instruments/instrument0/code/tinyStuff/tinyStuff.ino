// local libraries included with ""
#include "TinyLibrary.h"
#include "Inst0.h"
#include "Inst1.h"

TinyTrainable myTiny;
Inst0 myInst0(true);
Inst1 myInst1;

void setup() {
  // put your setup code here, to run once:

  myInst0.setupInstrument();  // moved to top of setup because it sets up Serial
  myInst0.debugPrint("instrument 0");

  myTiny.debugPrint("tiny trainable");

  myInst1.debugPrint("instrument 1");
  myInst1.print1();
}

void loop() {
  // put your main code here, to run repeatedly:

}
