#ifndef DNS_SERVER_H
# define DNS_SERVER_H

# include "libft.h"

# include <stdio.h>
# include <fcntl.h>


# include <stdio.h> //dell?

// # include <resolv.h> // lib for dns





#include <sys/socket.h>




typedef struct			s_host_name
{
	char				*host_name;
	uint 				ip;
	struct s_host_name	*next;
}						t_host_name;



typedef struct			s_data
{
	uint				wall_ip;
		

	struct s_host_name	*head;
}						t_data;




void			init_data(t_data *data, char **line);
void			read_conf_file(t_data *data, int fd);
void			err_msg(char *line);
#endif
