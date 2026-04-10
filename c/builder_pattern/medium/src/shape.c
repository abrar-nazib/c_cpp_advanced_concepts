#include "shape.h"
#include "shape_internal.h"
#include <stdlib.h>

// Generic dispatcher functions: Cast handle to base, call vtable.
double shape_area(shape_handle_t s){
    shape_base_t *base = (shape_base_t*) s;
    return base->ops->area(s);
}
// Concept notes
// Use -> when you have pointer to the object. Not the object itself.
// object.field
// pointer->field


double shape_perimeter(shape_handle_t s){
    shape_base_t *base = (shape_base_t*) s;
    return base->ops->perimeter(s);
}

void shape_print(shape_handle_t s){
    shape_base_t *base = (shape_base_t*) s;
    base->ops->print(s);
}

void shape_destroy(shape_handle_t s){
    shape_base_t *base = (shape_base_t*) s;
    base->ops->destroy(s);
}