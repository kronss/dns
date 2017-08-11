#include "dns_server.h"



int					check_list(char *str, t_data *data)
{
	char test[] = "ukr.net";

	if (ft_strstr(str, test))
	{
		return (1);
	}
	return (0);

}



int					check_domain(char *buffer, t_data *data)
{
	char			*str;
	char			*tmp;
	char			*buf;

	buf = &buffer[12]; // skip header;

	str = ft_strsub(buf, 1, ft_strlen(buf));
	tmp = str;
	while (*tmp != '\0')
	{
		if (!ft_isprint(*tmp))
			*tmp = '.';
		tmp++;
	}

	printf("str == %s\nft_strlen(str) == %d\n", str, ft_strlen(str)); // verbose


	if (check_list(str, data))
	{
		printf("black_list\n");
		ft_strdel(&str);
		return (1);
	}	
	else
	{
		/* if not contain in black list */
		printf("white_list\n");
		ft_strdel(&str);
		return (0);
	}
}
