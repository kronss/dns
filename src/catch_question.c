#include "dns_server.h"

void				catch_question(t_data *data, int sockfd)
{
	int							recive_byte;
	int							n;
	int							send_byte;
	char						buffer[BUF_SZ];
	struct sockaddr_in			client;
	socklen_t					clnt_adrs_len;
	int 						pid;

	clnt_adrs_len = sizeof(client);

	while (1)
	{
		bzero(&buffer, sizeof(buffer));
	
		recive_byte = recvfrom(sockfd, buffer, BUF_SZ, 0, (struct sockaddr*)&client, &clnt_adrs_len);
		if (recive_byte == -1)
			err_msg("recvfrom() failed");
		pid = fork();
		if (pid == -1)
			err_msg("fork() failed");

		if (pid == 0)
		{
			if (check_blacklist(buffer, data))
					send_refused(data, sockfd, buffer, recive_byte, &client);
			else
			{
				n = resend_query(data, buffer, recive_byte);
				send_byte =	sendto(sockfd, buffer, n, 0, (struct sockaddr*)&client, clnt_adrs_len);
				if (send_byte == -1)
				{
					err_msg("sendto() failed");
				}
			}
			close(sockfd);
			exit(0);
		}
	}
}
