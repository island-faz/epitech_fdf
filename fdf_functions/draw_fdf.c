/*
** draw_fdf.c for fdf in /home/bourhi_a/rendu/MUL_2013_fdf
** 
** Made by bourhime amine
** Login   <bourhi_a@epitech.net>
** 
** Started on  Sun Dec  8 01:42:08 2013 bourhime amine
** Last update Sun Dec  8 15:48:37 2013 bourhime amine
*/

#include "../include/geo_struct.h"

void		mfdf(t_fdf *fdf, int *i, int *j, t_point border)
{
  t_point	p[2];

  p[0].y = *i * fdf->ops.zoom;
  p[0].x = *j * fdf->ops.zoom;
  p[0].z = fdf->map.array[*i][*j] * (-1);
  p[0].z += (p[0].z) ? fdf->ops.z : 0;
  rotate(&p[0], fdf->angle.x, fdf->angle.y, fdf->angle.z);
  if (*i + 1 < fdf->map.i)
    {
      p[1].y = (*i + 1) * fdf->ops.zoom;
      p[1].x = *j * fdf->ops.zoom;
      p[1].z = -fdf->map.array[*i + 1][*j];
      p[1].z += (p[1].z) ? fdf->ops.z : 0;
      rotate(&p[1], fdf->angle.x, fdf->angle.y, fdf->angle.z);
      project_and_draw(p[0], p[1], fdf, border);
    }
  if (*j + 1 < fdf->map.j)
    {
      p[1].y = *i * fdf->ops.zoom;
      p[1].x = (*j + 1) * fdf->ops.zoom;
      p[1].z = -fdf->map.array[*i][*j + 1];
      p[1].z += (p[1].z) ? fdf->ops.z : 0;
      rotate(&p[1], fdf->angle.x, fdf->angle.y, fdf->angle.z);
      project_and_draw(p[0], p[1], fdf, border);
    }
}

void		draw_fdf(t_fdf *fdf)
{
  int		i;
  int		j;
  t_point	border;

  i = 0;
  border = cal_border(&fdf->map, fdf->angle, fdf->ops);
  while (i < fdf->map.i && (j = -1))
    {
      j = 0;
      while (j < fdf->map.j)
	{
	  mfdf(fdf, &i, &j, border);
	  j++;
	}
      i++;
    }
}
