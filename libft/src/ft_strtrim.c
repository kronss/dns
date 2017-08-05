/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 20:20:58 by ochayche          #+#    #+#             */
/*   Updated: 2016/11/28 20:20:59 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (s)
	{
		i = 0;
		j = (ft_strlen(s) - 1);
		while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && (s[i] != 0))
			i++;
		while ((s[j] == ' ' || s[j] == '\t' || s[j] == '\n') && (s[i] != 0))
			j--;
		str = ft_strnew(j - i + 1);
		if (str)
			return (str = ft_strncpy(str, &s[i], j - i + 1));
	}
	return (0);
}
