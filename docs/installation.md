# Installation

We will be using the Arduino Nano BLE 33 Sense microcontroller for this project.

## Arduino Dependencies

First, download the Arduino Desktop IDE, available [here](https://www.arduino.cc/en/software). Select the stable release corresponding to your operating system.

Now we need to install the core and neccesary libraries for the Arduino Nano 33 BLE Sense. Open the IDE and navigate to `Tools > Board: "board_name" > Boards Manager...`, then search for `Arduino nRF528x mbed Core` (large download, may take a few minutes to install).

Next, go to `Tools > Manage Libraries...` and install these libraries (corresponding to the sensors we'll be using):

* `Arduino_APDS9960` (gestures, color, proximity)
* `Arduino_HTS221` (temperature, humidity)
* `Arduino_LPS22HB` (pressure)
* `Arduino_LSM9DS1` (acceleration, magnetic field, gyroscope orientation)

Finally, we need to install the custom library for the project! Install `TinyTrainable` and select `Install all` if it prompts you to download missing dependencies (`Arduino_KNN` and `Arduino_TensorFlowLite`).

If you still have questions about setting up the microcontroller, the full startup guide is available [here](https://www.arduino.cc/en/Guide/NANO33BLESense).

If you've made it this far, welcome to our little project! We're super happy to have you here :)
