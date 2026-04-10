#ifndef COUNTER_H
#define COUNTER_H

// Forward declaration. We don't define what's inside
typedef struct counter_s *counter_handle_t;

// Constructor
counter_handle_t counter_create(int initial_value);

// Operations
void counter_increment(counter_handle_t h);
int counter_get(counter_handle_t h);

// Destructor
void counter_destroy(counter_handle_t h);

#endif

