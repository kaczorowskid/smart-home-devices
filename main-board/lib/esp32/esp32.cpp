#include "esp32.h"

void Esp32::initSerial(unsigned long baud)
{
  Serial.begin(baud);
}

void Esp32::initWifi(void)
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
