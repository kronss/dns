/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delnode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 11:36:58 by ochayche          #+#    #+#             */
/*   Updated: 2017/01/03 11:36:59 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_delnode(t_lst **head, t_lst *lst)
{
	t_lst		*tmp;

	if (*head == lst)
	{
		if ((*head)->next == NULL)
		{
			ft_strdel(&(*head)->cut);
			ft_memdel((void **)head);
			return ;
		}
		tmp = (*head)->next;
		ft_strdel(&(*head)->cut);
		ft_memdel((void **)head);
		*head = tmp;
		return ;
	}
	tmp = *head;
	while (tmp->next != NULL && tmp->next != lst)
		tmp = tmp->next;
	if (tmp->next == NULL)
		return ;
	tmp->next = tmp->next->next;
	ft_strdel(&tmp->cut);
	ft_memdel((void **)tmp);
}



