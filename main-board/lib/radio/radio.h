#ifndef radio_h
#define radio_h

#include <nRF24L01.h>
#include <RF24.h>

#define CE_PIN 16
#define CSN_PIN 0

class Radio
{
private:
  RF24 rf24;

public:
  Radio() : rf24(CE_PIN, CSN_PIN) {}

  void initRadio(const byte address[6])
  {
    if (!rf24.begin())
    {
      Serial.println("Failed to initialize nRF24L01");
      return;
    }

    rf24.setPALevel(RF24_PA_MIN);
    rf24.setDataRate(RF24_250KBPS);
    rf24.enableDynamicPayloads();

    rf24.openReadingPipe(0, address);
    rf24.startListening();

    rf24.printPrettyDetails();
  }

  void receive(void (*callback)(const String &data))
  {
    if (rf24.available())
    {
      uint8_t len = rf24.getDynamicPayloadSize();
      if (len == 0)
      {
        Serial.println("Received empty payload");
        return;
      }

      char buffer[len + 1];
      rf24.read(buffer, len);
      buffer[len] = '\0';

      callback(String(buffer));
    }
  }
};

#endif
