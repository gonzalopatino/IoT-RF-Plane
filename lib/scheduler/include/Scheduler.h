#pragma once
#include <Arduino.h>
#include <Timebase.h>   // <-- important for LDF to link util

class Scheduler {
public:
    void add(void (*task)(), uint32_t period_us);
    void tick();
private:
    struct Task {
        void (*func)();
        uint32_t period_us;
        uint32_t next_us;
    };
    static const uint8_t MAX_TASKS = 8;
    Task tasks[MAX_TASKS];
    uint8_t count = 0;
};
