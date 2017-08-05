/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 11:54:49 by ochayche          #+#    #+#             */
/*   Updated: 2017/03/23 11:54:50 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	q_sort(array, 0, max - 1)
*/

#include "libft.h"

void		q_sort(int *s_arr, int first, int last)
{
	int i;
	int j;
	int x;

	i = first;
	j = last;
	x = s_arr[(first + last) / 2];
	while (i <= j)
	{
		while (s_arr[i] < x)
			i++;
		while (s_arr[j] > x)
			j--;
		if (i <= j)
		{
			if (s_arr[i] > s_arr[j])
				ft_swap(&s_arr[i], &s_arr[j]);
			i++;
			j--;
		}
	}
	if (i < last)
		q_sort(s_arr, i, last);
	if (first < j)
		q_sort(s_arr, first, j);
}
