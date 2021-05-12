# TinyTrainable

## About

Though we don't expect an instance of the parent library TinyTrainable to be of much use on its own, documentation is included here in case users wish to fork and edit the library themselves.

## Documentation

### LEDs

The microcontroller we are using has 3 LEDs:

* Power LED: color green, it is always on.
* Built-in LED: color orange
* RGB LED: it has 3 channels, red, green and blue. It can output 6 different colors: red, green, blue, yellow, magenta, cyan.

We use the orange built-in LED for signalling if the instruments have been trained or not. When they are turned on, the LED is on, after the algorithm is trained, it blinks twice, and then goes off.
