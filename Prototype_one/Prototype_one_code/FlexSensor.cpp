/*
 flex_sensor.cpp - Library for using analogue flex sensors.
  Created by Siriffo Sonko and Joel Sirefelt 17 Feb, 2018.
  Released into the public domain.
*/

#include "Arduino.h"
#include "FlexSensor.h"

FlexSensor::FlexSensor(int pin)
{
  pinMode(pin, INPUT);
  _pin = pin;
}



void FlexSensor::stretch(){
  unsigned long startTime = millis();
  while (millis()-startTime< 5000){
    if(getVal() >_sensorMax){
      _sensorMax = getVal();
    }
  }
}

void FlexSensor::clench(){
  unsigned long startTime = millis();
  while (millis()-startTime< 5000){
    if(getVal() <_sensorMin){
      _sensorMin = getVal();
    }
  }
}

int FlexSensor::getVal(){
  return analogRead(_pin);
}

int FlexSensor::getMax(){
  return _sensorMax;
}

int FlexSensor::getMin(){
  return _sensorMin;
}

