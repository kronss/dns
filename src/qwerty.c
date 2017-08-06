#include <pcap.h> 
#include <stdio.h> 
#include <stdlib.h>
#include <errno.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <arpa/inet.h> 
#include <netinet/if_ether.h> 


void another_callback(u_char *arg, const struct pcap_pkthdr* pkthdr, const u_char* packet) 
{ 
	int i=0; 
	static int count=0; 

	printf("Packet Count: %d\n", ++count);             /* Количество пакетов */
	printf("Recieved Packet Size: %d\n", pkthdr->len); /* Длина заголовка */
	printf("Payload:\n");                              /* А теперь данные */
	for(i=0;i<pkthdr->len;i++) { 
		if(isprint(packet[i]))            /* Проверка, является ли символ печатаемым */
			printf("%c ",packet[i]);       /* Печать символа */
		else 
			printf(" . ",packet[i]);       /* Если символ непечатаемый, вывод . */
		if((i%16==0 && i!=0) || i==pkthdr->len-1) 
			printf("\n"); 
	}
}


void 	my_callback(u_char *args, const struct pcap_pkthdr* pkthdr, const u_char* packet) 
{ 
	static int count = 1; 


	fprintf(stdout, "%3d, ", count);
	fflush(stdout);
	count++; 
}

int main(int argc,char **argv) 
{ 
	int i;
	char *dev; 
	char errbuf[PCAP_ERRBUF_SIZE]; 
	pcap_t* descr; 
	const u_char *packet; 
	struct pcap_pkthdr hdr;
	struct ether_header *eptr; /* net/ethernet.h */ 
	struct bpf_program fp;     /*выражение фильтрации в составленном виде */ 
	bpf_u_int32 maskp;         /*маска подсети */ 
	bpf_u_int32 netp;          /* ip */ 

	if(argc != 2)
	{
		fprintf(stdout, "Usage: %s \"expression\"\n" ,argv[0]);
		return 0;
	} 

	/* Получение имени устройства */
	dev = pcap_lookupdev(errbuf);

	if (dev == NULL)
	{
		fprintf(stderr, "%s\n", errbuf);
		exit(1);
	} 
	/* Получение сетевого адреса и маски сети для устройства */ 
	pcap_lookupnet(dev, &netp, &maskp, errbuf); 

	/* открытие устройства в  promiscuous-режиме */ 
	descr = pcap_open_live(dev, BUFSIZ, 1,-1, errbuf); 
	if (descr == NULL)
	{
		printf("pcap_open_live(): %s\n", errbuf);
		exit(1);
	} 

	/* теперь составляется выражение фильтрации*/ 
	if (pcap_compile(descr, &fp, argv[1], 0, netp) == -1)
	{
		fprintf(stderr, "Error calling pcap_compile\n");
		exit(1);
	} 

	/* применение фильтра*/ 
	if (pcap_setfilter(descr, &fp) == -1)
	{
		fprintf(stderr, "Error setting filter\n");
		exit(1);
	} 

	/* функция обратного вызова используется в цикле */ 
	pcap_loop(descr, -1, my_callback, NULL); 
	return 0; 
}
