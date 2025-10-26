#pragma once

#ifdef ARDUINO_AVR_UNO
  #define LED_PIN 13
#elif defined(ARDUINO_NUCLEO_H753ZI)
  #define LED_PIN PC13
#else
  #define LED_PIN 13
#endif
