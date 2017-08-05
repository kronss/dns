/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 11:36:58 by ochayche          #+#    #+#             */
/*   Updated: 2017/01/03 11:36:59 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** !!!ATTENTION!!!
** `line` must be initialized to NULL before first call of function
** have a nice day!
*/

#include "libft.h"

static t_lst				*add_struct(int fd)
{
	t_lst			*new_lst;

	if (!(new_lst = malloc(sizeof(t_lst))))
		return (NULL);
	new_lst->fd = fd;
	new_lst->cut = NULL;
	new_lst->next = NULL;
	return (new_lst);
}

static t_lst				*get_struct(t_lst **head, int fd)
{
	t_lst			*tmp;

	tmp = (*head);
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		if (tmp->next)
			tmp = tmp->next;
		else
			return (tmp->next = add_struct(fd));
	}
	return (*head = add_struct(fd));
}

static int					check(char **cut, char **line)
{
	int				i;
	char			*tmp;

	tmp = NULL;
	i = -1;
	if (*cut && (**cut))
	{
		*line = ft_strdup(*cut);
		ft_strdel(cut);
	}
	if (*line)
		while ((*line)[++i] != '\0')
			if ((*line)[i] == '\n')
			{
				tmp = ft_strdup(*line);
				ft_strdel(line);
				*line = ft_strsub(tmp, 0, i);
				*cut = ft_strdup(&tmp[i + 1]);
				ft_strdel(&tmp);
				return (1);
			}
	return (0);
}

static int					join_to_line(char **cut, char *buf, char **line)
{
	char			*tmp;

	if (!(*cut) && !(*line))
		*line = ft_strdup(buf);
	else if (*cut)
	{
		tmp = ft_strdup((*cut));
		ft_strdel(cut);
		*line = ft_strjoin(tmp, buf);
		ft_strdel(&tmp);
	}
	else
	{
		tmp = ft_strdup(*line);
		ft_strdel(line);
		*line = ft_strjoin(tmp, buf);
		ft_strdel(&tmp);
	}
	return (check(cut, line));
}

int							get_next_line(const int fd, char **line)
{
	static t_lst	*head = NULL;
	t_lst			*lst;
	char			buf[BUFF_SIZE + 1];
	int				ret;

	if (!(lst = get_struct(&head, fd)) || fd < 0 || BUFF_SIZE == 0
		|| line == NULL)
		return (-1);
	ft_strdel(line);
	if ((check(&lst->cut, line)))
		return (1);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		if (join_to_line(&lst->cut, buf, line))
			break ;
	}
	if (*line)
		return (1);
	*line = ft_strdup("");
	return (0);
}
