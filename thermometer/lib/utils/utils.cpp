#include "utils.h"

Utils::floatValue Utils::formatFloatNumber(float number)
{
  floatValue value;

  int decimal = (int)number;
  int fraction = (int)((number - decimal) * 100);

  value.decimal = decimal;
  value.fraction = fraction;

  return value;
}
