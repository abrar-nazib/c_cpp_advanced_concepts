#include "counter.h"
#include <stdio.h>

int main(void){
 counter_handle_t score_p1 = counter_create(0);
 counter_handle_t score_p2 = counter_create(1);
 
 counter_increment(score_p1);
 counter_increment(score_p2);

 printf("P1: %d\nP2: %d\n", counter_get(score_p1), counter_get(score_p2));


 counter_destroy(score_p1);
 counter_destroy(score_p2);
 return 0;
}