#include <SPI.h>
#include <ArduinoJson.h>
#include "esp32.h"
#include "date.h"
#include "radio.h"
#include "../secrets.h"

Esp32 esp32;
Date date;
Radio radio;

void setup()
{
  esp32.initSerial(9600);
  esp32.initWifi();
  date.initDate();
  radio.initRadio(RF24_ADDR);
}

void loop()
{
}
