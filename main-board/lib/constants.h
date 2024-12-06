#ifndef constants_h
#define constants_h

#include <Arduino.h>
#include "secrets.h"

#define SENSORS_THERMOMETER_TOPIC strcmp(ENV, "dev") == 0 ? "dev/sensors/thermometer" : "prod/sensors/thermometer"

#endif
