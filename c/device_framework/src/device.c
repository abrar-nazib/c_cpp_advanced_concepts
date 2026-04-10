#include <stdio.h>
#include "device.h"

void device_start(device *dev){
    if(!dev || !dev->start){
        printf("Invalid device\n");
        return;
    }

    dev->start(dev);
}