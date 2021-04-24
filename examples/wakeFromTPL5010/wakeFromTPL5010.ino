// This sketch demonstrates how to enter sleep mode with WDT disabled and wake up from an interrupt on pin 2 through the TPL5010 timer
// This mode is the most low power mode available, it consumes about 560nA in this powerDown mode when powered through UREG pin
#include "LowPower.h" // https://github.com/rocketscream/Low-Power
#include "PinChangeInterrupt.h" // https://github.com/NicoHood/PinChangeInterrupt // you can also use the attachInterrupt() function from Arduino, to be consistent through all examples this lib is here used too
const int donePin = 3; // define done pin where TPL5010 is connected to, in our case pin 3
const int WakePin = 2; // define WDT pin where TPL5010 is connected to, in our case pin 2
bool wakeupReason = 0; // in the sketch we set this to 1 if waken up from pin 2

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Starting");
  Serial.flush();
  pinMode(WakePin, INPUT);
  pinMode(donePin, OUTPUT);
  attachPCINT(digitalPinToPCINT(WakePin), wakeupFromTimer, HIGH);
  }

void loop() {
  // put your main code here, to run repeatedly:
  // if wakeupReason is 1, we woke up from the TPL5010
  if(wakeupReason == 1) {
	  wakeupReason = 0; // Reset wakeup reason
	  Serial.println("Waken up from Timer");

  }
  // do something here instead of the delay
  delay(1000);
  Serial.println("Going to sleep");
  Serial.flush(); // waits for the transmission of outgoing serial data to complete

  // set DONE high for 100 micro seconds to tell the TPL5010 we're done
  // if DONE was not high between interrupts, TPL5010 will reset the MCU through the reset pin if connected, otherwise it will do nothing until 'DONE' was set high once
  digitalWrite(donePin, HIGH);
  delayMicroseconds(100);
  digitalWrite(donePin, LOW);
  LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF);
}

void wakeupFromTimer(void) {
  //do something if waken up through pin 2
  wakeupReason = 1;
}
