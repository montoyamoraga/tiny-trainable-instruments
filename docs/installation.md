# Installation

We will be using the Arduino Nano BLE 33 Sense microcontroller for this project.

## Arduino dependencies

First, download the Arduino Desktop IDE, available at [https://www.arduino.cc/en/software](https://www.arduino.cc/en/software). Select the stable release corresponding to your computer's operating system.

Now we need to install the core and necessary libraries for the Arduino Nano 33 BLE Sense. Open the Arduino IDE and navigate to `Tools => Board: "board_name" => Boards Manager...`, then search for `Arduino nRF528x mbed Core`. It is a large download, and it might take a few minutes to install.

Next, go to `Tools > Manage Libraries...` and install the custom library for this project, called `TinyTrainable`. This installation will give you the option to also install its dependencies, select `Install all` to additionally download these six following libraries:

* Libraries for using the embedded sensors of our microcontroller:
    * `Arduino_APDS9960`: color, proximity
    * `Arduino_HTS221`: temperature, humidity
    * `Arduino_LPS22HB`: pressure
    * `Arduino_LSM9DS1` acceleration, magnetic field, gyroscope orientation
* Libraries for machine learning:
    * `Arduino_KNN`: k-nearest neighbor algorithm.
    * `Arduino_TensorFlowLite`: microcontroller version of the TensorFlow machine learning library. Please download the latest non-precompiled version.


If you still have questions about setting up the microcontroller, the full startup guide is available [here](https://www.arduino.cc/en/Guide/NANO33BLESense).

If you've made it this far, welcome to our project! We're super glad to have you here :)

## TensorFlow, Python, Jupyter

For Instrument0, you only need Arduino libraries. For Instrument1 and Instrument2, you also need to have Python, in order to train with TensorFlow and Jupyter on your computer.

Your computer might have Python already installed, and it might be one that is not compatible with the TensorFlow version we are using.

These are the versions we will be using, as of January 2021:

* Python 3.8.6
* TensorFlow 2.3.2
* Jupyter Lab 3.0.5

In order to be able to manage different versions of Python, we suggest installing the tool pyenv https://github.com/pyenv/pyenv.

After installing pyenv, go to the folder instruments/

```bash
cd instruments/
```

Check that pyenv is able to read the .python-version file

```bash
pyenv versions
```

You should see a list, with the version we are using and an asterisk, to highlight that this is the Python version we will use.

Create a virtual environment called env, with the python package venv.

```bash
python -m venv env
```

Activate this virtual environment

```bash
source env/bin/activate
```

Now your terminal should have every new line starting with (env)

The pip of your Python virtual environment might need updating, you can update to the latest version with this command

```bash
pip install --upgrade pip
```

Use pip to install the Jupyter packages, along with their dependencies, with the command

```bash
pip install -r requirements.txt
```

Now you can run the Jupyter Lab tool with

```bash
jupyter-lab
```

This will open a tab on your browser to navigate through the files in your computer, and let you run the code in the Jupyter notebooks for Instrument1 and Instrument2, which have extension .ipynb
