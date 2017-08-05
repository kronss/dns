/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 22:56:35 by ochayche          #+#    #+#             */
/*   Updated: 2016/11/25 22:56:36 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	n;

	j = 0;
	n = ft_strlen(dst);
	i = n;
	if (size > n)
	{
		while (src[j] != '\0' && j < size && i < (size - 1))
			dst[i++] = src[j++];
		dst[i] = '\0';
		return (n + ft_strlen(src));
	}
	else
		return (ft_strlen(src) + size);
}
