#include "logger.h"
#include "formatter.h"
#include "writer.h"
#include <stdlib.h>

// Internal struct. Holds handles to both layers below.
// We need to remember the writer too because we own it and must destroy it when logger is destroyed
typedef struct{
    writer_handle_t writer;
    formatter_handle_t formatter;
} logger_t;

logger_handle_t logger_create_console(void){
    logger_t *l = malloc(sizeof(logger_t));

    // Build Layer 1: stdout writer
    l->writer = writer_create_stdout();

    // Build Layer 2: formatter that uses our writer
    l->formatter = formatter_create(l->writer);

    return l;
}

logger_handle_t logger_create_file(const char* path){
    logger_t *l = malloc(sizeof(logger_t));

    // Build layer 1: file writer
    l->writer = writer_create_file(path);
    if(!l->writer){
        free(l);
        return NULL;
    }

    // Build layer 2: formatter that our file writer
    l->formatter = formatter_create(l->writer);

    return l;
}

void logger_info(logger_handle_t h, const char* msg){
    logger_t *l = (logger_t*)h;
    formatter_format(l->formatter, FMT_LEVEL_INFO, msg);
}

void logger_warn(logger_handle_t h, const char* msg){
    logger_t *l = (logger_t*)h;
    formatter_format(l->formatter, FMT_LEVEL_WARN, msg);
}

void logger_error(logger_handle_t h, const char* msg){
    logger_t *l = (logger_t*)h;
    formatter_format(l->formatter, FMT_LEVEL_ERROR, msg);
}

void logger_destroy(logger_handle_t h){
    logger_t *l = (logger_t*) h;
    
    // Tear down in REVERSE order of creation (top to bottom)
    formatter_destroy(l->formatter);
    writer_destroy(l->writer);
    free(l); // Free our own struct
}