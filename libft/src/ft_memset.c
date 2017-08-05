/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 19:55:18 by ochayche          #+#    #+#             */
/*   Updated: 2016/11/21 19:55:19 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	if (len)
	{
		while (i < len)
		{
			*((unsigned char*)b + i) = (unsigned char)c;
			i++;
		}
	}
	return (b);
}
