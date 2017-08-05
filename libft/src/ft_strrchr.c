/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 16:27:30 by ochayche          #+#    #+#             */
/*   Updated: 2016/11/26 16:27:31 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strrchr(const char *s, int c)
{
	int			i;
	const char	*res;

	res = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			res = &s[i];
		i++;
	}
	if (res)
		return ((char*)res);
	if (s[i] == '\0' && c == '\0')
		return ((char*)&s[i]);
	return (NULL);
}
