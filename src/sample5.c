#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>


#include <arpa/inet.h>  

#include <unistd.h>


#include "dns_server.h"

#define BUFF_SIZE 1500







int					main(int argc, char const *argv[])
{
	int							sock;
	int							recive_size;
	char						buffer[BUFF_SIZE];
	struct sockaddr_in			client_adress;
	// struct sockaddr_in			server_adress;
	socklen_t 					clnt_adrs_len;
	t_data 						data;

	sock = create_server();
	clnt_adrs_len = sizeof(client_adress);
	printf("sizeof(socklen_t) == %zu sizeof(client_adress) == %zu clnt_adrs_len == %d\n", sizeof(socklen_t), sizeof(client_adress), clnt_adrs_len);



	int i;

	printf("-----------------------------------------------------------------------\n");

	char qwerty[20];
	bzero (&qwerty, sizeof(qwerty));



	char incom_ip_address[16];
	bzero(&incom_ip_address, sizeof(incom_ip_address));
	
	struct dns_header *dns_h;

	int z;
	ushort id;

	while (1)
	{
		bzero(&buffer, sizeof(buffer));
		recive_size = recvfrom(sock, buffer, sizeof(buffer), 0, (struct sockaddr*)&client_adress, &clnt_adrs_len);
		if (recive_size == -1)
		{
			error("recvfrom() failed");
		}

			printf("recive_size == %d\n", recive_size);
		strcpy(incom_ip_address, inet_ntoa(client_adress.sin_addr));
		
		dns_h = (struct dns_header *)&buffer;
		id = dns_h->id;



		printf("id %hu\n", id);
		printf("clnt_adrs_len == %d\n", clnt_adrs_len);
		printf("recive_size == %d\n", recive_size);
		i = 0;
		printf("\n---------------------question-----------------------\n");
		while (i < recive_size)
		{
			printf("%d = [%c][%u] ", i, buffer[i], buffer[i]);
			++i;
			if (i % 12 == 0)
				printf("\n");
			
		}
		printf("\n");
		printf("IP   == %s\n", incom_ip_address);
		printf("PORT == %d\n", client_adress.sin_port);




		if (check_domain(buffer, &data))
		{
			printf("sendo to client\n");


			dns_h = (struct dns_header *)&buffer;
			dns_h->id = id;
			dns_h->qr = 1;
			// dns_h->rcode = 1;


			buffer[36] = (char)4;
			buffer[37] = (char)212;
			buffer[38] = (char)42;
			buffer[39] = (char)76;
			buffer[40] = (char)253;



		    	z = 0;

		        printf("\n---------------------answer-----------------------\n");
		        while (z < 100)
		        {
		            printf("%d = [%c][%hhu] ", z, buffer[z], buffer[z]);
		            ++z;
		            if (z % 12 == 0)
		                printf("\n");
		            
		        }
		        printf("\n");

			sendto(sock, buffer, sizeof(buffer), 0, (struct sockaddr*)&client_adress, clnt_adrs_len);
			continue ;
			// sendo();
		}



		

		



	

		



	}
	return (0);
}







