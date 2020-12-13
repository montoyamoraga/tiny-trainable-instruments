#include "Arduino.h"
#include "TinyTrainable.h"

TinyTrainable myInst(true);
// TinyTrainable myInst(true, 0x99, 127, 38, 39, 42);
// TinyTrainable myInst(true, 9, 100, 250, 450);

void setup() {
    myInst.debugPrint("Arduino k-NN color classifier");
    myInst.setLabels("Object 1", "Object 2", "Object 3");
    myInst.trainKNN(5, 10, 0.5);
}

void loop() {
    myInst.identify();
}
