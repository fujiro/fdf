/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elcarrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 15:46:40 by elcarrei          #+#    #+#             */
/*   Updated: 2016/11/26 15:55:57 by elcarrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_range(int min, int max)
{
	int		i;
	int		*tab;

	i = 0;
	if (min >= max)
		return (0);
	while (min + i < max)
		i++;
	if (!(tab = malloc(sizeof(int) * i)) || min >= max)
		return (0);
	i = 0;
	while (min + i < max)
	{
		tab[i] = min + i;
		i++;
	}
	return (tab);
}
