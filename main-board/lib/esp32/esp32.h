#ifndef esp32_h
#define esp32_h

#include <ESP8266WiFi.h>
#include "../secrets.h"

class Esp32
{
public:
  void initSerial(unsigned long baud);
  void initWifi(void);
};

#endif
