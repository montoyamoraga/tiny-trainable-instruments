// inst0Blink
// blinking lights
// v0.0.1
// november 2020

// code by aaron montoya-moraga
// part of tiny trainable instruments
// with assistance by peter tone

// this code is based on the Blink example
// http://www.arduino.cc/en/Tutorial/Blink

// technology
// programmed using arduino ide 1.8.13
// on a macbook air with macos catalina 10.15.7
// for an arduino nano 33 ble sense

// this sketch cycles through all the lights
// on the arduino nano 33 ble sense

int timeOn = 500;
int timeOff = 250;

void setup() {
  // initialize digital pins as outputs
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDB, OUTPUT);

  // turn off the RGB LEDs
  digitalWrite(LEDR, HIGH);
  digitalWrite(LEDG, HIGH);
  digitalWrite(LEDB, HIGH);
}

void loop() {

  //  turn on and off the pull-up orange LED
  digitalWrite(LED_BUILTIN, HIGH);
  delay(timeOn);
  digitalWrite(LED_BUILTIN, LOW);
  delay(timeOff);

  // turn on and off the pull-down red, green, blue LEDs

  digitalWrite(LEDR, LOW);
  delay(timeOn);
  digitalWrite(LEDR, HIGH);
  delay(timeOff);

  digitalWrite(LEDG, LOW);
  delay(timeOn);
  digitalWrite(LEDG, HIGH);
  delay(timeOff);

  digitalWrite(LEDB, LOW);
  delay(timeOn);
  digitalWrite(LEDB, HIGH);
  delay(timeOff);

  // turn on and off the pull-down red, green, blue LEDs
  // now combined to form different colors

  // red + green = yellow
  digitalWrite(LEDR, LOW);
  digitalWrite(LEDG, LOW);
  delay(timeOn);
  digitalWrite(LEDR, HIGH);
  digitalWrite(LEDG, HIGH);
  delay(timeOff);

  // red + blue = magenta
  digitalWrite(LEDB, LOW);
  digitalWrite(LEDR, LOW);
  delay(timeOn);
  digitalWrite(LEDB, HIGH);
  digitalWrite(LEDR, HIGH);
  delay(timeOff);

  // green + blue = cyan
  digitalWrite(LEDG, LOW);
  digitalWrite(LEDB, LOW);
  delay(timeOn);
  digitalWrite(LEDG, HIGH);
  digitalWrite(LEDB, HIGH);
  delay(timeOff);
}
