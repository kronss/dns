#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>



void	usage(char *str)
{
	printf("usage: %s <adr> <port>\n", str);
	exit(-1);
}


int create_client(char *addr, int port)
{
	int sock;
	struct protoent *proto;
	struct sockaddr_in sin;



	proto = getprotobyname("tcp");
	if (proto == 0)
		return (-1);
	sock = socket(PF_INET, SOCK_STREAM, proto->p_proto);

	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = inet_addr(addr);
	if (connect(sock, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
	{
		printf("connect error\n");
		exit(-1);
	}




	listen(sock, 42);

	return (sock);
}

int main(int ar, char **av)
{
	int port;
	int sock;
	int cs;
	uint cslen;
	struct sockaddr_in csin;
	int 	r;
	char 	buf[1024];



	if (ar != 3)
		usage(av[0]);
	port = atoi(av[2]);
	sock = create_client(av[1], port);
	write(sock, "hello\n", 7);

	close(cs);
	close(sock);
	return 0;
}
