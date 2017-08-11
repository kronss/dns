#ifndef DNS_SERVER_H
# define DNS_SERVER_H

# include "libft.h"

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <netdb.h>
# include <arpa/inet.h>  
# include <unistd.h>




// # include <resolv.h> // lib for dns


# define BUF_SZ 1500
	

typedef struct			s_host_name
{
	char				*host_name;
	uint 				ip;
	struct s_host_name	*next;
}						t_host_name;



typedef struct			s_data
{
	char				wall_ip[17];
	char				dns_ip[17];	




	struct s_host_name	*head;
}						t_data;



//DNS header structure
typedef struct		s_dns_header
{
	unsigned short		id; // identification number				2
 
	unsigned char		rd :1; // recursion desired
	unsigned char		tc :1; // truncated message
	unsigned char		aa :1; // authoritive answer
	unsigned char		opcode :4; // purpose of message
	unsigned char		qr :1; // query/response flag 					1
 
	unsigned char		rcode :4; // response code
	unsigned char		cd :1; // checking disabled
	unsigned char		ad :1; // authenticated data
	unsigned char		z :1; // its z! reserved
	unsigned char		ra :1; // recursion available 					1
 
	unsigned short		q_count; // number of question entries 			2
	unsigned short		ans_count; // number of answer entries			2
	unsigned short		auth_count; // number of authority entries		2
	unsigned short		add_count; // number of resource entries			2
}					t_dns_header;



//Constant sized fields of query structure
struct QUESTION
{
    unsigned short qtype;
    unsigned short qclass;
};
 


//Constant sized fields of the resource record structure
struct R_DATA
{
    unsigned short type;
    unsigned short _class;
    unsigned int ttl;
    unsigned short data_len;
};

 
//Pointers to resource record contents
struct RES_RECORD
{
    unsigned char *name;
    struct R_DATA *resource;
    unsigned char *rdata;
};
 
//Structure of a Query
typedef struct
{
    unsigned char *name;
    struct QUESTION *ques;
} QUERY;


void				init_data(t_data *data, char **line);
void				read_conf_file(t_data *data, int fd);
void				err_msg(char *line);
int					create_server(void);
void				catch_question(t_data *data, int sockfd);
int					check_domain(char *buffer, t_data *data);

#endif

