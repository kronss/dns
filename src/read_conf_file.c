#include "dns_server.h"

static t_host_name	*create_host(t_data *data, char *line2)
{
	t_host_name		*new_elem;
	
	new_elem = malloc(sizeof(t_host_name));
	if (new_elem)
	{
		new_elem->host_name = ft_strdup(line2);
		new_elem->ip = 0;
		new_elem->next = NULL;
	}
	else
		err_msg(data, "can not allocate memmory");
	return (new_elem);
}

static void			add_host(t_data *data, t_host_name **head, char *line2)
{
	t_host_name		*tmp;

	tmp = *head;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = create_host(data, line2);
	}
	else
		*head = create_host(data, line2);
}

static void			read_black_list(t_data *data, t_host_name **head, int fd)
{
	char			*line;
	int				check;

	line = NULL;
	while (((check = get_next_line(fd, &line)) > 0))
	{
		if (ft_strcmp(line, ""))
			add_host(data, head, line);
		else
			break ;
	}
	ft_strdel(&line);
	if (check == -1)
		err_msg(data, "read file.conf failed");
}

static void			read_wall(t_data *data, char *wall_ip, int fd)
{
	char 			*line;
	int				check;

	line = NULL;
	check = get_next_line(fd, &line);
	if (check == -1)
		err_msg(data, "read file.conf failed");

	ft_strcpy(wall_ip, line);
	ft_strdel(&line);
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
		err_msg(data, "read file.conf failed");
	}

	ft_strcpy(dns_ip, line);
	ft_strdel(&line);
}

void				read_conf_file(t_data *data, int fd)
{
	char			*line;
	int				check;
	
	line = NULL;
	while (((check = get_next_line(fd, &line)) > 0))
	{
		if (!ft_strcmp(line, "black_list:"))
			read_black_list(data, &data->head, fd);
		else if (!ft_strcmp(line, "redirect:"))
			read_wall(data, data->wall_ip, fd);
		else if (!ft_strcmp(line, "nameserver:"))
			read_nameserver(data, data->dns_ip, fd);
	}
	ft_strdel(&line);

	if (check == -1)
		err_msg(data, "read file.conf failed");

	if (close(fd) == -1)
		err_msg(data, "close()");
}
