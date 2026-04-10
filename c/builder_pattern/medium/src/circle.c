#include "shape.h"
#include "shape_internal.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Concrete struct: vtable pointer first, then circle-specific data.
typedef struct {
    shape_base_t base;
    double radius;
}circle_t;

// Implementation functions (static as they won't be available from other files)
static double circle_area(shape_handle_t s){
    circle_t *c = (circle_t*)s;
    return M_PI * c->radius * c->radius;
}

static double circle_perimeter(shape_handle_t s){
    circle_t *c = (circle_t*)s;
    return 2 * M_PI * c->radius;
}

static void circle_print(shape_handle_t s){
    circle_t *c = (circle_t*)s;
    printf("Circle(radius=%.2f)\n",c->radius);
}

static void circle_destroy(shape_handle_t s){
    free(s);
}

static const shape_ops_t circle_ops = {
    .area = circle_area,
    .perimeter = circle_perimeter,
    .print = circle_print,
    .destroy = circle_destroy
};

// Constructor
shape_handle_t shape_create_circle(double radius){
    circle_t *c = malloc(sizeof(circle_t));
    c->base.ops = &circle_ops;
    c->radius = radius;
    return (shape_handle_t*)c;
}

