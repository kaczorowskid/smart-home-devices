#include <SPI.h>
#include <Arduino.h>
#include "radio.h"
#include "dht11.h"
#include "utils.h"
#include "adc.h"
#include "power.h"
#include "../secrets.h"
#include "../constants.h"

Radio radio;
Dht11 dht11;
Utils utils;
Power power;
Adc adc;

volatile bool shouldSendData = false;

ISR(WDT_vect)
{
  static int wakeCount = 0;

  wakeCount++;
  if (wakeCount >= TIME_IN_MINUTES(10))
  {
    wakeCount = 0;
    shouldSendData = true;
  }
}

void sendToMaster(void)
{
  char dataBuffer[20];
  Dht11::sensor values = dht11.getValues();

  Utils::floatValue temperature = utils.formatFloatNumber(values.temperature);
  Utils::floatValue humidity = utils.formatFloatNumber(values.humidity);
  int battery = adc.getBatteryPercentage();

  snprintf(dataBuffer,
           sizeof(dataBuffer),
           "%d.%02d,%d.%02d,%d,%d",
           temperature.decimal,
           temperature.fraction,
           humidity.decimal,
           humidity.fraction,
           battery,
           DEVICE_ID);

  Serial.println("Data sent: ");
  Serial.println(dataBuffer);

  radio.send(dataBuffer, strlen(dataBuffer) + 1);
}

void setup()
{
  delay(4000);

  Serial.begin(9600);
  radio.init(RF24_ADDR);
  dht11.init();
  adc.init();

  MCUSR = 0;
  WDTCSR = (1 << WDCE) | (1 << WDE);
  WDTCSR = (1 << WDP3) | (1 << WDP0);
  WDTCSR |= (1 << WDIE);
}

void loop()
{
  if (shouldSendData)
  {
    power.enableModules();
    delay(1000); // delay for DHT11 sensor
    sendToMaster();
    shouldSendData = false;
  }
  else
  {
    power.disableModules();
  }
}
