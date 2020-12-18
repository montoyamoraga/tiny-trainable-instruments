#ifndef _TINY_LIBRARY_H_
#define _TINY_LIBRARY_H_

// installed libraries included with <>
#include <Arduino.h>

class TinyTrainable {
  public:
    TinyTrainable();

    void setupInstrument();
    
    // using a template datatype allows debugPrint to take in any datatype, like 
    // Serial.println(). it needs to be defined here in the header file so it 
    // compiles before anything else, since it's called in the Inst0.cpp file
    template <typename T> void debugPrint(T message) {
      if (_serialDebugging) {
        Serial.println(message);
      }
    };
  protected:
    bool _serialDebugging;
};

#endif
