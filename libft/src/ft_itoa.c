/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 23:23:23 by ochayche          #+#    #+#             */
/*   Updated: 2016/11/29 23:23:27 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_strnumb(int numb)
{
	int			len;

	len = 0;
	if (1 <= numb && numb <= 9)
		return (1);
	if (numb < 0)
		len++;
	while (numb)
	{
		len++;
		numb = numb / 10;
	}
	return (len);
}

char			*ft_itoa(int number)
{
	char		*str;
	int			len;
	int			n;

	if (number == -2147483648)
		return (str = ft_strdup("-2147483648"));
	if (number == 0)
		return (str = ft_strdup("0"));
	len = ft_strnumb(number);
	str = (char*)malloc(sizeof(char) * (len + 1));
	if (str)
	{
		n = (number < 0) ? (number * -1) : (number);
		str[len] = '\0';
		while (len-- > 0)
		{
			str[len] = '0' + n % 10;
			n = n / 10;
		}
		if (number < 0)
			str[0] = '-';
		return (str);
	}
	return (NULL);
}
