#include <stdio.h>
#include "../include/device_manager.h"

int main()
{
    pcap_if_t *devices = NULL;
    char errbuf[PCAP_ERRBUF_SIZE];
    int d_cnt = 0;
    printf("Start_sniffer");
    if(get_devices(&devices,errbuf) == -1)
    {
        printf("ERR\n");
        return -1;
    }
    printf("Your devices");
    d_cnt = show_devices(devices);
    if(d_cnt == 0)
    {
        printf("not found\n");
    }
    printf("Find devices %d\n", d_cnt);
    pcap_if_t *selected = select_device(devices,d_cnt);
    if(selected != NULL)
    {
        printf("Selected: %s\n", selected->name);
    }
    while(getchar() != '\n');
    printf("Enter...   ");
    getchar();  
    return 0;
}