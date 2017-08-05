/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 16:19:52 by ochayche          #+#    #+#             */
/*   Updated: 2016/11/24 16:20:46 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *vdst, const void *vsrc, int ic, size_t n)
{
	size_t				i;
	unsigned char		*dst;
	const unsigned char	*src;
	unsigned char		c;

	dst = vdst;
	src = vsrc;
	c = ic;
	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		if (src[i] == c)
			return (&dst[++i]);
		i++;
	}
	return (0);
}
