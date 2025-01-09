#include "adc.h"

void Adc::init()
{
  pinMode(BATTERY_PIN, INPUT);
}

float Adc::readVoltage()
{
  long rawValue = 0;

  for (int i = 0; i < SAMPLES; i++)
  {
    rawValue += analogRead(BATTERY_PIN);
    delay(5);
  }

  rawValue /= SAMPLES;

  float voltage = rawValue * (REFERENCE_VOLTAGE / 1023.0) * VOLTAGE_DIVIDER;

  return voltage;
}

int Adc::getBatteryPercentage()
{
  float voltage = readVoltage();

  int percentage = map(
      voltage * 100,
      MIN_BATTERY_VOLTAGE * 100,
      MAX_BATTERY_VOLTAGE * 100,
      0,
      100);

  percentage = constrain(percentage, 0, 100);

  return percentage;
}

float Adc::getVoltage()
{
  return readVoltage();
}
