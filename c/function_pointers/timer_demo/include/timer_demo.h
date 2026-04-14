#ifndef TIMER_DEMO_H
#define TIMER_DEMO_H

#include<stdio.h>
#include<string.h>

typedef void (*timer_callback_t)(int tick, void *ctx); // CTX is signature provided by user

typedef struct{
    timer_callback_t on_tick; // callback function the user will provide
    void *ctx; // Why?
    int ticks; // for counting how many ticks?
}timer_t;

void timer_init(timer_t *t, timer_callback_t cb, void*ctx);
void timer_run(timer_t *t, int count);

#endif