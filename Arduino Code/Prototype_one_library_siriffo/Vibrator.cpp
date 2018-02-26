/*
 vibrator.cpp - Library for using vibrating acutators.
  Created by Siriffo Sonko and Joel Sirefelt 17 Feb, 2018.
  Released into the public domain.
*/

#include "Arduino.h"
#include "vibrator.h"

int _max;
int _min;

 Vibrator::Vibrator(int pin)
{
  pinMode(pin, OUTPUT);
  _pin = pin;
}
//TODO verify code 

void Vibrator::setSpeed(int speed){
  _speed = speed;
  analogWrite(_pin, _speed);
}

void Vibrator::setMaxMinVal(int maxVal, int minVal){
  _max = maxVal;
  _min = minVal;
}
//scales value to range 0-255
int Vibrator::setScaledSpeed(int input){
  

  return (1-((input-_min)/(_max-_min)))*(250-0)+0;
}


int Vibrator::getSpeed(){
  return _speed;
}

