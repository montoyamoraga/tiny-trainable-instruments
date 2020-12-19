#ifndef _TINY_LIBRARY_H_
#define _TINY_LIBRARY_H_

// installed libraries included with <>
#include <Arduino.h>

// colors for setting the LED
enum Colors {red, green, blue};

class TinyTrainable {
  public:
    TinyTrainable();
    
    // using a template datatype allows debugPrint to take in any datatype, like 
    // Serial.println(). it needs to be defined here in the header file so it 
    // compiles before anything else, since it's called in the Inst0.cpp file
    template <typename T> void debugPrint(T message) {
      if (_serialDebugging) {
        Serial.println(message);
      }
    };

  protected:
    static void setupLED();
    // void setupSerial1();
    void setColorBuiltInLED(Colors color);
    //    void midiCommand(byte cmd, byte data1, byte data2);

    bool _serialDebugging;
    //    byte _midiChannelHex;
    //    byte _midiVelocity;
    //    int _outputPin;
};

#endif
