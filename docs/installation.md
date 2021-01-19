# Installation

We will be using the Arduino Nano BLE 33 Sense microcontroller for this project.

## Arduino Dependencies

First, download the Arduino Desktop IDE, available at[https://www.arduino.cc/en/software](https://www.arduino.cc/en/software). Select the stable release corresponding to the operating system of the computer you are using.

Now we need to install the core and necessary libraries for the Arduino Nano 33 BLE Sense. Open the Arduino IDE and navigate to `Tools => Board: "board_name" => Boards Manager...`, then search for `Arduino nRF528x mbed Core`. It is a large download, and it might take a few minutes to install.

Next, go to `Tools > Manage Libraries...` and install the custom library for this project, called `TinyTrainable`. This installation will give you the option to also install its dependencies, select `Install all` to additionally download these six following libraries:

* Libraries for using the embedded sensors of our microcontroller:
    * `Arduino_APDS9960`: color, proximity
    * `Arduino_HTS221`: temperature, humidity)
    * `Arduino_LPS22HB`: pressure
    * `Arduino_LSM9DS1` acceleration, magnetic field, gyroscope orientation
* Libraries for machine learning:
    * `Arduino_KNN`: k-nearest neighbor algorithm.
    * `Arduino_TensorFlowLite`: microcontroller version of the TensorFlow machine learning library. As of January 2021, there are 5 different versions of the library available to be installed from the Arduino IDE, which are:
      * 1.14.0-ALPHA
      * 1.15.0-ALPHA
      * 1.15.0-ALPHA-precompiled
      * 2.1.0-ALPHA
      * 2.1.0-ALPHA-precompiled
      We suggest installing the latest 2.1.0 but not precompiled, which would be: 2.1.0-ALPHA.


If you still have questions about setting up the microcontroller, the full startup guide is available [here](https://www.arduino.cc/en/Guide/NANO33BLESense).

If you've made it this far, welcome to our project! We're super happy to have you here :)

## Python and TensorFlow

For Instrument0, you only need Arduino libraries. For Instrument1 and Instrument2, you also need to have Python and TensorFlow installed on your computer.

Your computer might have Python already installed, and it might be one that is not compatible with the TensorFlow version we are using.

In order to be able to manage different versions of Python, we suggest installing the tool pyenv https://github.com/pyenv/pyenv.


### Linux

### Mac


## Windows
