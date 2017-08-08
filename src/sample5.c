#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#include <unistd.h>





#define BUFF_SIZE 1500

void    error(char *err_msg)
{
    perror(err_msg);
    exit(-1);
}



int					main(int argc, char const *argv[])
{
	int				sock;
	int 			err;
	fd_set			rset;
	int				byte;
	char			buffer[BUFF_SIZE];
	
	// Construct the server address structure
	struct addrinfo	hints, *res;

												// Criteria for address
	bzero(&hints, sizeof(hints));					// Zero out structure
	hints.ai_family = AF_UNSPEC;					// Any address family
	hints.ai_flags = AI_PASSIVE;					// Accept on any address/port
	hints.ai_socktype = SOCK_DGRAM;				// Only datagram socket
	hints.ai_protocol = IPPROTO_UDP;				// Only UDP socket




	// struct addrinfo *res = NULL; // List of server addresses
	if ((err = getaddrinfo(NULL, "8080", &hints, &res)))
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




	while (1)
	{
		bzero(&buffer, sizeof(buffer));
		byte = recvfrom(sock, buffer, sizeof(buffer), 0, );



	}
	return (0);
}
