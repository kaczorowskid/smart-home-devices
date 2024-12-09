#include "mqtt.h"

Mqtt::Mqtt(const char *clientId = "ESP32Client")
    : pubSubClient(wifiClient), clientId(clientId) {}

void Mqtt::init()
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

void Mqtt::connectToMqttBroker()
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

void Mqtt::subscribeTopic(const char *topic)
{
  Serial.println("Topic has been subscribed");
  pubSubClient.subscribe(topic);
}

bool Mqtt::publishMessage(const char *topic, const char *message)
{
  if (!pubSubClient.connected())
  {
    Serial.println("MQTT client is not connected. Attempting to reconnect...");
    connectToMqttBroker();
  }

  return pubSubClient.publish(topic, message);
}

void Mqtt::clientLoop()
{
  pubSubClient.loop();
}
