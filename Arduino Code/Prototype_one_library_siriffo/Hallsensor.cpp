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


void Hallsensor::setDigitalValue(int val){
_val = val;
  
  
}


  
int Hallsensor::digitalVal(){ // returns 0 if outside of digital value 1 if inside of digital value


if(_val<analogRead(_pin)){
  return 0;
}


  return 1;


}

int Hallsensor::analogVal(){
  return analogRead(_pin);
}

