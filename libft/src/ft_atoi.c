/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 13:46:48 by ochayche          #+#    #+#             */
/*   Updated: 2016/11/27 13:46:49 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int		res;
	int		i;
	char	charge;

	res = 0;
	i = 0;
	charge = 1;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == 32)
		i++;
	while ((str[i] == '+' || str[i] == '-')
		&& ('0' <= str[i + 1] && str[i + 1] <= '9'))
	{
		if (str[i] == '-' && ('0' <= str[i + 1] && str[i + 1] <= '9'))
			charge = -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * charge);
}
