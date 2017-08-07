#include "dns_server.h"

t_host_name		*create_host(char *line2)
{
	t_host_name	*new_elem;
	
	new_elem = malloc(sizeof(t_host_name));
	if (new_elem)
	{
		new_elem->host_name = ft_strdup(line2);
		new_elem->ip = 0;
		new_elem->next = NULL;
	}
	else
		err_msg("can not allocate memmory");
	return (new_elem);
}

void			add_host(t_host_name **head, char *line2)
{
	t_host_name	*tmp;

	tmp = *head;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = create_host(line2);
	}
	else
		*head = create_host(line2);
}

void			read_black_list(t_host_name **head, int fd)
{
	char 		*line;
	int			check;

	line = NULL;
	while ((check = get_next_line(fd, &line) > 0))
	{
		printf("%s\n", line); // verbose
		if (!ft_strncmp(line, "*.", 2))
			add_host(head, &line[2]);
		else
			break ;	
	}
	if (check == -1)
		err_msg(line);
}

void			read_wall(uint *wall_ip, int fd)
{
	


}




void			read_conf_file(t_data *data, int fd)
{
	char		*line;
	int			check;

	init_data(data, &line);
	while ((check = get_next_line(fd, &line) > 0))
	{
		if (!ft_strncmp(line, "## black_list:", 14))
			read_black_list(&data->head, fd);
		if (!ft_strncmp(line, "## wall", 7))
			read_wall(data->wall_ip, fd);
		else
		;
		printf("%s\n", line); // verbose
	}
	if (check == -1)
		err_msg(line);
	ft_strdel(&line);
}
