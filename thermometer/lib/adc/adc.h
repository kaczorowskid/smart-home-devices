#ifndef adc_h
#define adc_h

#include <Arduino.h>

#define BATTERY_PIN A5
#define REFERENCE_VOLTAGE 3.3
#define VOLTAGE_DIVIDER 1.21
#define SAMPLES 10

const float MAX_BATTERY_VOLTAGE = 3.7;
const float MIN_BATTERY_VOLTAGE = 3.3;

class Adc
{
private:
  float readVoltage();

public:
  void init();
  int getBatteryPercentage();
  float getVoltage();
};

#endif
