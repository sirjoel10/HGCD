/*
 flexSensor.h - Library for using analogue flex sensors.
  Created by Siriffo Sonko and Joel Sirefelt 17 Feb, 2018.
  Released into the public domain.
*/
#ifndef vibrator_h
#define vibrator_h

//TODO verify code 

#include "Arduino.h"

class vibrator
{
  public:
    vibrator(int pin);
    void set_val();
    void getVal();
  private:
    int _pin;
   int speed
};

#endif
