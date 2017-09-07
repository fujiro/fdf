/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elcarrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:28:08 by elcarrei          #+#    #+#             */
/*   Updated: 2016/11/27 22:32:42 by elcarrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int			i;
	long int	nbr;

	nbr = n;
	i = 1;
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = nbr * -1;
	}
	while ((nbr / 10) > i)
		i = i * 10;
	while (i > 0)
	{
		ft_putchar_fd((nbr / i) % 10 + 48, fd);
		i = i / 10;
	}
}
