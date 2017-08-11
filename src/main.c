#include "dns_server.h"

void				err_msg(char *line)
{
	perror(line);
	exit(1);
}

static void			usage(void)
{
	ft_putendl("usage: ./dns-proxy-server configuration_file"); // -add -dell
	exit(0);
}

int					main(int argc, char **argv)
{
	int				fd;
	t_data			data;

	if (argc != 2)
		usage();

	if ((fd = open(argv[1], O_RDONLY)) == -1)
		err_msg(argv[1]);
	read_conf_file(&data, fd);








/***********************************************************/ //verbose
	printf("======== input data ========\n");
	printf("black_list:\n");
	t_host_name *tmp = data.head;
	while (tmp)
	{
		printf("%20s\n", tmp->host_name);
		tmp = tmp->next;
	}
	printf("redirect:\n%s\n", data.wall_ip);
	printf("nameserver:\n%s\n", data.dns_ip);
/***********************************************************/
	return (0);
}
