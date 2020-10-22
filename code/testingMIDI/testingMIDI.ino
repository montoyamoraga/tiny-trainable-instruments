

int noteKick = 36;
int noteSnare = 38;
int noteClap = 39;

int noteChannel = 10;
int noteOn = 143;
int noteVelocity = 127;

int baudRate = 31250;


void setup() {
  // put your setup code here, to run once:

  Serial.begin(baudRate);

}

void loop() {
  // put your main code here, to run repeatedly:
  MidiSendNoteOn(noteChannel, noteSnare, noteVelocity);
  delay(500);
}

void midiSendNoteOn(int channel, int note, int velocity) {
  Serial.write(noteOn + channel);
  Serial.write(note);
  Serial.write(velocity);
}
