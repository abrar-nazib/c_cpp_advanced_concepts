#ifndef STORAGE_DEVICE_H
#define STORAGE_DEVICE_H

#include "device.h"

typedef struct storage_device{
    device base;
    int capacity_gb;
}storage_device;

void storage_device_init(storage_device *dev, const char* name, int capacity);

#endif