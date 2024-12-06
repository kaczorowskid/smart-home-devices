#include <SPI.h>
#include <ArduinoJson.h>
#include "esp32.h"
#include "date.h"
#include "radio.h"
#include "mqtt.h"
#include "utils.h"
#include "../secrets.h"
#include "../constants.h"

Esp32 esp32;
Date date;
Radio radio;
Mqtt mqtt;
Utils utils;

bool dataReady = false;
String receivedString;

void convertReceivedDataAndSend()
{
  JsonDocument jsonDocToSend;
  char jsonStringToSend[128];

  float temperature = utils.getValueFromSplittedString(receivedString, ',', 0).toFloat();
  float humidity = utils.getValueFromSplittedString(receivedString, ',', 1).toFloat();
  int battery = utils.getValueFromSplittedString(receivedString, ',', 2).toInt();
  String deviceId = utils.getValueFromSplittedString(receivedString, ',', 3);

  jsonDocToSend["temperature"] = temperature;
  jsonDocToSend["humidity"] = humidity;
  jsonDocToSend["battery"] = battery;
  jsonDocToSend["deviceId"] = deviceId;
  jsonDocToSend["date"] = date.getISOTime();

  serializeJson(jsonDocToSend, jsonStringToSend);

  bool isPublished = mqtt.publishMessage(SENSORS_THERMOMETER_TOPIC, jsonStringToSend);

  if (isPublished)
  {
    Serial.println("Message published");
  }
  else
  {
    Serial.println("Publish failed");
  }
}

void copyReceivedData(const String &data)
{
  receivedString = data;
  dataReady = true;
}

IRAM_ATTR void irqHandler(void)
{
  radio.receive(copyReceivedData);
}

void setup()
{
  esp32.initSerial(9600);
  esp32.initWifi();
  mqtt.initMqtt();
  mqtt.connectToMqttBroker();
  date.initDate();
  radio.initRadio(RF24_ADDR);

  mqtt.subscribeTopic(SENSORS_THERMOMETER_TOPIC);

  pinMode(D2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(D2), irqHandler, FALLING);
}

void loop()
{
  mqtt.clientLoop();

  if (dataReady)
  {
    convertReceivedDataAndSend();
    dataReady = false;
  }
}
