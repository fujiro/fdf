/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elcarrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:21:52 by elcarrei          #+#    #+#             */
/*   Updated: 2016/11/20 17:12:19 by elcarrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char		*d;
	const char	*s;

	d = (char *)dst;
	s = (const char *)src;
	while (n--)
	{
		if (*s == c)
		{
			*d = *s;
			return (d + 1);
		}
		*d++ = *s++;
	}
	return (NULL);
}
