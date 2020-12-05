// inst0GyroscopeBuzzer
// knn + gyroscope + Buzzer
// v0.0.2
// november 2020

// code by aaron montoya-moraga
// part of tiny trainable instruments
// with assistance by peter tone

// this code is based on examples on the Arduino KNN library

// technology
// programmed using arduino ide 1.8.13
// on a macbook air with macos catalina 10.15.7
// for an arduino nano 33 ble sense

// this sketch records 3 positions
// and emits different frequencies
// to control a connected piezo buzzer

// when training the arduino changes the color of the lights
// in order red, green, blue, one for each category
// and then after training it signals with the corresponding color

// tip:
// if you are having trouble uploading the sketch,
// press fast twice the reset button on the arduino

#include "TinyTrainable.h"

// include Arduino KNN library
#include <Arduino_KNN.h>

// include Arduino library for IMU sensor
// more information at
// https://www.arduino.cc/en/Reference/ArduinoLSM9DS1
#include <Arduino_LSM9DS1.h>

// include Arduino library for proximity sensor
// more information at
// https://www.arduino.cc/en/Reference/ArduinoAPDS9960
#include <Arduino_APDS9960.h>

// variables being measured
const int INPUTS = 3;

// number of objects to classify
const int CLASSES = 3;

// number of examples per object
const int EXAMPLES_PER_CLASS = 10;

const int K = 5;

// this boolean is for turning on/off 
// the output of KNN classes via hardware (pins of the Arduino)
boolean outputHardware = true;

// this boolean is for turning on/off 
// the output of KNN classes via USB Serial port
boolean outputUSB = false;

// this boolean is for turning on/off 
// the output of debugging messages USB Serial port
boolean outputDebug = false;

int previousClassification = -1;

// instance of instrument0
TinyTrainable myTinyTrainable();

// Create a new KNNClassifier
KNNClassifier myKNN(INPUTS);

// Names for each class (object type)
String label[CLASSES] = {"Up", "Down", "Sideways"};

// Array to store data to pass to the KNN library
float inertia[INPUTS];

// frequencies for buzzer
int drumNotes[3] = {100, 250, 450};

const int buzzerPin = 9;

void setup() {

  if (outputDebug) {
    Serial.begin(9600);
    while (!Serial);
  }

  pinMode(buzzerPin, OUTPUT);

  if (outputHardware) {
    setupSerial1();
  }
  
  myTinyTrainable.setupBuiltInLED();

  if (!APDS.begin()) {
    while (1);
  }

  if (!IMU.begin()) {
    while (1);
  }

  if (outputDebug) {
    Serial.println("myInstrumentZero");
  }


  // Ask user for the name of each object
  for (int currentClass = 0; currentClass < CLASSES; currentClass++) {

    myInstrumentZero.setColorBuiltInLED(currentClass);

    // Ask user to show examples of each object
    for (int currentExample = 0; currentExample < EXAMPLES_PER_CLASS; currentExample++) {

      if (outputDebug) {
        Serial.print("Show me an example ");
        Serial.println(label[currentClass]);
      }

      // Wait for an object then read its inertia
      readInertia(inertia);

      // Add current inertia to the k-NN model
      myKNN.addExample(inertia, currentClass);
    }
    // Wait for the object to move away again
    while (!APDS.proximityAvailable() || APDS.readProximity() == 0) {}
  }
}

void loop() {

  int classification;

  // Wait for the object to move away again
  while (!APDS.proximityAvailable() || APDS.readProximity() == 0) {}

  if (outputDebug) {
    Serial.println("Let me guess your object");
  }

  // Wait for an object then read its inertia
  readInertia(inertia);

  // Classify the object
  classification = myKNN.classify(inertia, K);

  // Print the classification
  if (outputDebug) {
    Serial.print("classification: ");
    Serial.println(label[classification]);
  }

  myTinyTrainable.setColorBuiltInLED(classification);

  if (classification != previousClassification) {
    tone(buzzerPin, drumNotes[classification], 100);
    previousClassification = classification;
  }

}

void readInertia(float inertia[]) {
  float inertiaX, inertiaY, inertiaZ, proximity, inertiaTotal = 0.0;

  // Wait for the object to move close
  while (!APDS.proximityAvailable() || APDS.readProximity() > 0) {}

  // Sample if color is available and object is close
  while (!IMU.accelerationAvailable());

  // Read color and proximity
  IMU.readAcceleration(inertiaX, inertiaY, inertiaZ);
  inertiaTotal = (inertiaX + inertiaY + inertiaZ);

  inertia[0] = inertiaX;
  inertia[1] = inertiaY;
  inertia[2] = inertiaZ;

  if (outputDebug) {
    Serial.println(inertiaTotal);
    Serial.print(inertia[0]);
    Serial.print(",");
    Serial.print(inertia[1]);
    Serial.print(",");
    Serial.println(inertia[2]);
  }

}

void setupSerial1() {
  Serial1.begin(9600);

  // desired baudrate
  uint32_t baudrate = 0x800000;

  // pointer to the memory address that stores the baudrate
  uint32_t *pointerBaudrate = ( uint32_t * )0x40002524;

  // replace the value at the pointer with the desired baudrate
  *pointerBaudrate = baudrate;
}
