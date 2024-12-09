#include "radio.h"

Radio::Radio() : rf24(CE_PIN, CSN_PIN) {}

void Radio::init(const byte address[6])
{
  Serial.println("Initializing nRF24L01...");
  if (!rf24.begin())
  {
    Serial.println("Failed to initialize nRF24L01. Check wiring and power.");
  }
  Serial.println("nRF24L01 initialized successfully.");

  rf24.openWritingPipe(address);
  rf24.openReadingPipe(0, address);
  rf24.setPALevel(RF24_PA_HIGH);
  rf24.setDataRate(RF24_250KBPS);
  rf24.enableDynamicPayloads();
  rf24.stopListening();
  rf24.printDetails();
}

void Radio::send(const char *data, size_t length)
{
  if (!rf24.write(data, length))
  {
    Serial.println("Błąd wysyłania danych");
  }
  else
  {
    Serial.println("Dane wysłane pomyślnie");
  }
}
