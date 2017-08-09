#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#include <unistd.h>

#define BUFF_SIZE 1500

//DNS header structure
struct DNS_HEADER
{
    unsigned short id; // identification number
 
    unsigned char rd :1; // recursion desired
    unsigned char tc :1; // truncated message
    unsigned char aa :1; // authoritive answer
    unsigned char opcode :4; // purpose of message
    unsigned char qr :1; // query/response flag
 
    unsigned char rcode :4; // response code
    unsigned char cd :1; // checking disabled
    unsigned char ad :1; // authenticated data
    unsigned char z :1; // its z! reserved
    unsigned char ra :1; // recursion available
 
    unsigned short q_count; // number of question entries
    unsigned short ans_count; // number of answer entries
    unsigned short auth_count; // number of authority entries
    unsigned short add_count; // number of resource entries
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
	hints.ai_socktype = SOCK_DGRAM;		 			// Only datagram socket
	hints.ai_protocol = IPPROTO_UDP;				// Only UDP socket

	// struct addrinfo *res = NULL; // List of server addresses
	if (getaddrinfo(NULL, "5487", &hints, &res))
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

int					main(int argc, char const *argv[])
{
	int							sock;
	int							recive_size;
	char						buffer[BUFF_SIZE];
	struct sockaddr_storage		client_adress;
	socklen_t 					clnt_adrs_len;

	sock = create_server();
	clnt_adrs_len = sizeof(client_adress);
	printf("sizeof(socklen_t) == %zu sizeof(client_adress) == %zu clnt_adrs_len == %d\n", sizeof(socklen_t), sizeof(client_adress), clnt_adrs_len);



	int i;

	while (1)
	{
		bzero(&buffer, sizeof(buffer));
		recive_size = recvfrom(sock, buffer, sizeof(buffer), 0, (struct sockaddr*)&client_adress, &clnt_adrs_len);
		if (recive_size == -1)
		{
			error("recvfrom() failed");
		}
		
		i = 0;

		while (i < clnt_adrs_len)
		{
			printf("[%2d] ", buffer[i]);
			if (i % 16 == 0)
				printf("\n");
			++i;
		}
		


		printf("%d\n", recive_size);
		printf("datagram: %.*s\n", (int)recive_size, buffer);








		// if(decode_msg(&msg, buffer, recive_size) != 0)
		// {
		// 	continue;
		// }




	}
	return (0);
}







