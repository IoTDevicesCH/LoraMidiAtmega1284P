// This sketch sets the internal reference to 1.1V and does one ADC reading in order that you can measure AVCC to get more accurate voltage divider readings!

void setup() {
  Serial.begin(115200);
  Serial.println("Starting");
  analogReference(INTERNAL1V1); // Set internal reference to 1.1V
  analogRead(A4); // we need to call analogRead once to activate the analog reference
}

void loop() {
  // we don't do anything here
}
