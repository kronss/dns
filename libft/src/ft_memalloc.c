/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 17:46:49 by ochayche          #+#    #+#             */
/*   Updated: 2016/11/27 17:46:50 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memalloc(size_t size)
{
	void		*ptr;

	ptr = (void*)malloc(sizeof(size_t) * size);
	if (ptr)
		ft_bzero((void*)ptr, size);
	return ((void*)ptr);
}
