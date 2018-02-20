/*
 vibrator.cpp - Library for using vibrating acutators.
  Created by Siriffo Sonko and Joel Sirefelt 17 Feb, 2018.
  Released into the public domain.
*/

#include "Arduino.h"
#include "vibrator.h"

vibrator::vibrator(int pin)
{
  pinMode(pin, OUTPUT);
  _pin = pin;
}
//TODO verify code 

void vibrator::set_speed(int speed){
  _speed = speed;
  analogWrite(_pin, _speed);
}


int vibrator::get_speed(){
  return _speed;
}

