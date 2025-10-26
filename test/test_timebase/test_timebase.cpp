#include <Arduino.h>
#include <unity.h>
#include <Timebase.h>

// ---- tests ----------------------------------------------------

void test_tick_elapsed_basic() {
  uint32_t next = 0;
  TEST_ASSERT_TRUE(tick_elapsed(0, next, 500));   // fires at t=0
  TEST_ASSERT_EQUAL_UINT32(500, next);
  TEST_ASSERT_FALSE(tick_elapsed(100, next, 500));
  TEST_ASSERT_TRUE(tick_elapsed(500, next, 500)); // fires again at t=500
  TEST_ASSERT_EQUAL_UINT32(1000, next);
}

void test_tick_elapsed_wrap() {
  // Simulate a schedule near wrap, then after wrap.
  uint32_t next = 0xFFFFFF00u;

  // Slightly after scheduled time -> must fire, next becomes 244
  TEST_ASSERT_TRUE(tick_elapsed(0xFFFFFF10u, next, 500));

  // Before 244 after wrap -> must NOT fire
  TEST_ASSERT_FALSE(tick_elapsed(0x000000F0u, next, 500));  // 240 < 244

  // At/after 244 -> must fire (next -> 744)
  TEST_ASSERT_TRUE(tick_elapsed(0x0000012Cu, next, 500));   // 300 >= 244

  // Before 744 -> must NOT fire
  TEST_ASSERT_FALSE(tick_elapsed(0x00000280u, next, 500));  // 640 < 744

  // At/after 744 -> must fire
  TEST_ASSERT_TRUE(tick_elapsed(0x000002F0u, next, 500));   // 752 >= 744
}

// ---- Unity runner ---------------------------------------------

void setUp()   {}   // optional
void tearDown(){}   // optional

void setup() {
  delay(2000);              // give USB time to settle
  UNITY_BEGIN();
  RUN_TEST(test_tick_elapsed_basic);
  RUN_TEST(test_tick_elapsed_wrap);
  UNITY_END();
}

void loop() {
  // not used in unit tests
}
