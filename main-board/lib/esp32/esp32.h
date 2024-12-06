#ifndef esp32_h
#define esp32_h

#include <ESP8266WiFi.h>
#include "../secrets.h"

class Esp32
{
public:
  void initSerial(unsigned long baud)
  {
    Serial.begin(baud);
  }

  void initWifi(void)
  {
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    Serial.println("Connecting");
    while (WiFi.status() != WL_CONNECTED)
    {
      delay(500);
      Serial.print(".");
    }
    Serial.println("");
    Serial.print("Connected to WiFi, IP: ");
    Serial.println(WiFi.localIP());
  }
};

#endif
