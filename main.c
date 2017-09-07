/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elcarrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 01:18:25 by elcarrei          #+#    #+#             */
/*   Updated: 2017/09/07 06:57:55 by elcarrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/** BRESENHAM OK **/

int		*ft_bresenham(int x0, int y0, t_fdf fdf)
{
	ft_putendl("bresenham in");
	int		dx;
	int		dy;
	int		p;
	int		x;
	int		y;

	dx = fdf.coordx[x0 + 1] - fdf.coordx[x0];
	dy = fdf.coordy[y0 + 1] - fdf.coordy[y0];
	x = fdf.coordx[x0];
	y = fdf.coordy[y0];
	p = 2 * dy - dx;
	while (x < fdf.coordx[x0 + 1])
	{
		if (p >= 0)
		{
			mlx_pixel_put(fdf.mlx, fdf.wind, y, x, 0x00FFFFFF);
			y = y + 1;
			p = p + 2 * dy -2 * dx;
		}
		else
		{
			mlx_pixel_put(fdf.mlx, fdf.wind, y, x, 0x00FFFFFF);
			p = p + 2 * dy;
		}
		x = x + 1;
	}
	ft_putendl("bresenham out");
	return (0);
}

/** FDF FALSE **/

int		*ft_fdf(t_fdf fdf)
{
	ft_putendl("fdf in");
	int		x;
	int		y;

	x = 0;
	y = 0;
	ft_putendl("fdf while");
	while (fdf.coordx[x])
	{
		ft_putendl("if bresenham");
		if (fdf.coordx[x + 1] && fdf.coordy[y + 1])
			ft_bresenham(x, y, fdf);
		ft_putendl("if passe");
		x++;
		y++;
	}
	ft_putendl("fdf out");
	return (0);
}

/** TABLEN OK  **/

int		ft_tablen(int **coord)
{
	ft_putendl("tablen in");
	int		i;
	int		j;
	int		x;

	i = 0;
	j = 0;
	x = 0;
	while (coord[j][i])
	{
		x++;
		i++;
		if (!coord[j][i])
		{
			i = 0;
			j++;
		}
	}
	ft_putendl("tablen out");
	return (x);
}

/** GET_COORD  FALSE **/

void	ft_get_coord(int **coord, t_fdf fdf)
{
	ft_putendl("get coord in");
	int		i;
	int		j;
	int		x;

	i = 0;
	j = 0;
	x = 0;
	fdf.coordx = (int *)malloc(sizeof(int) * ft_tablen(coord) + 1);
	fdf.coordy = (int *)malloc(sizeof(int) * ft_tablen(coord) + 1);
	while (coord[j][i])
	{
		fdf.coordx[x] = i * 10;
		fdf.coordy[x] = j * 10 + coord[j][i];
		i++;
		if (!coord[j][i])
		{
			i = 0;
			j++;
		}
	}
	fdf.coordx[x] = '\0';
	fdf.coordy[x] = '\0';
	x = 0;
	while (fdf.coordx[x])
	{
		ft_putnbr(fdf.coordx[x]);
		ft_putchar('\n');
		ft_putnbr(fdf.coordy[x]);
		ft_putchar('\n');
		x++;
	}
	ft_putendl("get coord out");
}

/** GET_TAB OK **/

int		**ft_get_tab(int **coord, char *next_coord, int y)
{
	ft_putendl("get tab in");
	char	**tab;
	int		i;
	int		x;

	i = 0;
	x = 0;
	coord[y] = (int *)malloc(sizeof(int) * ft_strlen(next_coord) + 1);
	tab = ft_strsplit(next_coord, ' ');
	while (tab[i])
	{
		coord[y][x] = ft_atoi(tab[i]);
		x++;
		i++;
	}
	coord[y][x] = '\0';
	ft_putendl("get tab out");
	return (coord);
}

/** MAIN OK **/

int		main(int ac, char **av)
{
	ft_putendl("main in");
	char	*line;
	int		**coord;
	int		fd;
	int		y;
	t_fdf	fdf;

	if (ac != 2)
		return (0);
	fdf.mlx = mlx_init();
	fdf.wind = mlx_new_window(fdf.mlx, 400, 400, "window");
	fd = open(av[1], O_RDONLY);
	y = 0;
	coord = (int **)malloc(sizeof(int *) * 1);
	while (get_next_line(fd, &line))
	{
		coord = ft_get_tab(coord, line, y);
		y++;
	}
	ft_get_coord(coord, fdf);
	ft_fdf(fdf);
	mlx_loop(fdf.mlx);
	ft_putendl("main out");
	return (0);
}
