#include "timer_demo.h"

void timer_init(timer_t *t, timer_callback_t cb, void *ctx){
    t->on_tick = cb;
    t->ctx = ctx;
    t->ticks = 0;
}

void timer_run(timer_t *t, int count){
    for (int i = 0; i < count; i++){
        t->ticks++; // Library side functions
        if(t->on_tick){
            t->on_tick(t->ticks, t->ctx);  // User callback
        }
    }
}