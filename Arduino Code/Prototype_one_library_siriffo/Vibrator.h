/*
 flexSensor.h - Library for using analogue flex sensors.
  Created by Siriffo Sonko and Joel Sirefelt 17 Feb, 2018.
  Released into the public domain.
*/
#ifndef Vibrator_h
#define Vibrator_h



//TODO verify code 

#include "Arduino.h"

class Vibrator
{
  public:
    Vibrator(int pin);
    void setSpeed(int speed);
    int getSpeed();
    int setScaledSpeed(int input);
    void setMaxMinVal(int maxVal, int minVal);
  private:
    int _pin;
    int _speed;
};

#endif
