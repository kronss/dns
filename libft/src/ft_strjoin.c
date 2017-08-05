/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 19:41:15 by ochayche          #+#    #+#             */
/*   Updated: 2016/11/28 19:41:16 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strjoin(char const *s1, char const *s2)
{
	char		*str;
	size_t		a;
	size_t		b;

	if (s1 && s2)
	{
		a = ft_strlen(s1);
		b = ft_strlen(s2);
		str = (char*)malloc(sizeof(char) * (a + b + 1));
		if (str)
		{
			*str = 0;
			ft_strcat(str, s1);
			ft_strcat(str, s2);
			return (str);
		}
	}
	return (0);
}
