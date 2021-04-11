// This sketch demonstrates how to use the 'GNDS' (switched GND pins).
// The GNS pins are switched through a mosfet which is controlled through pin 15.
// If pin 15 is low, the GNDS pins are not connected to GND, if high, the GNDS pins are connected to GND

int GNDSenablePin = 15;        // set the control pin for GNDS mosfet

void setup() {
  Serial.begin(115200);
  Serial.println("Starting");
  pinMode(GNDSenablePin, OUTPUT);       // set pin to output
}

void loop() {
  //Enable GNDS pins
  digitalWrite(GNDSenablePin, HIGH);

  // do something with the now powered peripherals connected to the GNDS pins

  //Disable GNDS pins to power off peripherals
  digitalWrite(GNDSenablePin, LOW);

  // go to sleep for example

  delay(10000);
}
