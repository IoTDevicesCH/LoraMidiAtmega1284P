// This sketch demonstrates how to enter sleep mode with WDT disabled and wake up from an interrupt on pin 4
// This mode is the most low power mode available, it consumes about 520nA in this powerDown mode when powered through UREG pin
#include "LowPower.h" // https://github.com/rocketscream/Low-Power
#include "PinChangeInterrupt.h" // https://github.com/NicoHood/PinChangeInterrupt
const int wakePin = 4; // define wakeup pin, in our case pin 4 which is pulled up to VCC with a 10K resistor on the board
bool wakeupReason = 0; // in the sketch we set this to 1 if waken up from pin 4

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Starting");
  pinMode(wakePin, INPUT);
  attachPCINT(digitalPinToPCINT(wakePin), wakeupFromPin4, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(wakeupReason == 1) {
	  Serial.println("Waken up from pin 4");
	  wakeupReason = 0; // set variable back to 0
  }
  Serial.println("Going to sleep");
  Serial.flush(); // waits for the transmission of outgoing serial data to complete
  LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF);
  delay(1000); // instead a delay, you would do here something meaningful
}

void wakeupFromPin4(void) {
  //do something if waken up through pin 4
  wakeupReason = 1;
}