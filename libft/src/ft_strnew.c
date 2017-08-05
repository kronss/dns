/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:26:48 by ochayche          #+#    #+#             */
/*   Updated: 2016/11/28 13:26:49 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	char	*ptr;

	ptr = (char*)malloc(sizeof(char) * (size + 1));
	if (ptr)
		ft_bzero(ptr, size + 1);
	return (ptr);
}
