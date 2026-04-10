#include "logger.h"
#include <stdio.h>

int main(void){
    // Create a console logger.
    // Behind te scenes: writer_create_stdout() -> formatter_create(writer) -> logger
    // Three layers of handles.
    logger_handle_t console = logger_create_console();

    logger_info(console, "Application Started");
    logger_warn(console, "Disk space getting low");
    logger_error(console, "Failed to connect to server");

    printf("\n ---- Now logging to a file ---\n\n");

    // Create a file logger. Same API, completely different backend.
    logger_handle_t file_log = logger_create_file("app.log");
    if(!file_log){
        fprintf(stderr, "Could not open log file\n");
        logger_destroy(console);
        return 1;
    }

    logger_info(file_log, "This goes to app.log");
    logger_warn(file_log, "Not visible in terminal");
    logger_error(file_log, "But you can cat app.log to see it");

    // Cleanup
    logger_destroy(console);
    logger_destroy(file_log);

    printf("Run: cat app.log to see the file output\n");
    return 0;
}