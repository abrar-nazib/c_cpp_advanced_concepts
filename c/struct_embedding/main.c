#include <stdio.h>

typedef struct device{
    const char* name;
    void (*start)(struct deice* dev);
}device;

void generic_start(device* dev){
    printf("Starting device: %s\n", dev->name);
}

typedef struct network_device{
    device base;
    int port;
}network_device;

void network_start(device *dev){
    network_device *net = (network_device *) dev;

    printf("Network device start\n");
    printf("Name: %s\n", net->base.name);
    printf("Port: %d\n", net->port);
}

int main(){
    network_device eth0 = {
        .base = {
            .name = "eth0",
            .start = network_start
        },
        .port = 8080
    };

    device *dev = (device*) &eth0;
    dev->start(dev);
}