#ifndef DNS_SERVER_H
# define DNS_SERVER_H

# include "libft.h"

# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <netdb.h>
# include <arpa/inet.h>  

# define BUF_SZ 512


typedef struct			s_host_name
{
	char				*host_name;
	uint				ip;
	struct s_host_name	*next;
}						t_host_name;

typedef struct			s_data
{
	char				wall_ip[17];
	char				dns_ip[17];	
	struct s_host_name	*head;
}						t_data;

typedef struct			s_dns_header
{
	unsigned short		id;			// identification number			2 byte
 
	unsigned char		rd :1;		// recursion desired
	unsigned char		tc :1;		// truncated message
	unsigned char		aa :1;		// authoritive answer
	unsigned char		opcode :4;	// purpose of message
	unsigned char		qr :1;		// query/response flag				1 byte

	unsigned char		rcode :4;	// response code
	unsigned char		z :3;		// its z! reserved
	unsigned char		ra :1;		// recursion available				1 byte

	unsigned short		q_count;	// number of question entries		2 byte
	unsigned short		ans_count;	// number of answer entries			2 byte
	unsigned short		auth_count;	// number of authority entries		2 byte
	unsigned short		add_count;	// number of resource entries		2 byte
}						t_dns_header;

void				init_data(t_data *data, char **line);
void				read_conf_file(t_data *data, int fd);
void				err_msg(char *line);
int					create_server(void);
void				catch_question(t_data *data, int sockfd);
int					check_blacklist(char *buffer, t_data *data);
void				send_refused(int sockfd, char *buffer, int recive_byte, struct sockaddr_in *client);
int					resend_query(t_data *data, char *buffer, int recive_byte);

#endif
