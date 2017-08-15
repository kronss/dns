#include "dns_server.h"

int					check_list(char *str, t_host_name *tmp)
{
	while (tmp)
	{
		if (ft_strstr(str, tmp->host_name))
		{
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

int					check_blacklist(char *buffer, t_data *data)
{
	char			*str;
	char			*tmp;
	char			*buf;

	buf = &buffer[12]; // skip header datagram;

	str = ft_strsub(buf, 1, ft_strlen(buf));
	tmp = str;
	
	while (*tmp != '\0')
	{
		if (!ft_isprint(*tmp))
			*tmp = '.';
		tmp++;
	}

	if (check_list(str, data->head))
	{
		ft_strdel(&str);
		return (1); // black_list
	}
	else
	{
		ft_strdel(&str);
		return (0);
	}
}
