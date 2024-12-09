#ifndef utils_h
#define utils_h

#include <Arduino.h>

class Utils
{
private:
public:
  struct floatValue
  {
    int decimal;
    int fraction;
  };

  floatValue formatFloatNumber(float value);
};

#endif
