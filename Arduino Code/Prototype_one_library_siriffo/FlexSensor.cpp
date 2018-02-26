/*
 flex_sensor.cpp - Library for using analogue flex sensors.
  Created by Siriffo Sonko and Joel Sirefelt 17 Feb, 2018.
  Released into the public domain.
*/

#include "Arduino.h"
#include "FlexSensor.h"

//testtesttest

FlexSensor::FlexSensor(int pin)
{
  pinMode(pin, INPUT);
  _pin = pin;
}
//TODO verify code 


void FlexSensor::calib(){
 // calibrate during the first five seconds 
  Serial.println("write 1 to start calibration");
  while(Serial.read()!='1'){
    //write 1 to start calibration
  }
    Serial.println("Calibration started");

  Serial.println("Move fingers");
 
unsigned long startTime = millis();
 
while (millis()-startTime< 5000){
  if(getVal() < _sensorMin){
    _sensorMin = getVal();
  }

  if(getVal() > _sensorMax){
    _sensorMax = getVal();
  }

 
}
Serial.println("Callibration Finished");
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

