#include <SPI.h>
#include <ArduinoJson.h>
#include "esp32.h"

Esp32 esp32;

void setup()
{
  esp32.initSerial(9600);
  esp32.initWifi();
}

void loop()
{
}
