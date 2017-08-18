#include "dns_server.h"

static void			read_black_list(t_data *data, int fd)
{
	char			*line;
	int				check;
	int				i;

	i = 0;
	line = NULL;
	while (((check = get_next_line(fd, &line)) > 0))
	{
		if (strcmp(line, ""))
		{
			strcpy((data->blacklist)[i], line);
			i++;
		}
		else
			break ;
	}
	ft_strdel(&line);
	if (check == -1)
		err_msg("read file.conf failed");
}

static void			read_nameserver(t_data *data, char *dns_ip, int fd)
{
	char			*line;
	int				check;

	line = NULL;
	check = get_next_line(fd, &line);
	if (check == -1)
	{
		ft_strdel(&line);
		err_msg("read file.conf failed");
	}

	strcpy(dns_ip, line);
	ft_strdel(&line);
}

void				read_conf_file(t_data *data, int fd)
{
	char			*line;
	int				check;
	
	line = NULL;
	while (((check = get_next_line(fd, &line)) > 0))
	{
		if (!strcmp(line, "black_list:"))
			read_black_list(data, fd);
		else if (!strcmp(line, "nameserver:"))
			read_nameserver(data, data->dns_ip, fd);
	}
	ft_strdel(&line);

	if (check == -1)
		err_msg("read file.conf failed");

	if (close(fd) == -1)
		err_msg("close()");
}
