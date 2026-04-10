#ifndef LOGGER_H
#define LOGGER_H

// Layer 3 handle: high-level convenience API.
typedef void* logger_handle_t;

// Two ways to create a logger
logger_handle_t logger_create_console(void);
logger_handle_t logger_create_file(const char* path);

// Convenient logging functions
void logger_info(logger_handle_t l, const char* msg);
void logger_warn(logger_handle_t l, const char* msg);
void logger_error(logger_handle_t l, const char* msg);

void logger_destroy(logger_handle_t l);

#endif