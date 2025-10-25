#ifndef DEVICE_MANAGER_H
#define DEVICE_MANAGER_H

#include <pcap.h>

int get_devices(pcap_if_t **devices_list, char *errbuf);
int show_devices(pcap_if_t *devices_list);

#endif