#include <stdio.h>
#include "container_of.h"

typedef struct hook{
    int tag;
}hook_t;

typedef struct item{
    int id;
    char label[16];
    hook_t hook;  // Embedded child object
}item_t;


int main(){
    item_t item = {
        .id = 42,
        .label = "alpha",
        .hook = { .tag = 8}
    };

    // Step 1 pointer to the embedded member
    hook_t* hook_ptr = &item.hook;

    // step 2: recover parent pointer from member pointer
    item_t* recovered_parent_ptr = container_of(hook_ptr, item_t, hook);

    printf("offsetof(item_t, hook) = %zu bytes\n", offsetof(item_t, hook));
    printf("Original id:%d\n", item.id);
    printf("Received id: %d\n", recovered_parent_ptr->id);

    return 0;
}