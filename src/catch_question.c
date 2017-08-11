#include "dns_server.h"

void				catch_question(t_data *data, int sockfd)
{
	int							recive_size;
	char						buffer[BUF_SZ];
	struct sockaddr_in			client_adress;
	// struct sockaddr_in			server_adress;
	socklen_t 					clnt_adrs_len;

	clnt_adrs_len = sizeof(client_adress);

//verbose
	printf("sizeof(socklen_t) == %zu sizeof(client_adress) == %zu clnt_adrs_len == %d\n", sizeof(socklen_t), sizeof(client_adress), clnt_adrs_len);
	printf("-----------------------------------------------------------------------\n");

	char incom_ip_address[17]; // verbose?

	
	t_dns_header *dns_h;

	int z;
	ushort id;
//=======


	while (1)
	{
		bzero(&buffer, sizeof(buffer));
		
		bzero(&incom_ip_address, sizeof(incom_ip_address)); // verbose
		
		recive_size = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)&client_adress, &clnt_adrs_len);
		if (recive_size == -1)
		{
			err_msg("recvfrom() failed");
		}

			printf("recive_size == %d\n", recive_size);
		strcpy(incom_ip_address, inet_ntoa(client_adress.sin_addr));
		
		dns_h = (t_dns_header *)&buffer;
		id = dns_h->id;



		printf("id %hu\n", id);
		printf("clnt_adrs_len == %d\n", clnt_adrs_len);
		printf("recive_size == %d\n", recive_size);
		z = 0;
		printf("\n---------------------question-----------------------\n");
		while (z < recive_size)
		{
			printf("%d = [%c][%u] ", z, buffer[z], buffer[z]);
			++z;
			if (z % 12 == 0)
				printf("\n");
			
		}
		printf("\n");
		printf("IP   == %s\n", incom_ip_address);
		printf("PORT == %d\n", client_adress.sin_port);




		if (check_domain(buffer, data))
		{
			printf("sendo to client\n");


			dns_h = (t_dns_header *)&buffer;
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

		    //TODO valid sendo();
			sendto(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)&client_adress, clnt_adrs_len);
			// continue ;
		}
		else
		{
			//TODO	send answer to 8.8.8.8
			//		recv answer
			//		sendo to client
		}
	}
}
