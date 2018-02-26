/*
 flex_sensor.cpp - Library for using analogue flex sensors.
  Created by Siriffo Sonko 20 Feb, 2018.
  Released into the public domain.
*/



#include "Arduino.h"
#include "Hallsensor.h"

Hallsensor::Hallsensor(int pin)
{
  pinMode(pin, INPUT);
  _pin = pin;
}



int Hallsensor::analogVal(){
  return analogRead(_pin);
}




