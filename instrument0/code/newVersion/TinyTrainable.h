#ifndef TinyTrainable_h
#define TinyTrainable_h

// TODO explain on docs/ why some .h files are imported with "" and others with <>
#include "Arduino.h"

// include Arduino KNN library
#include <Arduino_KNN.h>

// TODO fix the input things and classes (3)

// this instrument has 3 modes of output
// usb is information sent over USB cable on serial protocol
// midiOut is hardware MIDI over pins
// pin controls a buzzer
enum OutputMode {usb, midiOut, pin};

class TinyTrainable
{
  public:
    TinyTrainable(bool serialDebugging);
    //        TinyTrainable(bool serialDebugging, byte midiChannelHex, byte midiVelocity, int midiNote1, int midiNote2, int midiNote3);
    //        TinyTrainable(bool serialDebugging, int outputPin, long noteDuration, int noteFreq1, int noteFreq2, int noteFreq3);

    // this is c++ technique for declaring this debugging function
    // to accept all the possible datatypes
    // TODO: explain this better
    template <typename T> void debugPrint(T message) {
      if (_serialDebugging) {
        Serial.println(message);
      }
    };

    //    void setLabels(String object1, String object2, String object3);
    //    void trainKNN(int k, int examplesPerClass, float colorThreshold);
    //    void identify();
  private:

    // private methods

    // initializes the variables and opens connections
    void setupInstrument();

    //    void setupSerial1();
    //    void readColor(float color[]);
    //    void setColorBuiltInLED(int color);
    //    void midiCommand(byte cmd, byte data1, byte data2);

    // private variables

    // boolean for serial debugging
    bool _serialDebugging;

    // current output mode of the instrument
    OutputMode _outputMode;

    // instance of KNN classifier
    KNNClassifier _myKNN;

    // integer variable for previous classification of KNN
    int _previousClassification;

    //    byte _midiChannelHex;
    //    byte _midiVelocity;
    //    int _outputPin;
    //    long _noteDuration;
    //    int _notes[3];

    //    float _colorReading[3];
    //    int _k;
    //    String _label[3];

    //    float _colorThreshold;
};

#endif
