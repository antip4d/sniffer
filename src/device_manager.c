#include "../include/pcap.h"
#include <pcap.h>


int get_devices(pcap_if_t **devices_list, char *errbuf)
{
    if(pcap_findalldevs(devices_list,errbuf) == -1)
    {
        return -1;
    }
    return 0;
}

int show_devices(pcap_if_t *devices_list)
{
    int cnt = 0;
    pcap_if_t *tek = devices_list;
    while(tek != NULL)
    {   
        printf("%d %s",cnt, tek->name);
        if(tek->description)
        {
            printf("- %s\n", tek->description);
        }
        cnt++;
        tek = tek->next;
    }
    return cnt;
}