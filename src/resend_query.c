#include "dns_server.h"

/*
** resend datagram to master dns server.
** get datagram with valid value.
** resend datagram to client
*/

int						resend_query(t_data *data, char *buffer, int recive_byte)
{
	int					sockfd;
	struct sockaddr_in	dest;
	socklen_t			dest_adrs_len;

	if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
		err_msg("client_socket() failed");

	bzero(&dest, sizeof(dest));
	dest.sin_family = AF_INET;
	dest.sin_addr.s_addr = inet_addr(data->dns_ip); //master dns servers
	dest.sin_port = htons(53);
	dest_adrs_len = sizeof(dest);

	if (sendto(sockfd, buffer, recive_byte , 0, (struct sockaddr*)&dest, sizeof(dest)) == -1)
		err_msg("sendto() failed");

	recive_byte = recvfrom(sockfd, buffer, BUF_SZ, 0, (struct sockaddr*)&dest, &dest_adrs_len);
	if (recive_byte == -1)
		err_msg("recvfrom() failed");

	if (close(sockfd) == -1)
		err_msg("close() failed");

	return (recive_byte);
}
