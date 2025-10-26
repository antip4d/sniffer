#ifndef PACKET_PROCESSOR_H
#define PACKET_PROCESSOR_H

#include <pcap.h>

void start_capture(pcap_if_t *device);
void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);

#endif