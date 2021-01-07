# Software

Notes about software development

## Files

TODO: explain difference between .h .cpp and .ino files

## Including libraries

TODO: explain difference between these two lines

```cpp
#include <Arduino.h>
#include "Arduino.h"
```

## Data structures

```cpp
// using a template datatype allows debugPrint to take in any datatype, like 
// Serial.println(). it needs to be defined here in the header file so it 
// compiles before anything else, since it's called in the Inst0.cpp file
template <typename T> void debugPrint(T message) {
      if (_serialDebugging) {
        Serial.println(message);
      }
    };

```
