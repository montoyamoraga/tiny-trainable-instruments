// TinyTrainable.h - a library for Tiny Trainable Instruments
// code by aaron montoya-moraga
// with assistance by peter tone
// for Arduino Nano 33 BLE Sense
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

// TODO fix the input things and classes (3)

enum OutputMode {usb, midi, pin};

class TinyTrainable {
  public:

    TinyTrainable(bool serialDebugging);
    TinyTrainable(bool serialDebugging, byte midiChannelHex, byte midiVelocity, int midiNote1, int midiNote2, int midiNote3);
    TinyTrainable(bool serialDebugging, int outputPin, long noteDuration, int noteFreq1, int noteFreq2, int noteFreq3);

    template <typename T> void debugPrint(T message) {
      if (_serialDebugging) {
        Serial.println(message);
      }
    };

    void setLabels(String object1, String object2, String object3);
    void trainKNN(int k, int examplesPerClass, float colorThreshold);
    void identify();

  private:

    void setupInstrument();
    void setupSerial1();
    void readColor(float color[]);
    void setColorBuiltInLED(int color);
    void midiCommand(byte cmd, byte data1, byte data2);

    byte _midiChannelHex;
    byte _midiVelocity;
    int _outputPin;
    long _noteDuration;
    int _notes[3];

    bool _serialDebugging;
    OutputMode _outputMode;
    KNNClassifier _myKNN;
    float _colorReading[3];
    // K number for KNN classifier
    int _k;
    String _label[3];
    int _previousClassification;
    float _colorThreshold;








    // integer to choose what type of instrument is it
    int _number;
    // integer to choose how many inputs to the KNN algorithm
    int _inputs;
    // float array to store data to pass to the KNN library
    // TODO: make the length of _inertia be dependent on inputs
    float _inertia[3];
    // KNN classifier TODO: make the length of _inertia be dependent on inputs
    KNNClassifier _myKNN;
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
