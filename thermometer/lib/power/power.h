#ifndef power_h
#define power_h

#include <avr/sleep.h>
#include <avr/power.h>
#include <Arduino.h>

class Power
{
public:
  void disableModules();
  void enableModules();
};

#endif
