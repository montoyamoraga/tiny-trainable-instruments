// inst0GyroscopeMidi
// knn + gyroscope + midi
// v0.0.1
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
// and emits different MIDI notes
// to control a Roland TR-09 drum machine
// on channel 10

// when training the arduino changes the color of the lights
// in order red, green, blue, one for each category
// and then after training it signals with the corresponding color

// tip:
// if you are having trouble uploading the sketch,
// press fast twice the reset button on the arduino


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

const int INPUTS = 3; // Classifier input is color sensor data; red, green and blue levels
const int CLASSES = 3; // Number of objects we will classify (e.g. Apple, Banana, Orange)
const int EXAMPLES_PER_CLASS = 10; // Number of times user needs to show examples for each object

const int K = 5;

boolean isPrintingConsole = false;

int previousClassification = -1;

// Create a new KNNClassifier
KNNClassifier myKNN(INPUTS);

// Names for each class (object type)
String label[CLASSES] = {"Up", "Down", "Sideways"};

// Array to store data to pass to the KNN library
float color[INPUTS];

// Threshold for color brightness
//const int THRESHOLD = 5;
const float THRESHOLD = 0.5;

// MIDI notes for drum machine
// 38 snare drum
// 39 hand clap
// 42 closed hihat
int drumNotes[3] = {38, 39, 42};

void setup() {

  if (isPrintingConsole) {
    Serial.begin(9600);
    while (!Serial);
  }

  setupSerial1();

  setupBuiltInLED();

  if (!APDS.begin()) {
    while (1);
  }

  if (!IMU.begin()) {
    while (1);
  }

  if (isPrintingConsole) {
    Serial.println("Arduino k-NN color classifier");
  }


  // Ask user for the name of each object
  for (int currentClass = 0; currentClass < CLASSES; currentClass++) {

    setColorBuiltInLED(currentClass);

    // Ask user to show examples of each object
    for (int currentExample = 0; currentExample < EXAMPLES_PER_CLASS; currentExample++) {

      if (isPrintingConsole) {
        Serial.print("Show me an example ");
        Serial.println(label[currentClass]);
      }

      // Wait for an object then read its color
      readColor(color);

      // Add example color to the k-NN model
      myKNN.addExample(color, currentClass);
    }
    // Wait for the object to move away again
    while (!APDS.proximityAvailable() || APDS.readProximity() == 0) {}
  }
}

void setColorBuiltInLED(int color) {

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
void loop() {

  int classification;

  // Wait for the object to move away again
  while (!APDS.proximityAvailable() || APDS.readProximity() == 0) {}

  if (isPrintingConsole) {
    Serial.println("Let me guess your object");
  }

  // Wait for an object then read its color
  readColor(color);

  // Classify the object
  classification = myKNN.classify(color, K);

  // Print the classification
  if (isPrintingConsole) {
    Serial.print("You showed me ");
    Serial.println(label[classification]);
  }

  setColorBuiltInLED(classification);

  if (classification != previousClassification) {
    midiCommand(0x99, drumNotes[classification], 127);
    previousClassification = classification;
  }

}

void readColor(float color[]) {
  //  int red, green, blue, proximity, colorTotal = 0;
  float red, green, blue, proximity, colorTotal = 0.0;

  // Wait for the object to move close
  while (!APDS.proximityAvailable() || APDS.readProximity() > 0) {}

  // Wait until we have a color bright enough
  //  while (colorTotal < THRESHOLD) {

  // Sample if color is available and object is close
  //    if (APDS.colorAvailable()) {
  while (!IMU.accelerationAvailable());
  //    if (IMU.accelerationAvailable()) {

  // Read color and proximity
  IMU.readAcceleration(red, green, blue);
  //      APDS.readColor(red, green, blue);
  colorTotal = (red + green + blue);

  color[0] = red;
  color[1] = green;
  color[2] = blue;


  if (isPrintingConsole) {
    Serial.println(colorTotal);
    // Print the red, green and blue percentage values
    Serial.print(color[0]);
    Serial.print(",");
    Serial.print(color[1]);
    Serial.print(",");
    Serial.println(color[2]);
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

void setupBuiltInLED() {
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

// send 3 byte midi message
void midiCommand(byte cmd, byte data1, byte data2) {
  Serial1.write(cmd);
  Serial1.write(data1);
  Serial1.write(data2);
}
