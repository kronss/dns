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
// #include <sys/types.h> 


#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <netinet/in.h>

 #include <unistd.h>
#include <errno.h>



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
    int check;
    struct protoent		proto;
	struct sockaddr_in	sa;
	socklen_t fromlen;

	char buffer[1024];
	ssize_t recsize;



	proto = *getprotobyname("UDP");
	sd = socket( PF_INET, SOCK_DGRAM, proto.p_proto );
	if (sd == -1)
		error("can not create socket");

	bzero(&sa, sizeof(sa));
	
	sa.sin_family = AF_INET;
	sa.sin_addr.s_addr = htonl(INADDR_ANY);
	sa.sin_port = htons(7654);
	fromlen = sizeof(sa);

	// printf("INADDR_ANY %d\n", INADDR_ANY);
	check = bind(sd, (struct sockaddr *)&sa, sizeof sa);
	if (check == -1)
	{
		perror("error bind failed");
		close(sd);
		exit(EXIT_FAILURE);
	}	
	printf("confirm: port #%d opened", sa.sin_port);


	for ( ; ; )
	{
		recsize = recvfrom(sd, (void*)buffer, sizeof buffer, 0, (struct sockaddr*)&sa, &fromlen);
		if (recsize < 0)
		{
			fprintf(stderr, "%s\n", strerror(errno));
			exit(EXIT_FAILURE);
    	}
		printf("recsize: %d\n ", (int)recsize);
		sleep(1);
		printf("datagram: %.*s\n", (int)recsize, buffer);
	}

	/*********************************************** verbose *******************************************************/
	printf("\n--------------------------------------------------------\n");
	printf("socket desriptor %d\n", sd);


	printf("\n--------------------------------------------------------\n");
	printf("официальное имя протокола %s\n", proto.p_name);
	printf("список псевдонимов        %s\n", (proto.p_aliases)[0]);
	printf("список псевдонимов        %s\n", (proto.p_aliases)[1]);
	printf("номер протокола           %d\n", proto.p_proto);
	printf("IPPROTO_UDP               %d\n", IPPROTO_UDP);


	
	printf("\n--------------------------------------------------------\n");
	printf("sizeof = %zu\n", sizeof(sa));
	printf(".sin_family             %d sizeof(sa.sin_family) %zu\n", sa.sin_family, sizeof(sa.sin_family));
	printf(".sin_port               %d sizeof(sa.sin_port) %zu\n", sa.sin_port, sizeof(sa.sin_port));
	printf(".sin_addr.s_addr        %d sizeof(sa.sin_addr) %zu\n", sa.sin_addr.s_addr, sizeof(sa.sin_addr.s_addr));
    return (0);
}



