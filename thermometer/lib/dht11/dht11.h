#ifndef dht11_h
#define dht11_h

#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN A4
#define DHTTYPE DHT11

class Dht11
{
private:
  DHT_Unified dht;

public:
  Dht11();

  struct sensor
  {
    float temperature;
    float humidity;
  };

  void init(void);
  sensor getValues(void);
};

#endif
