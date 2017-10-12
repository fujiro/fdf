void ft_bresenham(t_fdf *fdf, int *tab, int x, int y)
{
  int tabx[2];
  int taby[2];
  int e[2];
  int x0;
  int y0;

  x0 = tabx[0];
  y0 = taby[0];
  tabx[0] = abs(x - x0);
  tabx[1] = x0 < x ? 1 : -1;
  taby[0] = abs(y - y0);
  taby[1] = y0 < y ? 1 : -1;
  e[0] = (tabx[0] > taby[0] ? tabx[0] : -tabx[0]) / 2;
  while (x0 != x || y0 != y)
    {
      mlx_pixel_put(fdf->mlx, fdf->win, x0, y0, /*couleur*/);
      e[1] = e[0];
      e[1] > -tabx[0] ? e[0] = e[0] - taby[0] : 1 == 1;
      e[1] > -tabx[0] ? x0 = x0 + tabx[1] : 1 == 1;
      e[1] < taby[0] ? e[0] = e[0] + tabx[0] : 1 == 1;
      e[1] < taby[0] ? y0 = y0 + taby[1] : 1 == 1;
    }
}

void ft_lines(t_fdf *fdf, int x, int y)
{
  int tab[2];

  tab[0] = fdf->dx + (x - y);
  tab[1] = fdf->dy + fdf->map[y/fdf->sy][x/fdf->sx] * fdf->z + x + y;
  if (x/fdf->sx < fdf->col - 1 && y/fdf->sy < fdf->col)
    ft_bresenham(fdf, tab, fdf->dx + ((x + fdf->sx) - y), fdf->dy + fdf->map[y/fdf->sy][x/fdf->sx + 1] * fdf->z + (x + fdf->sx) + y);
  if (y/fdf->sy < fdf->col - 1 && x/fdf->sx < fdf->col)
    ft_bresenham(fdf, tab, fdf->dx + (x - (y + fdf->sy)), fdf->dy + fdf->map[y/fdf->sy + 1][x/fdf->sx] * fdf->z + x + (y + fdf->sy));
}

void ft_first_dot(t_fdf *fdf)
{
  if (fdf->first == 0)
    {
      fdf->z = -5;
      fdf->dx = /*largeur*/ * 0,4;
      fdf->dy = 20;
      fdf->sx = (/*largeur*/ * 0,7) / (fdf->col - 1);
      fdf->sy = (/*hauteur*/ * 0,5) / (fdf->lines - 1);
    }
}

void ft_draw(t_fdf *fdf)
{
  int x;
  int y;

  x = 0;
  y = 0;
  ft_first_dot(fdf);
  while (x/fdf->sx < fdf->col || y/fdf->sy < fdf->lines - 1)
    {
      if (x/fdf->sx == fdf->col)
	{
	  x = 0;
	  y = y + fdf->sy;
	}
      ft_lines(fdf, x, y);
      x = x + fdf->syx
    }
}

int ft_tab_alloc_2(t_fdf *fdf, char *line)
{
  int x;
  char **tab;

  x = 0;
  tab = ft_strsplit(line, ' ');
  while (tab[x])
    {
      free(tab[x]);
      x++;
    }
  if (fdf->lines == 0)
    fdf->col = x;
  else
    {
      if (x != parse->col)
	return (-1);
    }
  free(line);
  free(tab);
  fdf->lines++;
  return (0);
}

int ft_tab_alloc(t_fdf *fdf)
{
  char *line;
  int ret;

  line = NULL;
  fdf->lines = 0;
  fdf->col = 0;
  while ((ret = get_next_line(fdf->fd, &line)) > 0)
    {
      if (ft_tab_alloc_2(fdf, line) == -1)
	return (-1);
    }
  fdf->map = ft_memalloc(sizeof(int *) * fdf->lines);
  close(fdf->fd);
  fdf->fd = open(fdf->file, O_RDONLY);
  return (0);
}

int ft_getcoord(t_fdf *fdf)
{
  char **line;
  char **tab;
  int tabxy[3];

  tabxy[1] = 0;
  if (ft_tab_alloc(fdf) == -1)
    return (-1);
  while ((tabxy[2] = get_next_line(fdf->fd, &line)) > 0)
    {
      tabxy[0] = 0;
      tab = ft_strsplit(line, ' ');
      fdf->map[tabxy[1]] = ft_memalloc(sizeof(int) * fdf->col);
      while (tab[tabxy[0]] != NULL)
	{
	  fdf->map[tabxy[1]][tabxy[0]] = ft_atoi(tab[tabxy[0]]);
	  free(tab[tabxy[0]]);
	  tabxy[0]++,
	}
      free(tab);
      tabxy[1]++;
    }
  return ((tabxy[2] == -1) ? -1 : 1);
}

void ft_fdf_init(t_fdf *fdf)
{
  if (ft_getcoord(fdf) == -1)
    {
      ft_error(1);
      return ;
    }
  fdf->first = 0;
  fdf->mlx = mlx_init();
  fdf->win = mlx_new_window(fdf->mlx, /*largeur*/, /*hauteur*/, "fdf");
  ft_draw(fdf);
  mlx_loop(fdf->mlx);
  ft_fdf(fdf);
}

int main(int ac, char **av)
{
  t_fdf fdf;

  if (ac == 2)
    {
      fdf.file = av[1];
      fdf.fd = open(fdf.file, O_RDONLY);
      ft_fdf_init(&fdf);
    }
  else
    ft_error(0);
  return (0);
}
