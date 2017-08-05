/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 21:34:49 by ochayche          #+#    #+#             */
/*   Updated: 2016/12/03 21:34:50 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	ft_strlowcase(str);
	if (str[i] >= 97 && str[i] <= 122)
		str[i] = (str[i] - 32);
	while (str[i] != '\0')
	{
		if ((str[i] >= ' ' && str[i] <= '/') ||
		(str[i] >= ':' && str[i] <= '@'))
		{
			if (str[i + 1] >= 'a' && str[i + 1] <= 'z')
			{
				str[i + 1] = (str[i + 1] - 32);
			}
		}
		i++;
	}
	return (str);
}
