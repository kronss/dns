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

//DNS header structure
struct dns_header
{
    unsigned short id; // identification number						2
 
    unsigned char rd :1; // recursion desired
    unsigned char tc :1; // truncated message
    unsigned char aa :1; // authoritive answer
    unsigned char opcode :4; // purpose of message
    unsigned char qr :1; // query/response flag 					1
 
    unsigned char rcode :4; // response code
    unsigned char cd :1; // checking disabled
    unsigned char ad :1; // authenticated data
    unsigned char z :1; // its z! reserved
    unsigned char ra :1; // recursion available 					1
 
    unsigned short q_count; // number of question entries 			2
    unsigned short ans_count; // number of answer entries			2
    unsigned short auth_count; // number of authority entries		2
    unsigned short add_count; // number of resource entries			2
};




void    error(char *err_msg)
{
    perror(err_msg);
    exit(-1);
}

int		create_server()
{
	int	sock;
	struct addrinfo	hints, *res;

													// Criteria for address
	bzero(&hints, sizeof(hints));					// Zero out structure
	hints.ai_family = AF_UNSPEC;					// Any address family
	hints.ai_flags = AI_PASSIVE;					// Accept on any address/port
	hints.ai_socktype = SOCK_DGRAM;					// Only datagram socket
	hints.ai_protocol = IPPROTO_UDP;				// Only UDP socket

	// struct addrinfo *res = NULL; // List of server addresses
	if (getaddrinfo(NULL, "5555", &hints, &res))
		error("getaddrinfo() failed");



/*******************************************************************************/
	printf("Any address family %d\n" , hints.ai_family);
	printf("Accept on any address/port %d\n" , hints.ai_flags);
	printf("Only datagram socket %d\n", hints.ai_socktype);
	printf("Only UDP socket %d\n", hints.ai_protocol);
	printf("\n------------------------------------------------\n");
	printf("Any address family %d\n" , res->ai_family);
	printf("Accept on any address/port %d\n" , res->ai_flags);
	printf("Only datagram socket %d\n", res->ai_socktype);
	printf("Only UDP socket %d\n", res->ai_protocol);
/*******************************************************************************/

	if ((sock = socket(res->ai_family, res->ai_socktype, res->ai_protocol)) == -1)
		error("socket() failed");
	printf("sock == %d\n", sock);
	if (bind(sock, res->ai_addr, res->ai_addrlen) == -1)
	{
		close(sock);
		error("bind() failed");
	}
	freeaddrinfo(res);
	printf("bind confirmed\n");
	return (sock);
}




int 	check_list(char *str, t_data *data)
{

	char test[] = "ukr.net";

	if (ft_strstr(str, test))
	{
		return (1);
	}
	return (0);

}




int 	check_domain(char *buffer, t_data *data)
{
	char *str;
	char *tmp;

	str = ft_strsub(buffer, 1, ft_strlen(buffer));
	tmp = str;
	while (*tmp != '\0')
	{
		if (!ft_isprint(*tmp))
			*tmp = '.';
		tmp++;
	}
	printf("str == %s\nft_strlen(str) == %d\n", str, ft_strlen(str));





	if (check_list(str, data))
	{
		printf("black_list\n");
		ft_strdel(&str);
		return (1);
	}	
	else
	{
		/* if not contain in black list */
		printf("white_list\n");
		ft_strdel(&str);
		return (0);
	}
}







int					main(int argc, char const *argv[])
{
	int							sock;
	int							recive_size;
	char						buffer[BUFF_SIZE];
	struct sockaddr_in			client_adress;
	struct sockaddr_in			server_adress;
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

	while (1)
	{
		bzero(&buffer, sizeof(buffer));
		recive_size = recvfrom(sock, buffer, sizeof(buffer), 0, (struct sockaddr*)&client_adress, &clnt_adrs_len);
		if (recive_size == -1)
		{
			error("recvfrom() failed");
		}

			printf("recive_size == %d\n", recive_size);
			printf("datagram: %.*s\n", (int)recive_size, buffer);
		strcpy(incom_ip_address, inet_ntoa(client_adress.sin_addr));
		


		if (check_domain(&buffer[12], &data))
		{
			printf("sendo to client\n");


			dns_h = (struct dns_header *)&buffer;
			dns_h->qr = 1;


			buffer[36] = (char)4;
			buffer[37] = (char)212;
			buffer[38] = (char)42;
			buffer[39] = (char)76;
			buffer[40] = (char)253;



		    	z = 0;

		        printf("\n---------------------question-----------------------\n");
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



		printf("clnt_adrs_len == %d\n", clnt_adrs_len);
		printf("recive_size == %d\n", recive_size);
		i = 0;
		while (i < recive_size)
		{
			printf("%d = [%c][%d] ", i, buffer[i], buffer[i]);
			++i;
			if (i % 12 == 0)
				printf("\n");
			
		}
		printf("\n");

		



		printf("IP   == %s\n", incom_ip_address);
		printf("PORT == %d\n", client_adress.sin_port);

		



	}
	return (0);
}







