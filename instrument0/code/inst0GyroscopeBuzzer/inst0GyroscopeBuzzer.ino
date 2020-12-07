// inst0GyroscopeBuzzer
// knn + gyroscope + Buzzer
// v0.0.2
// december 2020

// this code is based on examples on the Arduino KNN library

// this sketch records 3 positions
// and emits different frequencies
// to control a connected piezo buzzer

// when training the arduino changes the color of the lights
// in order red, green, blue, one for each category
// and then after training it signals with the corresponding color

#include "TinyTrainable.h"

// instance of TinyTrainable
// arguments are
// 0 for instrument type 0
// 3 for 3 inputs
// 5 for K
TinyTrainable myTinyTrainable(0, 3, 5);

// number of objects to classify
const int CLASSES = 3;

// number of examples per object
const int EXAMPLES_PER_CLASS = 10;

int previousClassification = -1;

// Create a new KNNClassifier
// KNNClassifier myKNN(3);

// Names for each class (object type)
String label[CLASSES] = {"Up", "Down", "Sideways"};

// frequencies for buzzer
int drumNotes[3] = {100, 250, 450};

const int buzzerPin = 9;

void setup() {

  pinMode(buzzerPin, OUTPUT);

  myTinyTrainable.setupSerial1();

  myTinyTrainable.setupBuiltInLED();

  if (!APDS.begin()) {
    while (1);
  }

  if (!IMU.begin()) {
    while (1);
  }

  // Ask user for the name of each object
  for (int currentClass = 0; currentClass < CLASSES; currentClass++) {

    myTinyTrainable.setColorBuiltInLED(currentClass);

    // Ask user to show examples of each object
    for (int currentExample = 0; currentExample < EXAMPLES_PER_CLASS; currentExample++) {

      // Wait for an object then read its inertia
      myTinyTrainable.readInertia();

      // Add current inertia to the k-NN model
      // myKNN.addExample(inertia, currentClass);
      myTinyTrainable.addNewExample(currentClass);
    }
    // Wait for the object to move away again
    while (!APDS.proximityAvailable() || APDS.readProximity() == 0) {}
  }
}

void loop() {

  int classification;

  // Wait for the object to move away again
  while (!APDS.proximityAvailable() || APDS.readProximity() == 0) {}

  // Wait for an object then read its inertia
  myTinyTrainable.readInertia();

  // Classify the object
  //  classification = myKNN.classify(myTinyTrainable._inertia, K);
  classification = myTinyTrainable.classifyInput();

  myTinyTrainable.setColorBuiltInLED(classification);

  if (classification != previousClassification) {
    tone(buzzerPin, drumNotes[classification], 100);
    previousClassification = classification;
  }

}
