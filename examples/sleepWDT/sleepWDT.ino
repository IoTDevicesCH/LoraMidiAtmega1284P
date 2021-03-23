// This sketch demonstrates how to enter sleep mode while keep WDT active
// This mode consumes about 5.8uA in powerDown mode, the short wakeup every 8s is taken into account in this measurement
#include "LowPower.h" // https://github.com/rocketscream/Low-Power

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Starting");
  Serial.println("Going to sleep");
  Serial.flush();
}

void loop() {
  // put your main code here, to run repeatedly:
  LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
}