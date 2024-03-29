// This sketch demonstrates how to measure voltage provided by VCC or RAW pin depending on solderjumper selection.
// This voltage divider is switched on and off through two mosfets which are controller through pin 0.
// If pin 0 is low, voltage divider is off, if pin 0 is high, voltage divider is on.

int batteryReadPin = A0;        // set the input pin for the battery measurement
int voltageDividerPin = 0;      // set the pin to enable the voltage divider
const float AREF = 1.1;         // internal reference voltage. For more accurate measurement, use the AREF value from the sticker on the board.
const float RGND = 20.0;        // voltage divider resistor from A0 to GND. Value in K ohms
const float RSUP = 100.0;       // voltage divider resistor from A0 to VCC or UREG depending on solder jumper. Value in K ohms

void setup() {
  Serial.begin(115200);
  Serial.println("Starting");
  analogReference(INTERNAL1V1);         // Set internal reference to 1.1V
  pinMode(batteryReadPin, INPUT);       // Set analog pin to input
  pinMode(voltageDividerPin, OUTPUT);   // Set pin which controls the voltage divider to output
}

void loop() {
  //Enable voltage divider
  digitalWrite(voltageDividerPin, HIGH);

  //warm up the ADC
  for (int i = 0; i < 16; i++)
  {
    analogRead(batteryReadPin);
  }

  //oversample and print the ADC reading
  uint16_t ADCreading = 0;
  int i = 0;
  while (i < 8)
  {
    ADCreading = ADCreading + analogRead(batteryReadPin);
    i++;
  }
  ADCreading = ADCreading >> 3;
  Serial.print("ADC reading: ");
  Serial.println(ADCreading);

  //Disable voltage divider to save power
  digitalWrite(voltageDividerPin, LOW);

  //convert ADC reading to voltage and print it
  float voltage = ((ADCreading * AREF / 1024.0) * (RSUP + RGND) / RGND);
  Serial.print("Voltage: ");
  Serial.println(voltage);
  delay(10000);
}
