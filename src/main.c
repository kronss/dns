#include "dns_server.h"

void	err_msg(char *line)
{
	perror(line);
	exit(1);
}

static void 	usage(void)
{
	ft_putendl("usage: ./dns-proxy-server configuration_file"); // -add -dell
	exit(0);
}

int 			main(int argc, char **argv)
{
	int fd;
	t_data data;

	if (argc != 2)
		usage();
	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		perror(argv[1]);
		exit(1);
	}

	read_conf_file(&data, fd);





/***********************************************************/
	printf("======== input data ========\n");
	printf("black_list:\n");
	t_host_name *tmp = data.head;
	while (tmp)
	{
		printf("%20s\n", tmp->host_name);
		tmp = tmp->next;
	}

	return (0);
}



// #include <stdio.h>
// #include <sys/socket.h>
// #include <stdlib.h>
// #include <netinet/in.h>
// #include <strings.h>
// #include <arpa/inet.h>

// #define ERROR -1

// void    error_die(char *err_msg)
// {
//     perror(err_msg);
//     exit(-1);
// }

// int     main(int argc, char **argv)
// {
//     int                 sockfd;
//     struct sockaddr_in  servaddr;

//     if ((sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == ERROR)
//         error_die("socket");

//     bzero(&servaddr, sizeof(servaddr));
//     servaddr.sin_family = AF_INET;
//     servaddr.sin_port = htons(53);


//     servaddr.sin_addr.s_addr = htonl(INADDR_ANY);


//     inet_aton("192.168.0.1", &(servaddr.sin_addr));

//     if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof servaddr) == ERROR)
//         error_die("bind");
//     return (0);
// }
// recvfrom







