/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 22:09:46 by ochayche          #+#    #+#             */
/*   Updated: 2016/12/03 22:09:47 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;
	void	*c;

	new = (t_list*)malloc(sizeof(t_list) * 1);
	if (!new)
		return (NULL);
	if (content == NULL)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		c = (void*)malloc(sizeof(void) * (content_size + 1));
		ft_memcpy(c, content, content_size);
		new->content = c;
		new->content_size = content_size;
	}
	new->next = NULL;
	return (new);
}
