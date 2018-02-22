/*
 flex_sensor.cpp - Library for using analogue flex sensors.
  Created by Siriffo Sonko and Joel Sirefelt 17 Feb, 2018.
  Released into the public domain.
*/

#include "Arduino.h"
#include "FlexSensor.h"

FlexSensor::flexSensor(int pin)
{
  pinMode(pin, INPUT);
  _pin = pin;
}
//TODO verify code 


void flexSensor::calib(){
 // calibrate during the first five seconds 
  Serial.println("Callibration Start");
  bool nextop = false;
  unsigned long startTime1 = millis();
  Serial.println("Stretch out");
while (millis()-startTime1< 10000){
  sensorStart=getVal();
}
  Serial.println("Move fingers");
 
unsigned long startTime2 = millis();
 
while (millis()-startTime2< 10000){
  sensorValue = sensorStart - getVal();
   // record the maximum sensor value
  if (sensorValue > sensorMax) {
    sensorMax = sensorValue;
  }

   // record the minimum sensor value
  if (sensorValue < sensorMin) {
    sensorMin = sensorValue;
  }
}
Serial.println("Callibration Finished");
}




int flexSensor::getVal(){
  return analogRead(_pin);
}

