/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elcarrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 17:15:17 by elcarrei          #+#    #+#             */
/*   Updated: 2016/11/18 18:04:18 by elcarrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*tmp;
	char	*reader;
	size_t	len;

	tmp = (char *)ft_memchr(dst, '\0', size);
	if (tmp == NULL)
		return (ft_strlen(src) + size);
	reader = (char *)src;
	len = (size_t)(tmp - dst) + ft_strlen(reader);
	while ((size_t)(tmp - dst) < size - 1 && *reader != '\0')
		*tmp++ = *reader++;
	*tmp = '\0';
	return (len);
}
