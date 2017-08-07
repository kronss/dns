// #include <stdio.h>
// #include <sys/socket.h>
// #include <stdlib.h>
// #include <netinet/in.h>
// #include <strings.h>
// #include <arpa/inet.h>





// int create_server(int port)
// {
// 	int sock;
// 	struct protoent *proto;
// 	struct sockaddr_in sin;



// 	proto = getprotobyname("tcp");
// 	if (proto == 0)
// 		return (-1);
// 	sock = socket(PF_INET, SOCK_STREAM, proto->p_proto);

// 	printf("socket == %d\n", sock);


// 	sin.sin_family = AF_INET;
// 	sin.sin_port = htons(port);

// 	printf("sin.sin_port %d\n", sin.sin_port);	

// 	sin.sin_addr.s_addr = htonl(INADDR_ANY);
// 	if (bind(sock, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
// 	{
// 		printf("bind error\n");
// 		exit(-1);
// 	}




// 	listen(sock, 42);

// 	return (sock);
// }

// int main(int ar, char **av)
// {
// 	int port;
// 	int sock;
// 	int cs;
// 	uint cslen;
// 	struct sockaddr_in csin;
// 	int 	r;
// 	char 	buf[1024];



// 	if (ar != 2)
// 		usage(av[0]);
// 	port = atoi(av[1]);
// 	sock = create_server(port);

// 	cs = accept(sock, (struct sockaddr *)&csin, &cslen);

// 	while ((r = read(cs, buf,  1023)) > 0)
// 	{	
// 		buf[r] = '\0';
// 		printf("recived %d bytes: [%s]\n", r, buf);
// 	}

// 	close(cs);
// 	close(sock);
// 	return 0;
// }





#include <netdb.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>

void    error(char *err_msg)
{
    perror(err_msg);
    exit(-1);
}


//     struct protoent {
//         char    *p_name;        /* официальное имя протокола */
//         char    **p_aliases;    /* список псевдонимов */
//         int     p_proto;        /* номер протокола */
// }


int     main(int ar, char **av)
{
    int					sd;
    struct protoent		proto;


	struct sockaddr_in	sa; 
	char				buffer[1024];
	

	ssize_t recsize;
	

	socklen_t fromlen;

	
	// memset(&sa, 0, sizeof sa);
	// sa.sin_family = AF_INET;
	// sa.sin_addr.s_addr = htonl(INADDR_ANY);
	// sa.sin_port = htons(7654);
	// fromlen = sizeof sa;






	proto = *getprotobyname("UDP");
	sd = socket( PF_INET, SOCK_DGRAM, proto.p_proto);
	if (sd == -1)
		error("can not create socket");

	bind ()




/*********************************************verbose*******************************/
	printf("socket desriptor %d\n", sd);
	// printf("%s\n", socklen_t);
	printf("официальное имя протокола %s\n", proto.p_name);
	printf("список псевдонимов        %s\n", (proto.p_aliases)[0]);
	printf("список псевдонимов        %s\n", (proto.p_aliases)[1]);
	printf("номер протокола           %d\n", proto.p_proto);
	printf("IPPROTO_UDP               %d\n", IPPROTO_UDP);
    return (0);
}



