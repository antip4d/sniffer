#ifndef DEVICE_MANAGER_H
#define DEVICE_MANAGER_H

#include <pcap.h>

int get_devices(pcap_if_t **devices_list, char *errbuf);
int show_devices(pcap_if_t *devices_list);
pcap_if_t* select_device(pcap_if_t *devices_list,int d_cnt);

#endif