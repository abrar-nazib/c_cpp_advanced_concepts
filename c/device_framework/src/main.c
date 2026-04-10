#include "device.h"
#include "network_device.h"
#include "storage_device.h"

int main(){
    network_device eth0;
    storage_device disk0;

    network_device_init(&eth0, "eth0", 8080);
    storage_device_init(&disk0, "sda", 512);

    device_start((device*) &eth0);
    device_start((device*)&disk0);

    return 0;
}