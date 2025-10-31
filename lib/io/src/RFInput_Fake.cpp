#include <Arduino.h>
#include <RFInput.h>

static RcFrame last = {1500,1500,1500,1500,20000,true};
static uint32_t next_us;

bool rf_init() { next_us = micros(); return true; }

bool rf_read(RcFrame &out) {
  if ((int32_t)(micros() - next_us) < 0) return false;
  next_us += 20000;               // 50 Hz frames
  // simple sweep on ch1 to prove data moves
  static int dir = 1;
  last.ch1 += dir * 10;
  if (last.ch1 > 1900 || last.ch1 < 1100) dir = -dir;
  out = last;
  return true;
}
