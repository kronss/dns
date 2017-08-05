//#include "dns_server.h"


#include <stdlib.h>

     #include <sys/types.h>
     #include <netinet/in.h>
     #include <arpa/nameser.h>
     #include <resolv.h>


static usage(void)
{
//	ft_putstr("usage: ./dns_server host_name\n"); // -add -dell
	exit(0);
}

int main(int argc, char **argv)
{
	if (argc == 1)
		usage();



    ns_get16("1234567890");





	return 0;
}
