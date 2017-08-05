/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 22:57:51 by ochayche          #+#    #+#             */
/*   Updated: 2016/12/03 22:57:52 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *first;
	t_list *nxt_lst;

	if (!lst || !f)
		return (0);
	first = f(lst);
	nxt_lst = first;
	while (lst->next != 0)
	{
		lst = lst->next;
		nxt_lst->next = f(lst);
		nxt_lst = nxt_lst->next;
	}
	return (first);
}
