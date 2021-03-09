# Installation

This project is based on the Arduino Nano BLE 33 Sense microcontroller.

## Arduino dependencies

First, download the Arduino Desktop IDE, available at [https://www.arduino.cc/en/software](https://www.arduino.cc/en/software). Select the stable release corresponding to your computer's operating system.

Now we need to install the core and necessary libraries for the Arduino Nano 33 BLE Sense. Open the Arduino IDE and navigate to `Tools => Board: "board_name" => Boards Manager...`, then search for `Arduino nRF528x mbed Core`. It is a large download, and it might take a few minutes to install.

Next, go to `Tools > Manage Libraries...` and install the custom library for this project, called `TinyTrainable`. This installation will give you the option to also install its dependencies, select `Install all` to additionally download these libraries:

* Libraries for using the embedded sensors of our microcontroller:
    * `Arduino_APDS9960`: color, proximity
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

After installing pyenv, on the terminal go to this repository

```bash
cd tiny-trainable-instruments/
```

Check that pyenv is able to read the .python-version file

```bash
pyenv versions
```

You should see a list, with the version we are using and an asterisk, to highlight that this is the Python version we will use. If there is no asterisk and it says that the required version of python is not installed, use the command

```bash
pyenv install <python version number>
```

If you are using an old version of pyenv, there's a chance that the install won't work; copy the entire command pyenv gives you (including the &&'s) and enter it into the terminal. Then once pyenv is updated, try the above command again.

Now that you have the correct version of Python, create a virtual environment (which we will name env) using the Python package venv. Most dependency problems can be solved by using a virtualenv; we can’t support issues not using a virtualenv due to the huge variety of system configurations.

```bash
python -m venv env
```

Activate the virtual environment with this command, which you will use every time you want to enter the venv:

```bash
source env/bin/activate
```

Now your terminal should have every new line starting with (env). Your command prompt should look something like this:

![Virtual environment command prompt](https://github.com/montoyamoraga/tiny-trainable-instruments/blob/main/docs/images/venv-activation.png "Activating virtual environment")

The pip of your Python virtual environment might need updating; you can update to the latest version with the command

```bash
pip install --upgrade pip
```

Then use pip to install the Jupyter packages, along with their dependencies:

```bash
pip install -r requirements.txt
```

Now you can run the Jupyter Lab tool with `jupyter-lab`. This will open a tab on your browser to navigate through the files in your computer and allow you run code and read the documentation.

The code for Instrument1 and Instrument 2 is written using Jupyter notebooks, which have the extension .ipynb, and are located on the folder instruments/.

The documentation is written in several Markdown files with extension .md. These files are on the folder docs/, which includes an index on README.md.

If you double click on a Markdown file, it will open an Editor window with the Markdown code. To view the rendered text you can right click and select "Open with Markdown Preview".

If you have internet connection, it might be more convenient to access the online documentation on the online repository.

To close the Jupyter notebook server, press `ctrl+c` in the terminal (even on OSX; it's not `cmd`) and confirm with `y`.

To exit the virtual environment once you're done, simply use the command `deactivate`. Note that the command `jupyter-lab` will not work until you reenter the venv.
