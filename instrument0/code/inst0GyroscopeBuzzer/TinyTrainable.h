// TinyTrainable.h - a library for Tiny Trainable Instruments
// code by aaron montoya-moraga
// with assistance by peter tone
// for Arduino Nano 33 BLE Sense
// programmed using Arduino IDE 1.8.13
// on a Macbook Air with MacOS Catalina 10.15.7
// started in november 2020
// MIT License

// tip:
// if you are having trouble uploading the sketch,
// press fast twice the reset button on the arduino

#ifndef TinyTrainable_h
#define TinyTrainable_h

// include library dependencies
#include "Arduino.h"

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

class TinyTrainable {
  public:
    TinyTrainable(int number, int inputs, int K);
    void setupSerial();
    void setupSerial1();
    void setupBuiltInLED();
    void setColorBuiltInLED(int color);
    void readInertia();
    void addNewExample(int currentClass);
    int classifyInput();

  private:
    // integer to choose what type of instrument is it
    int _number;
    // integer to choose how many inputs to the KNN algorithm
    int _inputs;
    // float array to store data to pass to the KNN library
    // TODO: make the length of _inertia be dependent on inputs
    float _inertia[3];
    // KNN classifier TODO: make the length of _inertia be dependent on inputs
    KNNClassifier _myKNN(3);
    // K number for KNN classifier
    int _K;
    // integer for current class
    int _currentClass;
    // this boolean is for turning on/off
    // the output of KNN classes via hardware (pins of the Arduino)
    boolean _outputHardware = true;
    // this boolean is for turning on/off
    // the output of KNN classes via USB Serial port
    boolean _outputUSB = false;
    // this boolean is for turning on/off
    // the output of debugging messages USB Serial port
    boolean _outputDebug = false;
};

#endif
