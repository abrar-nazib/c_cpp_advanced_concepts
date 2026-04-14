#include "library.h"

static library_cfg_t *g_cfg;

void library_start(library_cfg_t *cfg){
    g_cfg = cfg;
    // When something hapens
    if(g_cfg->on_event){
        g_cfg->on_event(42, g_cfg->ctx); // Call the user's function
    }
}

