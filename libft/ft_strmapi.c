/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elcarrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 08:03:19 by elcarrei          #+#    #+#             */
/*   Updated: 2016/11/27 21:46:54 by elcarrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *str, char (*f) (unsigned int, char))
{
	int		i;
	char	*dst;

	i = 0;
	if (!str || !f)
		return (NULL);
	if (!(dst = malloc(sizeof(char) * ft_strlen(str) + 1)))
		return (NULL);
	while (str[i])
	{
		dst[i] = f(i, str[i]);
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
