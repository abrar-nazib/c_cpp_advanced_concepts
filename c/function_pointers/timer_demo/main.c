#include <stdio.h>
#include "timer_demo.h"

typedef struct{
        const char* name;
        int event_count;
}user_state_t;

static void my_tick_handler(int tick, int *ctx){
    user_state_t *state = (user_state_t*)ctx;
    state->event_count++;
    printf("[%s] tick=%d, total_events=%d\n", state->name, tick, state->event_count);
}

int main(){
    user_state_t alice_state = {.name="Alice", .event_count=0};
    user_state_t bob_state = {.name="Bob", .event_count=0};

    timer_t alice_timer, bob_timer;
    timer_init(&alice_timer, my_tick_handler, &alice_state);
    timer_init(&bob_timer, my_tick_handler, &bob_state);

    timer_run(&alice_timer, 2);
    timer_run(&bob_timer, 5);

    return 0;
}
