/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elcarrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 14:38:08 by elcarrei          #+#    #+#             */
/*   Updated: 2016/11/26 16:01:45 by elcarrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sort_params(int ac, char **av)
{
	int		i;

	i = 1;
	while (i + 1 < ac)
	{
		if (ft_strcmp(av[i], av[i + 1]) > 0)
		{
			av[0] = av[i];
			av[i] = av[i + 1];
			av[i + 1] = av[0];
			i = 1;
		}
		else
			i++;
	}
	i = 1;
	while (i < ac)
	{
		ft_putstr(av[i]);
		ft_putchar('\n');
		i++;
	}
}
