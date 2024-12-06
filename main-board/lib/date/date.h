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
  Date() : timeClient(ntpUDP, "pool.ntp.org", 3600, 60000) {}

  void initDate()
  {
    timeClient.begin();
    while (!timeClient.update())
      ;
  }

  String getISOTime()
  {
    timeClient.update();
    time_t now = timeClient.getEpochTime();
    struct tm *timeinfo = localtime(&now);

    char buffer[30];
    strftime(buffer, sizeof(buffer), "%Y-%m-%dT%H:%M:%S+01:00", timeinfo);

    return String(buffer);
  }
};
#endif
