#include "shape.h"
#include "shape_internal.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Concrete struct: vtable pointer first, then triangle-specific data.
typedef struct {
    shape_base_t base;
    double base_length;
    double height;
} triangle_t;

// Implementation functions (static as they won't be available from other files)
static double triangle_area(shape_handle_t s){
    triangle_t *t = (triangle_t*)s;
    return 0.5 * t->base_length * t->height;
}

static double triangle_perimeter(shape_handle_t s){
    triangle_t *t = (triangle_t*)s;
    double hypotenuse = sqrt(t->base_length * t->base_length + t->height * t->height);
    return t->base_length + t->height + hypotenuse;
}

static void triangle_print(shape_handle_t s){
    triangle_t *t = (triangle_t*)s;
    printf("Triangle(base=%.2f, height=%.2f)\n", t->base_length, t->height);
}

static void triangle_destroy(shape_handle_t s){
    free(s);
}

static const shape_ops_t triangle_ops = {
    .area = triangle_area,
    .perimeter = triangle_perimeter,
    .print = triangle_print,
    .destroy = triangle_destroy
};

// Constructor
shape_handle_t shape_create_triangle(double base, double height){
    triangle_t *t = malloc(sizeof(triangle_t));
    if (t == NULL) {
        return NULL;
    }

    t->base.ops = &triangle_ops;
    t->base_length = base;
    t->height = height;
    return (shape_handle_t)t;
}