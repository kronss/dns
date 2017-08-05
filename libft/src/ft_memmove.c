/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 19:44:04 by ochayche          #+#    #+#             */
/*   Updated: 2016/11/24 19:44:15 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*s;
	char		*d;

	s = (char *)src;
	d = (char *)dst;
	if (src > dst)
	{
		i = 0;
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	else
		while (n--)
			d[n] = s[n];
	return (dst);
}
