#include "power.h"

void Power::disableModules()
{
  power_adc_disable();
  power_spi_disable();
  power_timer0_disable();
  power_timer1_disable();
  power_timer2_disable();
  power_twi_disable();
  power_usart0_disable();

  set_sleep_mode(SLEEP_MODE_PWR_DOWN);

  sleep_enable();
  sleep_mode();
  sleep_disable();
}

void Power::enableModules()
{
  power_adc_enable();
  power_spi_enable();
  power_timer0_enable();
  power_timer1_enable();
  power_timer2_enable();
  power_twi_enable();
  power_usart0_enable();
}
