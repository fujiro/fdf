/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elcarrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 07:00:38 by elcarrei          #+#    #+#             */
/*   Updated: 2016/11/27 21:57:33 by elcarrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	pos;
	char	*tmp;

	i = 0;
	j = 0;
	tmp = (char *)str;
	while (tmp[i] && i <= size)
	{
		pos = i;
		while (tmp[i] == to_find[j] && tmp[i] != '\0' && i++ < size)
			j++;
		if (to_find[j] == '\0')
			return (&(tmp)[i - j]);
		else
		{
			i = pos;
			j = 0;
		}
		i++;
	}
	if (to_find[j] == tmp[i] && i < size)
		return (&(tmp[i - j]));
	return (NULL);
}
