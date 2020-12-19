#ifndef inst0_h
#define inst0_h

// installed libraries included with <>
#include <Arduino.h>
#include <Arduino_KNN.h>

// local libraries included with ""
#include "TinyLibrary.h"

// rather than using numbers to represent the different output modes, using 
// an enum makes the code more readable in if and switch statements
enum OutputMode {usbOut, midiOut, pinOut};


// inheriting the class TinyTrainable as public
class Inst0 : public TinyTrainable
{
  public:
    Inst0(bool serialDebugging);

    //    Instrument0(bool serialDebugging, byte midiChannelHex, byte midiVelocity, int midiNote1, int midiNote2, int midiNote3);
    //    Instrument0(bool serialDebugging, int outputPin, long noteDuration, int noteFreq1, int noteFreq2, int noteFreq3);
    
    void setupInstrument();
    void setLabels(String object1, String object2, String object3);
    void trainKNN(int k, int examplesPerClass, float colorThreshold);
    void identify();
  private:
    void readColor(float color[]);

    OutputMode _outputMode;
    KNNClassifier _myKNN;
    //    long _noteDuration;
    //    int _notes[3];
    int _previousClassification;
    String _labels[3];
    int _k;
    float _colorThreshold;
    float _colorReading[3];
};

#endif
