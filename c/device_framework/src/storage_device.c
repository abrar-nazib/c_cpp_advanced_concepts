#include <stdio.h>
#include "storage_device.h"

static void storage_start(device *dev){
    storage_device *disk = (storage_device*) dev;

    printf("Storage device start\n");
    printf("Name: %s\n", disk->base.name);
    printf("Capacity: %d GB\n", disk->capacity_gb);
}

void storage_device_init(storage_device *dev, const char* name, int capacity){
    dev->base.name = name;
    dev->base.start = storage_start;
    dev->capacity_gb = capacity;
}

