#include "dns_server.h"

void		send_refused(int sockfd, char *buffer, int recive_byte, struct sockaddr_in *client, socklen_t *clnt_adrs_len)
{
	t_dns_header 				*dns_h;
	int							send_byte;

	// clnt_adrs_len = sizeof(client);

	printf("sendo erro msg to client\n");

	dns_h = (t_dns_header *)buffer;
			
	dns_h->qr = 1;
	dns_h->opcode = 0;
	dns_h->aa = 0;
	dns_h->tc = 0;
	dns_h->rd = 0;

	dns_h->ra = 0;
	dns_h->z = 0;
	dns_h->rcode= 5; // set refused

/********************** verbose ******************************************************************/
	int z;
	printf("====================================DNS HEADER====================================\n");
	printf("%10hu - id; // identification number\n--\n", dns_h->id);

 	printf("%10hhu - rd :1; // recursion desired\n", dns_h->rd);
	printf("%10hhu - tc :1; // truncated message\n", dns_h->tc);
	printf("%10hhu - aa :1; // authoritive answer\n", dns_h->aa);
	printf("%10hhu - opcode :4; // purpose of message\n", dns_h->opcode);
	printf("%10hhu - qr :1; // query/response flag\n--\n", dns_h->qr);
 
	printf("%10hhu - rcode :4; // response code\n", dns_h->rcode);
	printf("%10hhu - z :1; // its z! reserved\n", dns_h->z);
	printf("%10hhu - ra :1; // recursion available \n--\n", dns_h->ra);
 
	printf("%10hu - q_count; // number of question entries(2)\n", dns_h->q_count);
	printf("%10hu - ans_count; // number of answer entries(2)\n", dns_h->ans_count);
	printf("%10hu - auth_count; // number of authority entries(2)\n", dns_h->auth_count);
	printf("%10hu - add_count; // number of resource entries(2)\n", dns_h->add_count);
	printf(".................................................................................\n");
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
/*************************************************************************************************/

	send_byte =	sendto(sockfd, buffer, recive_byte, 0, (struct sockaddr*)client, *clnt_adrs_len);
	if (send_byte == -1)
	{
		err_msg("sendto() failed");
	}
}
