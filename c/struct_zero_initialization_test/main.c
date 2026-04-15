#include <stdio.h>

typedef struct init_test{
    int a;
    double b;
    const char* c;
}init_test_t;


int main(){
    init_test_t t = {.a=22,};

    printf("%d %.2l %s\n", t.a, t.b, t.c);

    return 0;
}