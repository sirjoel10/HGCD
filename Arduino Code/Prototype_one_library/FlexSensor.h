/*
 flex_sensor.h - Library for using analogue flex sensors.
  Created by Siriffo Sonko and Joel Sirefelt 17 Feb, 2018.
  Released into the public domain.
*/
#ifndef FlexSensor_h
#define FlexSensor_h

//TODO verify code 

#include "Arduino.h"

class FlexSensor
{
  public:
    flexSensor(int pin);
    void calib();
    int getVal();
  private:
    int _pin;
    int sensorValue = 0;         // the sensor value
    int sensorMin = 1023;        // minimum sensor value
    int sensorMax = 0;
    int sensorStart = 0;
};

#endif
