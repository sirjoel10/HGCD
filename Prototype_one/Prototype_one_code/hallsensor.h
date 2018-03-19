/*
 flex_sensor.h - Library for using analogue flex sensors.
  Created by Siriffo Sonko 20 Feb, 2018.
  Released into the public domain.
*/

/*
  Designed for a delay of 250ms
  OutputTap
  0: no tap
  1: hold tap 
  2: single tap 
  3: double tap
*/

#ifndef Hallsensor_h
#define Hallsensor_h
#include "Arduino.h"


class Hallsensor
{
  public:
    Hallsensor(int pin);
    int analogVal();
  private:
    int _pin;
    int _val;
};


#endif
