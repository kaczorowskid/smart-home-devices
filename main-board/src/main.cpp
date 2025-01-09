#include <SPI.h>
#include <ArduinoJson.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
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
LiquidCrystal_I2C lcd(0x27, 16, 2);

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
    Serial.print("Message published - ");
    Serial.println(date.getISOTime());
    lcd.setCursor(0, 1);
    lcd.print(date.getFormattedTime());
    lcd.setCursor(7, 1);
    lcd.print("ID: ");
    lcd.print(deviceId);
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
  Wire.begin(D2, D1);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("MQTT connecting");

  esp32.initSerial(9600);
  esp32.initWifi();
  mqtt.init();
  mqtt.connectToMqttBroker();
  date.init();
  radio.init(RF24_ADDR);

  mqtt.subscribeTopic(SENSORS_THERMOMETER_TOPIC);

  lcd.setCursor(0, 0);
  lcd.print("MQTT connected!");

  pinMode(D4, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(D4), irqHandler, FALLING);
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
