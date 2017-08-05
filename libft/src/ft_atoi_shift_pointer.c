/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_shift_pointer.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 21:30:14 by ochayche          #+#    #+#             */
/*   Updated: 2017/03/03 21:30:15 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi_shift_pointer(char **str)
{
	int		res;
	int		i;
	int		charge;

	res = 0;
	i = 0;
	charge = 1;
	while ((9 <= (*str)[i] && (*str)[i] <= 13) || (*str)[i] == 32)
		i++;
	while (((*str)[i] == '+' || (*str)[i] == '-')
		&& ('0' <= (*str)[i + 1] && (*str)[i + 1] <= '9'))
	{
		if ((*str)[i] == '-' && ('0' <= (*str)[i + 1] && (*str)[i + 1] <= '9'))
			charge = -1;
		i++;
	}
	while ('0' <= (*str)[i] && (*str)[i] <= '9')
	{
		res = res * 10 + (*str)[i] - '0';
		i++;
	}
	*str = &((*str)[i]);
	return (res * charge);
}
