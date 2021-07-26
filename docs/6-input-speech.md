# input-speech

## About

input-speech is an instrument that uses its microphone for recognizing voice commands, to train a neural network built with the Google TensorFlow library. This allows you to control different multimedia outputs.

The instrument can be programmed with a computer and then run as a standalone instrument, or you can use its serial port to communicate with your computer for debugging or interfacing with other software.

## Installation

Follow the instructions on [installation.md](installation.md).

## Wiring

Follow the instructions on [wiring.md](wiring.md).

## Code examples

hello_tiny_world: this is an example that cycles through all the LEDs and their colors.

## Data collection

Record .wav files with this format:

* 1 audio channel (mono)
* 16 kHZ sample rate
* 16 bits per sample: 16 bits

## Training

Open your terminal and go to the instruments folder.

```bash
cd instruments
```

Activate the virtual environment

```bash
source env/bin/activate
```

Run Jupyter lab

```bash
jupyter-lab
```

Open the window on your web browser, and navigate to the gesture notebook.

## Deploying

Open the Arduino sketch
