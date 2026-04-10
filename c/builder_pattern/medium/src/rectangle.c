#include "shape.h"
#include "shape_internal.h"
#include <stdio.h>
#include <stdlib.h>

// Concrete struct: vtable pointer first, then rectangle-specific data.
typedef struct {
    shape_base_t base;
    double width;
    double height;
} rectangle_t;

// Implementation functions (static as they won't be available from other files)
static double rectangle_area(shape_handle_t s){
    rectangle_t *r = (rectangle_t*)s;
    return r->width * r->height;
}

static double rectangle_perimeter(shape_handle_t s){
    rectangle_t *r = (rectangle_t*)s;
    return 2 * (r->width + r->height);
}

static void rectangle_print(shape_handle_t s){
    rectangle_t *r = (rectangle_t*)s;
    printf("Rectangle(width=%.2f, height=%.2f)\n", r->width, r->height);
}

static void rectangle_destroy(shape_handle_t s){
    free(s);
}

static const shape_ops_t rectangle_ops = {
    .area = rectangle_area,
    .perimeter = rectangle_perimeter,
    .print = rectangle_print,
    .destroy = rectangle_destroy
};

// Constructor
shape_handle_t shape_create_rectangle(double width, double height){
    rectangle_t *r = malloc(sizeof(rectangle_t));
    if (r == NULL) {
        return NULL;
    }

    r->base.ops = &rectangle_ops;
    r->width = width;
    r->height = height;
    return (shape_handle_t)r;
}