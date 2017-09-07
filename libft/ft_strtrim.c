/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elcarrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 08:44:02 by elcarrei          #+#    #+#             */
/*   Updated: 2016/11/27 21:53:35 by elcarrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *str)
{
	char	*dst;
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	if (!(dst = ft_strdup((char *)str)) || !(str))
		return (NULL);
	while (dst[i] == ' ' || dst[i] == ',' || dst[i] == '\n' || dst[i] == '\t')
		dst++;
	i = ft_strlen(dst) - 1;
	while (dst[i] == ' ' || dst[i] == ',' || dst[i] == '\n' || dst[i] == '\t')
		i--;
	dst[++i] = '\0';
	return (ft_strdup(dst));
}
