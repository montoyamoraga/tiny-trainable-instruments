# Installation

We will be using the Arduino Nano BLE 33 Sense microcontroller for this project.

## Arduino dependencies

First, download the Arduino Desktop IDE, available [here](https://www.arduino.cc/en/software). Select the stable release corresponding to your operating system.

Now we need to install the core and neccesary librares for the Arduino Nano 33 BLE Sense.
Open the IDE and navigate to `Tools > Board: "board_name" > Boards Manager...`, then search for `Arduino nRF528x mbed Core` (large download, may take a few minutes to install)

Next, go to `Tools > Manage Libraries...` and install these libraries (corresponding to the sensors we'll be using):

* `Arduino_APDS9960` (gestures, color, proximity)
* `Arduino_HTS221` (temperature, humidity)
* `Arduino_LPS22HB` (pressure)

If you still have questions about the NANO 33 BLE Sense, the full startup guide is available [here](https://www.arduino.cc/en/Guide/NANO33BLESense).

# TinyTrainable Arduino library

Finally, we need to install our own library for the project! Install `TinyTrainable` and select `Install all` if it prompts you to download missing dependencies. 

? To install the TinyTrainable Arduino library, download the latest release from [the repository](https://github.com/montoyamoraga/TinyTrainable).

## Debugging

* If your Arduino becomes unresponsive or you are having trouble uploading the code to it, quickly press the reset button twice on the Arduino.
