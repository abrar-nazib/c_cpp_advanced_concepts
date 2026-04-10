#include "formatter.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Internal struct - holds the writer handle from layer 1
typedef struct{
    writer_handle_t writer;
} formatter_t;

formatter_handle_t formatter_create(writer_handle_t writer){
    formatter_t *f = malloc(sizeof(formatter_t));
    f->writer = writer;
    return f;
}

static const char* level_string(fmt_level_t level){
    switch(level){
        case FMT_LEVEL_INFO:  return " INFO";
        case FMT_LEVEL_WARN:  return " WARN";
        case FMT_LEVEL_ERROR: return "ERROR";
        default: return "?";
    }
}

void formatter_format(formatter_handle_t h, fmt_level_t level, const char* message){
    formatter_t *f = (formatter_t* )h;

    //Format: [TIME] LEVEL: message
    char buffer[512];

    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);
    char time_str[32];
    strftime(time_str, sizeof(time_str), "%H:%M:%S", tm_info);

    int len = snprintf(buffer, sizeof(buffer), "[%s] %s: %s\n", time_str, level_string(level), message);

    // Hand off to layer 1. We don't know or care if it's a file or stdout
    writer_write(f->writer, buffer, len);
}


void formatter_destroy(formatter_handle_t h){
    formatter_t *f = (formatter_t*) h;
    // We do not destroy the writer here. The owner of the writer
    // Or whoever passed it to formatter_create is responsible for it.
    // This is design choice
    free(f);
}
