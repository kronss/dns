#include "dns_server.h"

void				catch_question(t_data *data, int sockfd)
{
	int							recive_byte;
	int							n;
	int							send_byte;
	char						buffer[BUF_SZ];
	struct sockaddr_in			client;
	socklen_t					clnt_adrs_len;

	clnt_adrs_len = sizeof(client);

// /********************** verbose ******************************************************************/
// 	printf("sizeof(socklen_t) == %zu sizeof(client) == %zu clnt_adrs_len == %d\n", sizeof(socklen_t), sizeof(client), clnt_adrs_len);
// 	printf("-----------------------------------------------------------------------\n");
// 	char incom_ip_address[17]; // verbose?
// 	t_dns_header *dns_h;
// 	uint z;
// 	ushort id;
// /*************************************************************************************************/
	while (1)
	{
		bzero(&buffer, sizeof(buffer));

		// bzero(&incom_ip_address, sizeof(incom_ip_address)); // verbose
		
		recive_byte = recvfrom(sockfd, buffer, BUF_SZ, 0, (struct sockaddr*)&client, &clnt_adrs_len);
		if (recive_byte == -1)
			err_msg("recvfrom() failed");
// /********************** verbose ******************************************************************/
// 	printf("recive_byte == %d\n", recive_byte);
// 	strcpy(incom_ip_address, inet_ntoa(client.sin_addr));
	
// 	dns_h = (t_dns_header *)&buffer;

// 	printf("====================================DNS HEADER====================================\n");
// 	printf("%10hu - id; // identification number\n--\n", dns_h->id);

//  	printf("%10hhu - rd :1; // recursion desired\n", dns_h->rd);
// 	printf("%10hhu - tc :1; // truncated message\n", dns_h->tc);
// 	printf("%10hhu - aa :1; // authoritive answer\n", dns_h->aa);
// 	printf("%10hhu - opcode :4; // purpose of message\n", dns_h->opcode);
// 	printf("%10hhu - qr :1; // query/response flag\n--\n", dns_h->qr);
 
// 	printf("%10hhu - rcode :4; // response code\n", dns_h->rcode);
// 	printf("%10hhu - z :1; // its z! reserved\n", dns_h->z);
// 	printf("%10hhu - ra :1; // recursion available \n--\n", dns_h->ra);
 
// 	printf("%10hu - q_count; // number of question entries(2)\n", dns_h->q_count);
// 	printf("%10hu - ans_count; // number of answer entries(2)\n", dns_h->ans_count);
// 	printf("%10hu - auth_count; // number of authority entries(2)\n", dns_h->auth_count);
// 	printf("%10hu - add_count; // number of resource entries(2)\n", dns_h->add_count);
// 	printf(".................................................................................\n");

// 		z = 0;
// 		printf("\n---------------------question-----------------------\n");
// 		while (z < recive_byte)
// 		{
// 			printf("%u = [%c][%hhu] ", z, buffer[z], buffer[z]);
// 			++z;
// 			if (z % 12 == 0)
// 				printf("\n");
// 		}
// 		printf("\n");
// 		printf("IP   == %s\n", incom_ip_address);
// 		printf("PORT == %d\n", client.sin_port);
// /*************************************************************************************************/


		if (check_blacklist(buffer, data))
			send_refused(sockfd, buffer, recive_byte, &client);
		else
		{
			n = resend_query(data, buffer, recive_byte);



// /********************** verbose ******************************************************************/
// 	printf("====================================DNS HEADER====================================\n");
// 	printf("%10hu - id; // identification number\n--\n", dns_h->id);

//  	printf("%10hhu - rd :1; // recursion desired\n", dns_h->rd);
// 	printf("%10hhu - tc :1; // truncated message\n", dns_h->tc);
// 	printf("%10hhu - aa :1; // authoritive answer\n", dns_h->aa);
// 	printf("%10hhu - opcode :4; // purpose of message\n", dns_h->opcode);
// 	printf("%10hhu - qr :1; // query/response flag\n--\n", dns_h->qr);
 
// 	printf("%10hhu - rcode :4; // response code\n", dns_h->rcode);
// 	printf("%10hhu - z :1; // its z! reserved\n", dns_h->z);
// 	printf("%10hhu - ra :1; // recursion available \n--\n", dns_h->ra);
 
// 	printf("%10hu - q_count; // number of question entries(2)\n", dns_h->q_count);
// 	printf("%10hu - ans_count; // number of answer entries(2)\n", dns_h->ans_count);
// 	printf("%10hu - auth_count; // number of authority entries(2)\n", dns_h->auth_count);
// 	printf("%10hu - add_count; // number of resource entries(2)\n", dns_h->add_count);
// 	printf(".................................................................................\n");
// 	z = 0;
//     printf("\n---------------------answer-----------------------\n");
// 	    while (z < n)
// 	    {
//             printf("%d = [%c][%hhu] ", z, buffer[z], buffer[z]);
//             ++z;
//             if (z % 12 == 0)
//                 printf("\n");
            
//         }
//         printf("\n");
// /*************************************************************************************************/


			send_byte =	sendto(sockfd, buffer, n, 0, (struct sockaddr*)&client, clnt_adrs_len);
			if (send_byte == -1)
			{
				err_msg("sendto() failed");
			}
		}
	}
}
