#ifndef WRITER_H
#define WRITER_H

#include <stddef.h> 

// Layer 1 handle: Writes raw bytes to some destination
typedef void* writer_handle_t;

// Two flavors of writer
writer_handle_t writer_create_stdout(void);
writer_handle_t writer_create_file(const char* path);

// Generic write function. Works regardless of destination
int writer_write(writer_handle_t w, const char* data, size_t len);

// Generic write function
void writer_destroy(writer_handle_t w);

#endif