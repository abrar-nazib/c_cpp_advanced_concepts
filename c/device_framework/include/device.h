#ifndef DEVICE_H
#define DEVICE_H

typedef struct device device;

struct device{
    const char* name;
    void(*start)(device* dev);
};

void device_start(device *dev);
#endif