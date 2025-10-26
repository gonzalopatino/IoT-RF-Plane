#pragma once
#include <stdint.h>

// Returns true when 'period_us' elapsed since last trigger.
bool tick_elapsed(uint32_t now_us, uint32_t& next_due_us, uint32_t period_us);
