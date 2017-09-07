/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elcarrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 15:16:59 by elcarrei          #+#    #+#             */
/*   Updated: 2016/11/22 07:36:11 by elcarrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nb)
{
	int			i;
	long int	nbr;

	nbr = nb;
	i = 1;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = nbr * -1;
	}
	while ((nbr / 10) > i)
		i = i * 10;
	while (i > 0)
	{
		ft_putchar((nbr / i) % 10 + 48);
		i = i / 10;
	}
}
