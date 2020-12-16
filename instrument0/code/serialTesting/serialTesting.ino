
char bytes[1024];

void setup()
{
  // start serial port at 9600 bps and wait for port to open:
  Serial.begin(9600);
}

void loop()
{
  int frequency = 5;

  //  Serial.println("0");
  Serial.write("3");

  delay(1000);
}
