/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 10:06:43 by ochayche          #+#    #+#             */
/*   Updated: 2016/11/25 10:06:44 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memchr(const void *str, int c, size_t n)
{
	size_t				i;
	const unsigned char	*s;

	s = str;
	i = 0;
	while (i < n)
	{
		if (s[i] == (unsigned char)c)
			return ((void*)&s[i]);
		i++;
	}
	return (0);
}
