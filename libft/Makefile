#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ochayche <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/21 20:49:37 by ochayche          #+#    #+#              #
#    Updated: 2016/11/21 20:49:46 by ochayche         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./inc/
SHELL = /bin/sh

SRC_DIR = src

#******************************************************************************#
# HEADER
#******************************************************************************#
INC_NAME = libft.h
INC_DIR = inc
INC = $(addprefix $(INC_DIR)/, $(INC_NAME))

#******************************************************************************#
# OBJECT/SOURCES
#******************************************************************************#
OBJ_NAME = ft_memset.o \
	ft_bzero.o \
	ft_memcpy.o \
	ft_memccpy.o \
	ft_memmove.o \
	ft_memchr.o \
	ft_memcmp.o \
	ft_strlen.o \
	ft_strdup.o \
	ft_strcpy.o \
	ft_strncpy.o \
	ft_strcat.o \
	ft_strncat.o \
	ft_strlcat.o \
	ft_strchr.o \
	ft_strrchr.o \
	ft_strstr.o \
	ft_strnstr.o \
	ft_strcmp.o \
	ft_strncmp.o \
	ft_atoi.o \
	ft_isalpha.o \
	ft_isdigit.o \
	ft_isalnum.o \
	ft_isascii.o \
	ft_isprint.o \
	ft_toupper.o \
	ft_tolower.o \
	ft_memalloc.o \
	ft_memdel.o \
	ft_strnew.o \
	ft_strdel.o \
	ft_strclr.o \
	ft_striter.o \
	ft_striteri.o \
	ft_strmap.o \
	ft_strmapi.o \
	ft_strequ.o \
	ft_strnequ.o \
	ft_strsub.o \
	ft_strjoin.o \
	ft_strtrim.o \
	ft_strsplit.o \
	ft_itoa.o \
	ft_itoa_base.o \
	ft_putchar.o \
	ft_putstr.o \
	ft_putendl.o \
	ft_putnbr.o \
	ft_putchar_fd.o \
	ft_putstr_fd.o \
	ft_putendl_fd.o \
	ft_putnbr_fd.o \
	ft_strlowcase.o \
	ft_strcapitalize.o \
	ft_strupcase.o \
	ft_swap.o \
	ft_lstnew.o \
	ft_lstdelone.o \
	ft_lstdel.o \
	ft_lstadd.o \
	ft_lstiter.o \
	ft_lstmap.o \
	ft_wrdcount_del.o \
	ft_chrcount.o \
	ft_chrposn.o \
	get_next_line.o \
	ft_atoi_shift_pointer.o \
	ft_atohex_shift_pointer.o \
	ft_atohex.o \
	ft_max.o \
	ft_atol.o \
	q_sort.o \
	ft_atoi_ptv.o \
	ft_abs.o
OBJ_DIR = .obj
OBJ = $(addprefix $(OBJ_DIR)/, $(OBJ_NAME))

#******************************************************************************#
.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) $(INC)
	ar rc $(NAME) $? $(INC)
	ranlib $(NAME)


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) -c $(CFLAGS) $? -o $@


$(OBJ_DIR):
	mkdir $(OBJ_DIR)


clean:
	rm -rf $(OBJ_DIR)


fclean: clean
	rm -f $(NAME)


re: fclean all
