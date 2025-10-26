#include "../include/packet_processor.h"
#include <stdio.h>


struct eth
{
    u_char dst[6];
    u_char src[6];
    u_char type;
};
void packet_handler(u_char *user, const struct pcap_pkthdr *header, const u_char *packet)
{
    printf("Byte: %d\n",header->len);
    struct eth *e = (struct eth*)packet;
    printf("From: %.2X:%.2X:%.2X:%.2X:%.2X:%.2X\n", e->src[0], e->src[1], e->src[2],e->src[3], e->src[4], e->src[5]);
    printf("To:   %.2X:%.2X:%.2X:%.2X:%.2X:%.2X\n", e->dst[0], e->dst[1], e->dst[2], e->dst[3], e->dst[4], e->dst[5]);
}
void start_capture(pcap_if_t *device)
{
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle = pcap_open_live(device->name,65535,1,1000,errbuf);
    if(handle == NULL)
    {
        printf("ERR\n");
        return;
    }
    printf("Started capture %s\n", device->name);
    pcap_loop(handle,0,packet_handler, NULL);
    pcap_close(handle);
}