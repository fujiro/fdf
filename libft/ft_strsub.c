/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elcarrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 08:14:53 by elcarrei          #+#    #+#             */
/*   Updated: 2016/11/27 22:03:50 by elcarrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *str, unsigned int start, size_t len)
{
	int		i;
	char	*dst;

	i = 0;
	if (!str)
		return (NULL);
	if (!(dst = malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (len-- && str[start] != '\0')
	{
		dst[i] = str[start + i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
