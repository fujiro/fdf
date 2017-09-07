/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elcarrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 02:07:12 by elcarrei          #+#    #+#             */
/*   Updated: 2017/09/07 06:58:49 by elcarrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FDF_H
# define	FDF_H

# include "libft/libft.h"
# include <mlx.h>

typedef struct	s_fdf 
{
	void		*mlx;
	void		*wind;
	int			*coordx;
	int			*coordy;
}				t_fdf;

#endif
