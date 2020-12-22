// import libraries
import processing.sound.*;
import processing.serial.*;

// declare instance of Serial
// a serial connection for reading and writing 
Serial myPort;

int myPortNumber = 0;

int myBaudRate = 9600;

// declare instance of integer
int myClass;

// declare instance of SinOsc
// a sine wave oscillator
SinOsc myOscillator;

int[] myFrequencies = {200, 400, 800};

void setup() {
  size(512, 512);
  background(255);

  myOscillator = new SinOsc(this);
  myOscillator.play();
  myOscillator.amp(1.0);
  
  printArray(Serial.list());
  
  String myPortName = Serial.list()[myPortNumber];
  
  myPort = new Serial(this, myPortName, myBaudRate);
  
}

void draw() {
  if (myPort.available() > 0) {
    myClass = myPort.read();
  }
  
  myOscillator.freq(myFrequencies[myClass]);
  
}
