/*
 flexSensor.h - Library for using analogue flex sensors.
  Created by Siriffo Sonko and Joel Sirefelt 17 Feb, 2018.
  Released into the public domain.
*/
#ifndef Vibrator_h
#define Vibrator_h

#endif

//TODO verify code 

#include "Arduino.h"

class Vibrator
{
  public:
    vibrator(int pin);
    void setSpeed(int speed);
    int getSpeed();
    
  private:
    int _pin;
    int _speed;
};


