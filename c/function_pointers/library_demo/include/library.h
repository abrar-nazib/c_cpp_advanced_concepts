#ifndef LIBRARY_H
#define LIBRARY_H

typedef void (*on_event_fn)(int event_id, void *ctx);

typedef struct{
    on_event_fn on_event;
    void *ctx;
}library_cfg_t;

void library_start(library_cfg_t *cfg);

#endif