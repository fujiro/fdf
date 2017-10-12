#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <math.h>
# include "libft.h"

typedef struct s_fdf
{
  int fd;
  int **map;
  int lines;
  int first;
  int col;
  int z;
  int dx;
  int dy;
  int sx;
  int sy;
  void *mlx;
  void *win;
} t_fdf;

#endif
