#include <stdio.h>
#include "network_device.h"


static void network_start(device *dev){
    network_device *net = (network_device*) dev;
    
    printf("Network device start\n");
    printf("Name: %s\n", net->base.name);
    printf("Port: %d\n", net->port);
}

void network_device_init(network_device *dev, const char* name, int port){
    dev->base.name = name;
    dev->base.start = network_start;
    dev->port = port;
}