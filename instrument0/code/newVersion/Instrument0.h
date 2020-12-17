#ifndef Instrument0_h
#define Instrument0_h

// TODO explain on docs/ why some .h files are imported with "" and others with <>
// #include "Arduino.h"

#include "TinyTrainableInstrument.h"

// include Arduino KNN library
#include <Arduino_KNN.h>

// TODO fix the input things and classes (3)

// TODO explain this
enum OutputMode {usb, midiOut, pin};

// here is where we say that Instrument0 is a subclass of TinyTrainableInstrument
class Instrument0 : public TinyTrainableInstrument
{
  public:
    Instrument0(bool serialDebugging);
    //        Instrument0(bool serialDebugging, byte midiChannelHex, byte midiVelocity, int midiNote1, int midiNote2, int midiNote3);
    //        Instrument0(bool serialDebugging, int outputPin, long noteDuration, int noteFreq1, int noteFreq2, int noteFreq3);

        template <typename T> void debugPrint(T message) {
          if (_serialDebugging) {
            Serial.println(message);
          }
        };
    //    void setLabels(String object1, String object2, String object3);
    //    void trainKNN(int k, int examplesPerClass, float colorThreshold);
    //    void identify();
    void setupInstrument();
  private:
    
    //    void setupSerial1();
    //    void readColor(float color[]);
    //    void setColorBuiltInLED(int color);
    //    void midiCommand(byte cmd, byte data1, byte data2);

    //    byte _midiChannelHex;
    //    byte _midiVelocity;
    //    int _outputPin;
    //    long _noteDuration;
    //    int _notes[3];

    bool _serialDebugging;
    OutputMode _outputMode;
    KNNClassifier _myKNN;
    //    float _colorReading[3];
    //    int _k;
    //    String _label[3];
    //    int _previousClassification;
    //    float _colorThreshold;
};

#endif
