/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 12:24:17 by ochayche          #+#    #+#             */
/*   Updated: 2016/11/29 12:24:18 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t		ft_wrd_cnt(char const *s, char c)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	if (s)
	{
		while (s[i] != '\0')
		{
			while (s[i] == c && s[i] != '\0')
				i++;
			if (s[i] != c && s[i] != '\0')
			{
				n++;
				while (s[i] != c && s[i] != '\0')
					i++;
			}
		}
		return (n);
	}
	return (0);
}

static	size_t		ft_lttr_cnt(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

char				**ft_strsplit(char const *s, char c)
{
	size_t	wrd_n;
	size_t	i;
	char	**array;

	if (s)
	{
		i = 0;
		wrd_n = ft_wrd_cnt(s, c);
		array = (char**)malloc(sizeof(char*) * (wrd_n + 1));
		if (!array)
			return (0);
		while (i < wrd_n)
		{
			while (*s == c && *s != '\0')
				s++;
			array[i] = ft_strsub(s, 0, ft_lttr_cnt(s, c));
			while (*s != c && *s != '\0')
				s++;
			i++;
		}
		array[i] = 0;
		return (array);
	}
	return (0);
}
