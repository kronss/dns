/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 19:27:07 by ochayche          #+#    #+#             */
/*   Updated: 2016/11/26 19:27:08 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strnstr(const char *big, const char *lit, size_t len)
{
	size_t		i;
	size_t		j;
	size_t		k;

	i = 0;
	if (lit[0] == '\0')
		return ((char*)big);
	while (big[i] && i <= len)
	{
		j = 0;
		k = i;
		while ((big[k++] == lit[j++]) && (k <= len))
		{
			if (lit[j] == '\0')
				return ((char*)&big[i]);
		}
		i++;
	}
	return (0);
}
