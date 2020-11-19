// instrument0
// v0.0.1
// november 2020

// code by aaron montoya-moraga
// for thesis tiny trainable instruments
// with assistance by peter tone
// based on examples on the Arduino KNN library

// technology
// programmed using arduino ide 1.8.13
// on a macbook air with macos catalina 10.15.7
// for an arduino nano 33 ble sense

// include Arduino KNN library
#include <Arduino_KNN.h>

// include Arduino library for IMU sensor
// more information at
// https://www.arduino.cc/en/Reference/ArduinoLSM9DS1
#include <Arduino_LSM9DS1.h>

// parameters for KNN model
// inputs: acceleration in x, y, z
const int inputs = 3;
// classes: movement in x, y, z
const int classes = 3;
// number of examples per class
const int examples = 30;
// k parameter for the classifier
const int k = 5;

// declare KNN classifier
KNNClassifier myKNN(inputs);

// names of each class
String label[classes] = {"movX", "movY", "movZ"};

// array to store data to pass to the KNN classifier
float acceleration[3];

// threshold for movement
const float threshold = 1.0;

// MIDI notes for drum machine
// 38 snare drum
// 39 hand clap
// 42 closed hihat
int drumNotes[3] = {38, 39, 42};

int ledTimeOn = 500;
int ledTimeOff = 500;

void setup() {

  // start serial communication on pins A0 and A1
  Serial1.begin(9600);

  // desired baudrate
  uint32_t baudrate = 0x800000;

  // pointer to the memory address that stores the baudrate
  uint32_t *pointerBaudrate = ( uint32_t * )0x40002524;

  // replace the value at the pointer with the desired baudrate
  *pointerBaudrate = baudrate;

  // setup built in LED
  setupBuiltInLED();

  // go through every class
  for (int currentClass = 0; currentClass < classes; currentClass++) {

    // wait one second before doing next class
    setColorBuiltInLED(currentClass);

    // get examples for every class
    for (int currentExample = 0; currentExample < examples; currentExample++) {

      // read from sensor
      readAcceleration(acceleration);

      // add acceleration as example to KNN
      myKNN.addExample(acceleration, currentClass);
    }

  }

}


void loop() {

  // new variable
  int classification;

  // read acceleration
  readAcceleration(acceleration);

  // classify
  classification = myKNN.classify(acceleration, k);

  // 0x99 is hexadecimal for 153 decimal
  // 153 is note on channel 10, 49 is crash cymbal, 127 is velocity
  midiCommand(0x99, drumNotes[classification], 127);
  delay(1000);
}

// send 3 byte midi message
void midiCommand(byte cmd, byte data1, byte data2) {
  Serial1.write(cmd);
  Serial1.write(data1);
  Serial1.write(data2);
}

void readAcceleration(float acceleration[]) {
  float accelerationX = 0.0;
  float accelerationY = 0.0;
  float accelerationZ = 0.0;
  float accelerationTotal = 0.0;

  // wait until we have a acceleration bigger than the threshold
  while (accelerationTotal < threshold) {

    // wait until the next acceleration data is available
    while (!IMU.accelerationAvailable());

    // read acceleration data
    IMU.readAcceleration(accelerationX, accelerationY, accelerationZ);
    accelerationTotal = (accelerationX + accelerationY + accelerationZ);
  }

  // normalize the sample data and put it in the classifier:
  acceleration[0] = (float) accelerationX / accelerationTotal;
  acceleration[1] = (float) accelerationY / accelerationTotal;
  acceleration[2] = (float) accelerationZ / accelerationTotal;

}


void setupBuiltInLED() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDB, OUTPUT);

  // start with everything off
  digitalWrite(LEDR, HIGH);
  digitalWrite(LEDG, HIGH);
  digitalWrite(LEDB, HIGH);

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
