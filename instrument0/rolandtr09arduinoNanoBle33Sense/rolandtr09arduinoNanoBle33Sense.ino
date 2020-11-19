// instrument0
// v0.0.1
// november 2020

// code by aaron montoya-moraga
// for thesis tiny trainable instruments
// with assistance by peter tone

// technology
// programmed using arduino ide 1.8.13
// on a macbook air with macos catalina 10.15.7
// for an arduino nano 33 ble sense

// MIDI notes
int drumNotes[3] = {37, 39, 42};

void setup() {

  // start serial communication on pins A0 and A1
  Serial1.begin(9600);

  uint32_t baudrate = 0x800000;
  uint32_t *pBaudrate = ( uint32_t * )0x40002524;
  *pBaudrate = baudrate;
}


void loop() {
  // 0x99 is hexadecimal for 153 decimal
  // 153 is note on channel 10
  // 49 is crash cymbal
  // 127 is velocity
  midiCommand(0x99, 49, 127);
  delay(1000);
}

// send 3 byte midi message
void midiCommand(byte cmd, byte data1, byte data2) {

  Serial1.write(cmd);
  Serial1.write(data1);
  Serial1.write(data2);

}
