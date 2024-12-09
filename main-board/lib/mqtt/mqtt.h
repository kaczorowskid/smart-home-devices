#ifndef mqtt_h
#define mqtt_h

#include <WiFiClient.h>
#include <PubSubClient.h>
#include "../secrets.h"

class Mqtt
{
public:
  Mqtt(const char *clientId = "ESP32Client");

  void init();
  void connectToMqttBroker();
  void subscribeTopic(const char *topic);
  bool publishMessage(const char *topic, const char *message);
  void clientLoop();

private:
  WiFiClient wifiClient;
  PubSubClient pubSubClient;
  const char *clientId;
};

#endif
