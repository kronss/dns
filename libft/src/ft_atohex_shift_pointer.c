/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atohex_shift_pointer.c                          :+:      :+:    :+:   */
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

int					ft_atohex_shift_pointer(char **str)
{
	int res;
	int power;

	res = 0;
	if ((**str == '0') && ((*str)[1] == 'x' || (*str)[1] == 'X'))
	{
		(*str) += 2;
		power = size_hexa(*str);
		while (('0' <= **str && **str <= '9') ||
		('a' <= **str && **str <= 'f') ||
		('A' <= **str && **str <= 'F'))
		{
			power--;
			if ('0' <= **str && **str <= '9')
				res = (res + (**str - '0') * ft_iter_power(16, power));
			else if ('a' <= **str && **str <= 'f')
				res = (res + (**str - 'a' + 10) * ft_iter_power(16, power));
			else if ('A' <= **str && **str <= 'F')
				res = (res + (**str - 'A' + 10) * ft_iter_power(16, power));
			(*str)++;
		}
	}
	return (res);
}
