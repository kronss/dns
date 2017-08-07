#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>



void	usage(char *str)
{
	printf("usage: %s <port>\n", str);
	exit(-1);
}


int create_server(int port)
{
	int sock;
	struct protoent *proto;
	struct sockaddr_in sin;



	proto = getprotobyname("tcp");
	if (proto == 0)
		return (-1);
	sock = socket(PF_INET, SOCK_STREAM, proto->p_proto);

	printf("socket == %d\n", sock);


	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);

	printf("sin.sin_port %d\n", sin.sin_port);	

	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(sock, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
	{
		printf("bind error\n");
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



	if (ar != 2)
		usage(av[0]);
	port = atoi(av[1]);
	sock = create_server(port);

	cs = accept(sock, (struct sockaddr *)&csin, &cslen);

	while ((r = read(cs, buf,  1023)) > 0)
	{	
		buf[r] = '\0';
		printf("recived %d bytes: [%s]\n", r, buf);
	}

	close(cs);
	close(sock);
	return 0;
}
