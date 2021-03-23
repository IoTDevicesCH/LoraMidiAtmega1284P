// This sketch demonstrates how to enter sleep mode with WDT disabled and wake up from an interrupt on A2 pin
// This mode is the most low power mode availabel, it consumes about 510nA in this powerDown mode
#include "PinChangeInterrupt.h" // https://github.com/NicoHood/PinChangeInterrupt
#include "LowPower.h" // https://github.com/rocketscream/Low-Power
const int wakeUpPin = A2; // define wakeup pin, in our case A2 which is pulled up to VCC with a 10K resistor on the board
bool wakeupReason = 0; // in the sketch we set this to 1 if waken up from A2 pin

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Starting");
  pinMode(wakeUpPin, INPUT);
  attachPCINT(digitalPinToPCINT(wakeUpPin), wakeupFromA2, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(wakeupReason == 1) {
	  Serial.println("Waken up from A2 pin");
	  wakeupReason = 0; // set variable back to 0
  }
  Serial.println("Going to sleep");
  Serial.flush(); // waits for the transmission of outgoing serial data to complete
  LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF);
  delay(1000); // instead a delay, you would do here something meaningful
}

void wakeupFromA2(void) {
  //do something if waken up through A2 pin
  wakeupReason = 1;
}
