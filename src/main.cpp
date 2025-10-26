#include <Arduino.h>
#include <Scheduler.h>
#include "config.h"

Scheduler sch;

static void task_led() {
  static bool on = false;
  digitalWrite(LED_PIN, on ? HIGH : LOW);
  on = !on;
}

static void task_heartbeat() {
  static uint32_t n = 0;
  Serial.print(F("HB ")); Serial.println(n++);
}

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);
  delay(200);                     // give the port a moment on Uno
  Serial.println(F("FC scaffold online."));
  sch.add(task_led,       500000);  // 500 ms
  sch.add(task_heartbeat, 1000000); // 1 s
}

void loop() {
  sch.tick();
}
