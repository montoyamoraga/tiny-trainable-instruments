# Instrument1

## About

Instrument1 is an instrument that uses its sensors for measuring gestures, to train a neural network built with the Google TensorFlow library. This allows you to control different multimedia outputs.

The instrument can be programmed with a computer and then run as a standalone instrument, or you can use its serial port to communicate with your computer for debugging or interfacing with other software.

Training Instrument1 is done in three steps:
* *Data collection*, where the Arduino takes in environmental input from its sensors and writes it as a .csv (spreadsheet) file, which is then copied over to your computer
* *Training*, where your computer analyzes the collected data and builds a model to interpret the data using machine learning
* *Deploying*, where the now-trained model is uploaded to the Arduino and executed!

## Installation

Follow the instructions on [installation.md](installation.md).

## Wiring

Follow the instructions on [wiring.md](wiring.md).

## Code examples

hello_tiny_world: this is an example that cycles through all the LEDs and their colors.

## Training

Open your terminal and go to the repository folder

```bash
cd tiny-trainable-instruments/
```

Activate the virtual environment


```bash
source env/bin/activate
```

Run Jupyter lab

```bash
jupyter-lab
```

Open the window on your web browser, and navigate to the notebook instrument1.ipynb. Then, simply execute the code blocks in order to train your model!

## Deploying

Open the Arduino sketch
