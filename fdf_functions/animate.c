/*
** animate.c for fdf in /home/bourhi_a/rendu/MUL_2013_fdf
** 
** Made by bourhime amine
** Login   <bourhi_a@epitech.net>
** 
** Started on  Sun Dec  8 05:36:25 2013
** Last update Thu Dec 12 13:24:10 2013 
*/

#include "../include/geo_struct.h"

void		animate_y(t_fdf *fdf)
{
  float		tmp;

  tmp = fdf->angle.y + 3.14 / 2;
  while (fdf->angle.y < tmp)
    {
      clear_image(fdf->img->data, fdf->img->end);
      draw_fdf(fdf);
      mlx_put_image_to_window(fdf->p->mlx_ptr, fdf->p->win_ptr,
			      fdf->p->img_ptr, 0, 0);
      fdf->angle.y += 0.1;
      mlx_do_sync(fdf->p->mlx_ptr);
    }
}

void		animate_x(t_fdf *fdf)
{
  float		tmp;

  tmp = fdf->angle.x + 3.14 / 2;
  while (fdf->angle.x < tmp)
    {
      clear_image(fdf->img->data, fdf->img->end);
      draw_fdf(fdf);
      mlx_put_image_to_window(fdf->p->mlx_ptr, fdf->p->win_ptr,
			      fdf->p->img_ptr, 0, 0);
      mlx_do_sync(fdf->p->mlx_ptr);
      fdf->angle.x += 0.1;
    }
}

void		animate_z(t_fdf *fdf)
{
  float		tmp;

  tmp = fdf->angle.z + 3.14 / 2;
  while (fdf->angle.z <= tmp)
    {
      clear_image(fdf->img->data, fdf->img->end);
      draw_fdf(fdf);
      mlx_put_image_to_window(fdf->p->mlx_ptr, fdf->p->win_ptr,
			      fdf->p->img_ptr, 0, 0);
      mlx_do_sync(fdf->p->mlx_ptr);
      fdf->angle.z += 0.1;
    }
}

void		animate(int key, t_fdf *fdf)
{
  if (key == ANIMATE_KEY_X)
    animate_x(fdf);
  else if (key == ANIMATE_KEY_Y)
    animate_y(fdf);
  else if (key == ANIMATE_KEY_Z)
    animate_z(fdf);
}
