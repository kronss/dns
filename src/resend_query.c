#include "dns_server.h"

int						resend_query(t_data *data, char *buffer, int recive_byte)
{
	int					sockfd;
	struct sockaddr_in	dest;
	socklen_t			dest_adrs_len;
	int					send_byte;
	t_dns_header 		*dns_h;

	if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
		err_msg("client_socket() failed");

	bzero(&dest, sizeof(dest));				
	dest.sin_family = AF_INET;
	dest.sin_addr.s_addr = inet_addr(data->dns_ip); //dns servers	
	dest.sin_port = htons(53);

	// dns_h = (t_dns_header *)buffer;
	// dns_h->qr = 0;	 //This is a query
 //    dns_h->opcode = 0; //This is a standard query
 //    dns_h->aa = 0; //Not Authoritative
 //    dns_h->tc = 0; //This message is not truncated
 //    dns_h->rd = 1; //Recursion Desired
    
 //    dns_h->ra = 0; //Recursion not available! hey we dont have it (lol)
 //    dns_h->z = 0;
 //    dns_h->rcode = 0;

 //    // dns_h->q_count = htons(1); //we have only 1 question
 //    dns_h->ans_count = 0;
 //    dns_h->auth_count = 0;
 //    dns_h->add_count = 0;




    send_byte = sendto(sockfd, buffer, recive_byte , 0, (struct sockaddr*)&dest, sizeof(dest));
    if (send_byte == -1)
    {
        err_msg("sendto() failed");
    }


	
	//Receive the answer
	dest_adrs_len = sizeof(dest);

	recive_byte = recvfrom(sockfd, buffer, BUF_SZ, 0, (struct sockaddr*)&dest, &dest_adrs_len);
	if (recive_byte == -1)
    {
        err_msg("recvfrom() failed");
    }
    if (close(sockfd) == -1)
    	err_msg("close() failed");

	return (recive_byte);
}
