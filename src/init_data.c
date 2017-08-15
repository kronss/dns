#include "dns_server.h"

void			init_data(t_data *data)
{
	bzero(data->wall_ip, sizeof(data->wall_ip));
	bzero(data->dns_ip, sizeof(data->dns_ip));

	data->head = NULL;
}
