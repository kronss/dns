#include "dns_server.h"

int				create_server(void)
{
	int			sock;
	struct addrinfo	hints;
	struct addrinfo *res;
													// Criteria for address
	bzero(&hints, sizeof(hints));					// Zero out structure
	hints.ai_family = AF_UNSPEC;					// Any address family
	hints.ai_flags = AI_PASSIVE;					// Accept on any address/port
	hints.ai_socktype = SOCK_DGRAM;					// Only datagram socket
	hints.ai_protocol = IPPROTO_UDP;				// Only UDP socket

	res = NULL; // List of server addresses
	if (getaddrinfo(NULL, "5555", &hints, &res))
		err_msg("getaddrinfo() failed");

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
		err_msg("socket() failed");
	printf("sock == %d\n", sock);
	if (bind(sock, res->ai_addr, res->ai_addrlen) == -1)
	{
		close(sock);
		err_msg("bind() failed");
	}
	freeaddrinfo(res);
	printf("bind confirmed\n");
	return (sock);
}
