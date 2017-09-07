/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elcarrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:18:24 by elcarrei          #+#    #+#             */
/*   Updated: 2016/11/22 08:06:44 by elcarrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((((unsigned char *)s1)[i] == ((unsigned char *)s2)[i]) && i < n - 1)
		i++;
	if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
		return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
	return (0);
}
