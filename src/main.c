#include "dns_server.h"

void				destruct(t_data *data)
{
	t_host_name		*node;
	t_host_name		*tmp;

	node = data->head;
	while (node != NULL)
	{
		tmp = node->next;
		ft_strdel(&node->host_name);
		ft_memdel((void **)&node);
		node = tmp;
	}
	data->head = NULL;
}

void				err_msg(t_data *data, char *line)
{
	destruct(data);
	perror(line);
	exit(1);
}

static void			usage(char *str)
{
	ft_putstr("usage: ");
	ft_putstr(str);
	ft_putstr(" configuration_file\n");
	exit(0);
}

int					main(int argc, char **argv)
{
	int				fd;
	int				sockfd;
	t_data			data;

	if (argc != 2)
		usage(argv[0]);

	init_data(&data);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		err_msg(&data, argv[1]);

	read_conf_file(&data, fd);

	sockfd = create_server(&data);

	catch_question(&data, sockfd);
	return (0);
}
