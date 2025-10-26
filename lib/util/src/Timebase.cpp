#include "Timebase.h"

bool tick_elapsed(uint32_t now_us, uint32_t& next_due_us, uint32_t period_us) {
  if (next_due_us == 0) {            // first call
    next_due_us = now_us + period_us;
    return true;
  }
  if ((int32_t)(now_us - next_due_us) >= 0) { // handles wraparound
    next_due_us += period_us;
    return true;
  }
  return false;
}
