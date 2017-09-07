/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elcarrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 10:40:50 by elcarrei          #+#    #+#             */
/*   Updated: 2016/11/27 22:28:39 by elcarrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_getsize(int n)
{
	int		i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

static char		*ft_maxint(int n)
{
	char	*str;

	str = malloc(sizeof(char) * 11);
	str = ft_itoa(-(n - 1));
	str[10]++;
	return (str);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		i;

	i = ft_getsize(n) + (n < 0) - 1;
	if (!(str = malloc(ft_getsize(n) + (n < 0) + 1)))
		return (NULL);
	str[ft_getsize(n) + (n < 0) + 1] = '\0';
	if (n == -2147483648)
		return (ft_maxint(n));
	if (!n)
		str[0] = '0';
	if (n < 0)
	{
		n = n * -1;
		str[0] = '-';
	}
	str[i + 1] = '\0';
	while (n)
	{
		str[i--] = n % 10 + 48;
		n = n / 10;
	}
	return (str);
}
