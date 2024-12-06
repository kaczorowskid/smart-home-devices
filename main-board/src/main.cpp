#include <SPI.h>
#include <ArduinoJson.h>
#include "esp32.h"
#include "date.h"

Esp32 esp32;
Date date;

void setup()
{
  esp32.initSerial(9600);
  esp32.initWifi();
  date.initDate();
}

void loop()
{
}
