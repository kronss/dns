/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_ptv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 11:47:50 by ochayche          #+#    #+#             */
/*   Updated: 2017/06/07 11:47:51 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi_ptv(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	if (!ft_isdigit(str[i]))
		return (-1);
	while (ft_isdigit(str[i]))
	{
		if (res > 214748364 || (res == 214748364 && str[i] >= '8'))
			return (-1);
		res = res * 10 + str[i] - '0';
		++i;
	}
	return (str[i] == '\0') ? (res) : (-1);
}
