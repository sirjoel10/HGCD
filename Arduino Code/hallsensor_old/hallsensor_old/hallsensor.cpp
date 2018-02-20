/*
 flex_sensor.cpp - Library for using analogue flex sensors.
  Created by Siriffo Sonko 20 Feb, 2018.
  Released into the public domain.
*/



#include "Arduino.h"
#include "hallsensor.h"

hallsensor::hallsensor(int pin)
{
  pinMode(pin, INPUT);
  _pin = pin;
}


void hallsensor::setDigitalValue(int val){
_val = val;
  
  
}


  
int hallsensor::digitalVal(){ // returns 0 if outside of digital value 1 if inside of digital value


if(_val<analogRead(_pin)){
  return 0;
}


  return 1;


}

int hallsensor::analogVal(){
  return analogRead(_pin);
}

