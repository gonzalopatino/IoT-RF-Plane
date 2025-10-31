#pragma once
#include <stdint.h>

struct RcFrame {
  int16_t ch1, ch2, ch3, ch4;  // 1000..2000 us or -1000..+1000 scaled
  uint16_t frame_us;           // time since last frame
  bool valid;
};

bool rf_init();                // no-op for fake
bool rf_read(RcFrame &out);    // returns latest sample if available
