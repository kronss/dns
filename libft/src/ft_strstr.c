/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 17:42:32 by ochayche          #+#    #+#             */
/*   Updated: 2016/11/26 17:42:45 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strstr(const char *big, const char *little)
{
	size_t		i;
	size_t		j;
	size_t		k;
	const char	*ptr;

	i = 0;
	ptr = 0;
	if (little[0] == '\0')
		return ((char*)big);
	while (big[i] != '\0')
	{
		j = 0;
		ptr = &big[i];
		k = i;
		while (big[k++] == little[j++])
		{
			if (little[j] == '\0')
				return ((char*)ptr);
		}
		i++;
	}
	return (0);
}
