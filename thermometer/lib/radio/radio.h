#ifndef radio_h
#define radio_h

#include <nRF24L01.h>
#include <RF24.h>

#define CE_PIN A1
#define CSN_PIN A0

class Radio
{
private:
  RF24 rf24;

public:
  Radio();

  void init(const byte address[6]);
  void send(const char *data, size_t length);
};

#endif
