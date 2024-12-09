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
  Radio();

  void init(const byte address[6]);
  void receive(void (*callback)(const String &data));
};

#endif
