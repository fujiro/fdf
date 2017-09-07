/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elcarrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 07:00:38 by elcarrei          #+#    #+#             */
/*   Updated: 2016/11/26 07:13:17 by elcarrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strstr_addon(char *str, const char *to_find)
{
	int		i;
	int		j;
	int		pos;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (j == 0)
			pos = i;
		if (str[i] == to_find[j])
			j++;
		else
		{
			i = pos;
			j = 0;
		}
		i++;
		if (to_find[j] == '\0')
			return (&(str[i - j]));
	}
	return (NULL);
}

char		*ft_strstr(const char *str, const char *to_find)
{
	char	*tmp;

	if (!to_find[0])
		return (&(((char *)str)[0]));
	if (!str[0] && to_find[0])
		return (NULL);
	tmp = (char *)str;
	return (ft_strstr_addon(tmp, to_find));
}
