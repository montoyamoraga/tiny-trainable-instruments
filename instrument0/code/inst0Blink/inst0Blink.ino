/*
  Built on example code from:
  http://www.arduino.cc/en/Tutorial/Blink
*/

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
