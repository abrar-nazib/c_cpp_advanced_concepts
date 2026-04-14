#include <stdio.h>
#include "library.h"

typedef struct{
    int counter;
    char name[32];
}my_state_t;

static void my_handler(int event_id, void* ctx){
    // Event handler function
    my_state_t *state = (my_state_t*)ctx;
    state->counter++;
    printf("[%s] got event %d (count=%d)\n", state->name, event_id, state->counter);
}

int main(){
    my_state_t state = {.counter = 0, .name="App"};

    library_cfg_t cfg = {
        .on_event = my_handler, // pass our function
        .ctx = &state, // pass our state
    };

    library_start(&cfg);
    library_start(&cfg);

    return 0;
}