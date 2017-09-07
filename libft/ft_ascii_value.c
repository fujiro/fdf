/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ascii_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elcarrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 19:03:24 by elcarrei          #+#    #+#             */
/*   Updated: 2016/11/19 19:26:50 by elcarrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_ascii_value(char *str)
{
	unsigned int		i;
	unsigned int		res;

	i = 0;
	res = 0;
	if (str[i])
	{
		while (str[i])
		{
			res = res + str[i];
			i++;
		}
	}
	return (res);
}
