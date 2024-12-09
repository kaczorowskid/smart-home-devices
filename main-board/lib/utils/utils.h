#ifndef utils_h
#define utils_h

#include <Arduino.h>

class Utils
{
public:
  String getValueFromSplittedString(String data, char separator, int index);
};

#endif
