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
pcap_if_t* select_device(pcap_if_t *devices_list,int d_cnt)
{
    int choice; 
    printf("choose a device ");
    scanf("%d",&choice);
    if(choice < 0 || choice >= d_cnt)
    {
        printf("ERR");
        return NULL;
    }
    pcap_if_t *tek = devices_list;
    for(int i = 0; i < choice; i++)
    {
        tek = tek->next;
    }

    return tek;
}