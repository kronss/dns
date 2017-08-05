/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wrdcount_del.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 22:31:36 by ochayche          #+#    #+#             */
/*   Updated: 2016/12/05 22:31:52 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_wrdcount_del(char const *s, char c)
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
