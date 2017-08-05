/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 20:13:14 by ochayche          #+#    #+#             */
/*   Updated: 2016/12/03 20:13:15 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcat(char *dst, const char *src)
{
	int		n;
	int		i;

	n = ft_strlen(dst);
	i = 0;
	while (src[i] != '\0')
	{
		dst[n] = src[i];
		n++;
		i++;
	}
	dst[n] = '\0';
	return (dst);
}
