#ifndef date_h
#define date_h

#include <NTPClient.h>
#include <WiFiUdp.h>
#include <time.h>

class Date
{
private:
  WiFiUDP ntpUDP;
  NTPClient timeClient;

public:
  Date();

  void init();
  String getISOTime();
  String getFormattedTime();
};
#endif
