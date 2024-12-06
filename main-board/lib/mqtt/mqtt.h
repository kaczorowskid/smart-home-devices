#ifndef mqtt_h
#define mqtt_h

#include <WiFiClient.h>
#include <PubSubClient.h>
#include "../secrets.h"

class Mqtt
{
public:
  Mqtt(const char *clientId = "ESP32Client")
      : pubSubClient(wifiClient), clientId(clientId) {}

  void initMqtt()
  {
    if (IPAddress().fromString(MQTT_SERVER))
    {
      Serial.println("Valid IPv6 address format.");
    }
    else
    {
      Serial.println("Invalid IPv6 address format.");
    }

    pubSubClient.setServer(MQTT_SERVER, MQTT_PORT);
  }

  void connectToMqttBroker()
  {
    while (!pubSubClient.connected())
    {
      Serial.println("Connecting to MQTT...");
      if (pubSubClient.connect(clientId))
      {
        Serial.println("Connected to MQTT.");
      }
      else
      {
        Serial.print("Failed to connect to MQTT, error code: ");
        Serial.println(pubSubClient.state());
        delay(2000);
      }
    }
  }

  void subscribeTopic(const char *topic)
  {

    Serial.println("Subscribed to topic.");
    pubSubClient.subscribe(topic);
  }

  bool publishMessage(const char *topic, const char *message)
  {
    if (!pubSubClient.connected())
    {
      Serial.println("MQTT client is not connected. Attempting to reconnect...");
      connectToMqttBroker();
    }

    return pubSubClient.publish(topic, message);
  }

  void clientLoop()
  {
    pubSubClient.loop();
  }

private:
  WiFiClient wifiClient;
  PubSubClient pubSubClient;
  const char *clientId;
};

#endif
