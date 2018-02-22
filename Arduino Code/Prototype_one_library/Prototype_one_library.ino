
#ifndef flex_sensor.h
#include "flex_sensor.h"
#endif


flex_sensor s1(A3);
void setup() {
pinMode
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println(s1.getVal());
delay(500);
}
