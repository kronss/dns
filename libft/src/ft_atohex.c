/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atohex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 13:28:59 by ochayche          #+#    #+#             */
/*   Updated: 2017/03/04 13:29:02 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_iter_power(int nb, int power)
{
	int i;
	int result;

	i = 1;
	result = 1;
	if (power < 0)
	{
		return (0);
	}
	if (power == 0)
	{
		return (1);
	}
	while (i <= power)
	{
		result = result * nb;
		i++;
	}
	return (result);
}

static int			size_hexa(char *tmp)
{
	int i;

	i = 0;
	while (('0' <= *tmp && *tmp <= '9') || ('a' <= *tmp && *tmp <= 'f') ||
	('A' <= *tmp && *tmp <= 'F'))
	{
		tmp++;
		i++;
	}
	return (i);
}

int					ft_atohex(char *str)
{
	int res;
	int power;
	int i;

	res = 0;
	if ((str[0] == '0') && (str[1] == 'x' || str[1] == 'X'))
	{
		i = 2;
		power = size_hexa(&str[i]);
		while (('0' <= str[i] && str[i] <= '9') ||
		('a' <= str[i] && str[i] <= 'f') ||
		('A' <= str[i] && str[i] <= 'F'))
		{
			power--;
			if ('0' <= str[i] && str[i] <= '9')
				res = (res + (str[i] - '0') * ft_iter_power(16, power));
			else if ('a' <= str[i] && str[i] <= 'f')
				res = (res + (str[i] - 'a' + 10) * ft_iter_power(16, power));
			else if ('A' <= str[i] && str[i] <= 'F')
				res = (res + (str[i] - 'A' + 10) * ft_iter_power(16, power));
			i++;
		}
	}
	return (res);
}
