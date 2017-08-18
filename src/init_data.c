#include "dns_server.h"

void			init_data(t_data *data)
{
	bzero(data->dns_ip, sizeof(data->dns_ip));
	bzero(data->blacklist, sizeof(data->blacklist));

	data->head = NULL;
}
