#include <Arduino.h>
#include "config.h"
#include <Timebase.h>

static uint32_t next_500ms = 0;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);
  Serial.println("FC scaffold online.");
}

void loop() {
  if (tick_elapsed(micros(), next_500ms, 500000)) { // 500 ms
    static bool on = false;
    digitalWrite(LED_PIN, on ? HIGH : LOW);
    on = !on;
    Serial.println("Blink");
  }
}
