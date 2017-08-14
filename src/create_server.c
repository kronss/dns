#include "dns_server.h"

int						create_server(void)
{
	int					sockfd;
	struct sockaddr_in	server;
													
	if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
		err_msg("socket() failed");

	bzero(&server, sizeof(server));				
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	// server.sin_port = htons(53);
	server.sin_port = htons(5555); 

	if (bind(sockfd, (struct sockaddr *)&server, sizeof(server)) == -1)
	{
		close(sockfd);
		err_msg("bind() failed");
	}
	printf("sockfd1 == %d\n", sockfd);

	return (sockfd);
}
