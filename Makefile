CC = gcc
CFLAGS =   -I./$(LIB_DIR_INC) -I./$(INC_DIR) 

#-lresolv

SHELL = /bin/sh

################################################################################
# libft
################################################################################

LIB_DIR =		libft
LIB_DIR_INC =	libft/inc 
LIB =			libft.a

################################################################################
# main
################################################################################
NAME = 			dns-proxy-server

#********* -INC
INC_NAME =		dns_server.h
INC_DIR =		inc
INC = $(addprefix $(INC_DIR)/, $(INC_NAME))

#********* -OBJ
OBJ_DIR =		./.obj
OBJ = $(subst .c,.o,$(subst $(SRC_DIR)/,$(OBJ_DIR)/,$(SRC)))

#********* -SRC
SRC_DIR =		./src
SRC = $(addprefix $(SRC_DIR)/, $(SRC_NAME))
SRC_NAME =		main.c \
				init_data.c \
				read_conf_file.c \
				create_server.c \
				check_blacklist.c \
				catch_question.c \
				send_refused.c \
				resend_query.c

# add .c file ---->
################################################################################
#	RULES
################################################################################

.PHONY: all clean fclean re

all: $(LIB) $(NAME)

$(NAME): $(OBJ) $(INC)
	$(CC) $(CFLAGS) $(OBJ) -L./$(LIB_DIR) -lft -o $(NAME)
	@echo "\033[33m'$(NAME)' compiling done.\033[0m"

$(LIB):
	@make -C $(LIB_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) -c $(CFLAGS) $? -o $@

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIB_DIR)/ clean

fclean: clean
	rm -f $(NAME)
	rm -f $(LIB_DIR)/$(LIB)

re: fclean all

rewq:
	rm -rf $(OBJ_DIR)
	rm -f $(NAME)

rew: rewq all

r:	all
	./$(NAME) file.conf
