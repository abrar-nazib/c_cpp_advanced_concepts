#ifndef SHAPE_INTERNAL_H
#define SHAPE_INTERNAL_H

#include "shape.h"

// Vtable: A struct of function pointers that every shape provides
typedef struct shape_ops {
    double (*area)(shape_handle_t s);
    double (*perimeter)(shape_handle_t s);
    void (*print)(shape_handle_t s);
    void (*destroy)(shape_handle_t s);
}shape_ops_t;
// shape_ops_t is the shorter, cleaner name. 
//If shape_ops was to be used instead of this, 
//struct keyword would have to be used every time, which is a bit verbose.

// The "base class". Every concrete shape struct must put this first
typedef struct shape_base{
    const shape_ops_t *ops;  // Expects a pointer
} shape_base_t;

#endif