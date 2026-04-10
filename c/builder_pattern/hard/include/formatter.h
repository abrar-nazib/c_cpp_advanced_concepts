#ifndef FORMATTER_H
#define FORMATTER_H

#include "writer.h"

// Layer 2 handle: takes a message + level, formats it, sends to a writer.
typedef void* formatter_handle_t;

typedef enum{
    FMT_LEVEL_INFO,
    FMT_LEVEL_WARN,
    FMT_LEVEL_ERROR
}fmt_level_t;

formatter_handle_t formatter_create(writer_handle_t writer);

void formatter_format(formatter_handle_t f, fmt_level_t level, const char *message);

void formatter_destroy(formatter_handle_t f);

#endif