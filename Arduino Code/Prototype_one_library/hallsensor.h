/*
 flex_sensor.h - Library for using analogue flex sensors.
  Created by Siriffo Sonko 20 Feb, 2018.
  Released into the public domain.
*/

#ifndef hallsensor_h
#define hallsensor_h

#include "Arduino.h"

class hallsensor
{
  public:
    hallsensor(int pin);
    void setDigitalValue(int val);
    int digitalVal(); // returns 0 if outside of digital value 1 if inside of digital value
    int analogVal();
  private:
    int _pin;
    int _val;
};


#endif
