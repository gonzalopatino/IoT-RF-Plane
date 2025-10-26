#include "Scheduler.h"

void Scheduler::add(void (*task)(), uint32_t period_us) {
    if (count >= MAX_TASKS) return;
    tasks[count++] = {task, period_us, micros() + period_us};
}

void Scheduler::tick() {
    uint32_t now = micros();
    for (uint8_t i = 0; i < count; i++) {
        if (tick_elapsed(now, tasks[i].next_us, tasks[i].period_us)) {
            tasks[i].func();
        }
    }
}
