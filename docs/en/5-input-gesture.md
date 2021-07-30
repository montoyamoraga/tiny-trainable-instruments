# input-gesture

## About

input-gesture is an instrument that uses its sensors for measuring gestures, to train a neural network built with the Google TensorFlow library. This allows you to control different multimedia outputs.

The instrument can be programmed with a computer and then run as a standalone instrument, or you can use its serial port to communicate with your computer for debugging or interfacing with other software.

Training input-gesture is done in three steps:

* *Data collection*, where the Arduino takes in environmental input from its sensors and writes it as a .csv (spreadsheet) file, which you then copy over to your computer.
* *Training*, where your computer analyzes the collected data and builds a model to interpret the data using machine learning
* *Deploying*, where you upload your newly-trained model to the Arduino and execute it!

## Installation

Follow the instructions on [installation.md](installation.md).

## Wiring

Follow the instructions on [wiring.md](wiring.md).

## Code examples

check_serial: cycles through all the LEDs and their colors.

gesture_buzzer: train with gestures, and then output over buzzer.

gesture_classifier: uploads your finished model to the Arduino for classifying gestures!

gesture_database: collects accelerometer data to prepare for training a model.

## Data collection

Open the Arduino IDE and select `File > Examples > TinyTrainable > gesture_database`, then execute the sketch. Open the serial monitor, which should list six values that the Arduino is measuring: a for (linear) acceleration, and g for gyroscope (angle). Hold the breadboard and perform one of three gestures, *with the end with the wire facing towards you*:

* Gesture 0: diagonal up-left
* Gesture 1: counterclockwise circle
* Gesture 2: thrust forwards

Note: There is a minimum acceleration threshold in order to prevent accidental inputs, so the gestures require a fairly quick motion.

You should see the serial monitor output a table of comma-separated values (csv). After recording the same gesture 10 times, copy the entire output from the serial monitor and replace the example data in te corresponding .csv file. Next, click ```Clear output``` in the serial monitor, single-press the button on the Arduino to reset the example, and repeat this procedure for the remaining gestures. After you're done recording the data, now it's time to train your model!

## Training

Open your terminal and go to the repository folder:

```bash
cd tiny-trainable-instruments/
```

Activate the virtual environment:

```bash
source env/bin/activate
```

Run Jupyter lab:

```bash
jupyter-lab
```

Now open the window on your web browser, and navigate to the notebook instrument1.ipynb. Then, simply execute the code blocks in order to train your model!

## Deploying

Open the Arduino sketch
