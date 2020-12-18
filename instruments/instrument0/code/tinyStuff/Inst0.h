#ifndef inst0_h
#define inst0_h

// installed libraries included with <>
#include <Arduino.h>
#include <Arduino_KNN.h>

// local libraries included with ""
#include "TinyLibrary.h"

// rather than using numbers to represent the different output modes, using 
// an enum makes the code more readable in if or switch statements
enum OutputMode {usbOut, midiOut, pinOut};


// inheriting the class TinyTrainable as public
class Inst0 : public TinyTrainable
{
  public:
    Inst0(bool serialDebugging);
    
    void setupInstrument();
  private:
    OutputMode _outputMode;
    KNNClassifier _myKNN;
};

#endif
