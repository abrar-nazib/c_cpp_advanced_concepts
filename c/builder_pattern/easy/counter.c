#include <stdlib.h>
#include "counter.h"

struct counter_s{
    int value;
    int increment_count;
};

counter_handle_t counter_create(int initial_value){
    struct counter_s *c = malloc(sizeof(struct counter_s));
    c->value = initial_value;
    c->increment_count = 0;
    return c;
}

void counter_increment(counter_handle_t h){
    h->value++;
    h->increment_count++;
}

int counter_get(counter_handle_t h){
    return h->value;
}

void counter_destroy(counter_handle_t h){
    free(h);
}