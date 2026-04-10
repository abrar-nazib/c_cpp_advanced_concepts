#ifndef NETWORK_DEVICE_H
#define NETWORK_DEVICE_H

#include "device.h"

typedef struct network_device{
    device base;
    int port;
}network_device;

void network_device_init(network_device *dev, const char* name, int port);

#endif