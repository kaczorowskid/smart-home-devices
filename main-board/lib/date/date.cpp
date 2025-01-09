#include "date.h"

Date::Date() : timeClient(ntpUDP, "pool.ntp.org", 3600, 60000) {}

void Date::init()
{
  timeClient.begin();
  while (!timeClient.update())
    ;
}

String Date::getISOTime()
{
  timeClient.update();
  time_t now = timeClient.getEpochTime();
  struct tm *timeinfo = localtime(&now);

  char buffer[30];
  strftime(buffer, sizeof(buffer), "%Y-%m-%dT%H:%M:%S+01:00", timeinfo);

  return String(buffer);
}

String Date::getFormattedTime()
{
  timeClient.update();
  time_t now = timeClient.getEpochTime();
  struct tm *timeinfo = localtime(&now);

  char buffer[6];
  strftime(buffer, sizeof(buffer), "%H:%M", timeinfo);

  return String(buffer);
}
