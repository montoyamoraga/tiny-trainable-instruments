// local libraries included with ""
#include "TinyLibrary.h"
#include "Inst0.h"
#include "Inst1.h"

// constants for the KNN algorithm
int K = 5;  // algorithm will use the K nearest neighbors
int EXAMPLES_PER_CLASS = 10;  // # of examples to be collected for each object
float COLOR_THRESHOLD = 0.5;  // threshold for the color sensor

// instantiate the instruments
TinyTrainable myTiny;
// Inst0 myInst0(true);
Inst0 myInst0(true, 153, 127, 38, 38, 38);
Inst1 myInst1;

void setup() {
  // put your setup code here, to run once:

  myInst0.setupInstrument();  // moved to top of setup because it sets up Serial
  myInst0.debugPrint("instrument 0");

  myTiny.debugPrint("tiny trainable");

  myInst1.debugPrint("instrument 1");
  myInst1.print1();


  // using instrument 0
  myInst0.setLabels("Object 1", "Object 2", "Object 3");
  myInst0.trainKNN(K, EXAMPLES_PER_CLASS, COLOR_THRESHOLD);
}

void loop() {
  // put your main code here, to run repeatedly:
  myInst0.identify();
}
