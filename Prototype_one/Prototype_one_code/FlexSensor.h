/*
 flex_sensor.h - Library for using analogue flex sensors.
  Created by Siriffo Sonko and Joel Sirefelt 17 Feb, 2018.
  Released into the public domain.
*/
#ifndef FlexSensor_h
#define FlexSensor_h


#include "Arduino.h"

class FlexSensor
{
  public:
    FlexSensor(int pin);
    void stretch();
    void clench();
    int getVal();
    int getMax();
    int getMin();
  private:
    int _pin;
    int _sensorValue = 0;         // the sensor value
    int _sensorMin = 1000;        // minimum sensor value
    int _sensorMax = 0;
    int _sensorStart = 0;
};

#endif
