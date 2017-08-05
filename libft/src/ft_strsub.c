/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 20:19:34 by ochayche          #+#    #+#             */
/*   Updated: 2016/12/03 20:19:41 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
		return (0);
	str = (char*)malloc(sizeof(char) * (len + 1));
	if (str)
	{
		i = 0;
		while (i < len)
			str[i++] = s[start++];
		str[i] = '\0';
		return (str);
	}
	else
		return (NULL);
}
