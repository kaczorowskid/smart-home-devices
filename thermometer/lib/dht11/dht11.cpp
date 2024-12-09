#include "dht11.h"

Dht11::Dht11() : dht(DHTPIN, DHTTYPE) {}

void Dht11::init(void)
{
  dht.begin();
}

Dht11::sensor Dht11::getValues(void)
{
  init(); // Required after the processor wakes up

  sensors_event_t temp, hum;
  sensor values;

  dht.temperature().getEvent(&temp);
  dht.humidity().getEvent(&hum);

  values.temperature = temp.temperature;
  values.humidity = hum.relative_humidity;

  return values;
}
