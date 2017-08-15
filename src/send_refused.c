#include "dns_server.h"

/*
** set DNS_HEADER->rcode to ERROR
** return datagram with ERROR opcode to client
*/

void		send_refused(t_data *data, int sockfd, char *buffer, int recive_byte, struct sockaddr_in *client)
{
	t_dns_header 				*dns_h;
	socklen_t 					clnt_adrs_len;
	int							send_byte;

	clnt_adrs_len = sizeof(*client);

	dns_h = (t_dns_header *)buffer;
	dns_h->qr = 1; // set querry
	dns_h->rcode = 5; // set refused
	dns_h->ans_count = 0; //set number of answer entries

	send_byte =	sendto(sockfd, buffer, recive_byte, 0, (struct sockaddr*)client, clnt_adrs_len);
	if (send_byte == -1)
	{
		err_msg(data, "sendto() failed");
	}
}
