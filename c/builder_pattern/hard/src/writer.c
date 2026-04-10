#include "writer.h"
#include <stdio.h>
#include <stdlib.h> // Why?
#include <string.h>

// Internal struct - hidden from everyone else
typedef struct{
    FILE *fp;
    int owns_fp; // 1 if we open it (and must close), 0 if borrowed(stdout)
} writer_t;

writer_handle_t writer_create_stdout(void){
    writer_t *w = malloc(sizeof(writer_t));
    w->fp = stdout;
    w->owns_fp = 0;
    return w;
}

writer_handle_t writer_create_file(const char* path){
    writer_t *w = malloc(sizeof(writer_t));
    w->fp = fopen(path, "a");
    if(!w->fp){
        free(w);
        return NULL;
    }
    w->owns_fp = 1;
    return w;
}

int writer_write(writer_handle_t h, const char* data, size_t len){
    writer_t *w = (writer_t*)h;
    return fwrite(data, 1, len, w->fp);
}

void writer_destroy(writer_handle_t h){
    writer_t *w = (writer_t*) h;
    if(w->owns_fp){
        fclose(w->fp);
    }
    free(w);
}