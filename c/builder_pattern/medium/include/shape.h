#ifndef SHAPE_H
#define SHAPE_H

// Opaque handle type. The user can hold this but can't dereference it.
typedef void* shape_handle_t;

// Constructors. Each returns the same opaque handle type.
shape_handle_t shape_create_circle(double radius);
shape_handle_t shape_create_rectangle(double width, double height);
shape_handle_t shape_create_triangle(double base, double height);

// Generic operation. Works on any type
double shape_area(shape_handle_t s);
double shape_perimeter(shape_handle_t s);
void shape_print(shape_handle_t s);

// Destructor
void shape_destroy(shape_handle_t s);

#endif

