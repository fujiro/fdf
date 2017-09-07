/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elcarrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 19:55:49 by elcarrei          #+#    #+#             */
/*   Updated: 2016/11/20 21:50:26 by elcarrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	char	*dst;

	i = 0;
	if (!(dst = malloc(sizeof(char) * ft_strlen(str) + 1)))
		return (NULL);
	dst[ft_strlen(str) + 1] = '\0';
	while (str[i])
	{
		dst[ft_strlen(str) - i] = str[i];
		i++;
	}
	return (dst);
}
