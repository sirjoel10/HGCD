/*
 vibrator.cpp - Library for using vibrating acutators.
  Created by Siriffo Sonko and Joel Sirefelt 17 Feb, 2018.
  Released into the public domain.
*/

#include "Arduino.h"
#include "Vibrator.h"

Vibrator::vibrator(int pin)
{
  pinMode(pin, OUTPUT);
  _pin = pin;
}
//TODO verify code 

void Vibrator::setSpeed(int speed){
  _speed = speed;
  analogWrite(_pin, _speed);
}


int Vibrator::getSpeed(){
  return _speed;
}

