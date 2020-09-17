/*
** run_fdf.c for fdf in /home/bourhi_a/rendu/MUL_2013_fdf
** 
** Made by bourhime amine
** Login   <bourhi_a@epitech.net>
** 
** Started on  Sun Dec  8 16:09:41 2013 bourhime amine
** Last update Sun Dec  8 16:35:46 2013 bourhime amine
*/

#include "../include/geo_struct.h"

int	project_and_draw(t_point p1, t_point p2, t_fdf *fdf, t_point border)
{
  calc_projection(&p1, &p2);
  p1.x += border.x + fdf->ops.trans_x;
  p1.y += border.y + fdf->ops.trans_y;
  p2.x += border.x + fdf->ops.trans_x;
  p2.y += border.y + fdf->ops.trans_y;
  draw_line(p1, p2, fdf->img, GREEN_COLOR);
  return (1);
}

int	run_fdf(t_fdf *fdf, int fd)
{
  fdf->map = get_map(fd);
  fdf->angle.x = 0;
  fdf->angle.y = 0;
  fdf->angle.z = 0;
  if (fdf->map.i == 0 || fdf->map.j <= 0)
    {
      my_putstr(BAD_FILE_FORMAT);
      exit(1);
    }
  fdf->ops.zoom = HEIGHT / fdf->map.j;
  fdf->ops.trans_x = 0;
  fdf->ops.trans_y = 0;
  fdf->ops.z = 0;
  if (!(fdf->p->mlx_ptr = mlx_init()))
    exit(1);
  if (!(fdf->p->img_ptr = mlx_new_image(fdf->p->mlx_ptr, WIDTH, HEIGHT)))
    return (1);
  if (!(fdf->p->win_ptr = mlx_new_window(fdf->p->mlx_ptr, WIDTH, HEIGHT, "F")))
    return (1);
  fdf->img->data = (int *)mlx_get_data_addr(fdf->p->img_ptr, &fdf->img->bpp,
					    &fdf->img->sizeline,
					    &fdf->img->endian);
  fdf->img->end = (fdf->img->sizeline * HEIGHT / 4) - 1;
  draw_fdf(fdf);
  return (0);
}
