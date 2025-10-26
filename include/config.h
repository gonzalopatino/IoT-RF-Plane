#pragma once

#if defined(ARDUINO_AVR_UNO)
  #define LED_PIN 13
#elif defined(ARDUINO_ARCH_STM32)
  #ifndef LED_BUILTIN
    #define LED_BUILTIN PC13
  #endif
  #define LED_PIN LED_BUILTIN
#else
  #define LED_PIN 13
#endif
