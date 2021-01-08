# Tiny Trainable Instrument

## About

Though we don't expect an instance of the parent library Tiny Trainable to be of much use on its own, documentation is included here in case users wish to fork and edit the library themselves.

## Documentation

### Public
`TinyTrainable();`

`template <typename T> void debugPrint(T message);`

`static void setupLED();`

`void setColorBuiltInLED(Colors color);`

`void turnOffBuiltInLED();`

`void setupSerial1();`

`void midiCommand(byte midiNote);`

### Protected

`bool _serialDebugging;`

`byte _midiChannelDec;`

`byte _midiVelocity;`

`int _outputPin;`
