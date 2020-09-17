/*
** manage_key.c for fdf in /home/bourhi_a/rendu/MUL_2013_fdf
** 
** Made by bourhime amine
** Login   <bourhi_a@epitech.net>
** 
** Started on  Sun Dec  8 01:45:10 2013 bourhime amine
** Last update Fri Jan 10 17:48:37 2014 
*/

#include "../include/geo_struct.h"

void	check_for_exit(int key, t_fdf *fdf)
{
  if (key == EXIT_KEY)
    exit(0);
}

void	reset_fdf(t_fdf *fdf)
{
  fdf->angle.x = 0;
  fdf->angle.y = 0;
  fdf->angle.z = 0;
  fdf->ops.zoom = HEIGHT / fdf->map.j;
  fdf->ops.trans_x = 0;
  fdf->ops.trans_y = 0;
  fdf->ops.z = 0;
}

void		key_apply(int key, void *p)
{
  t_fdf		*fdf;

  fdf = (t_fdf*)p;
  check_for_exit(key, fdf);
  animate(key, fdf);
  fdf->angle.z += (key == ROTATE_Z_LEFT_KEY) ? 0.05 : 0;
  fdf->angle.z -= (key == ROTATE_Z_RIGHT_KEY) ? 0.05 : 0;
  fdf->angle.y += (key == ROTATE_Y_LEFT_KEY) ? 0.05 : 0;
  fdf->angle.y -= (key == ROTATE_Y_RIGHT_KEY) ? 0.05 : 0;
  fdf->angle.x += (key == ROTATE_X_LEFT_KEY) ? 0.05 : 0;
  fdf->angle.x -= (key == ROTATE_X_RIGHT_KEY) ? 0.05 : 0;
  if (key == RESET_KEY)
    reset_fdf(fdf);
  fdf->ops.zoom += (key == ZOOM_IN_KEY) ? 1 : 0;
  fdf->ops.zoom -= (key == ZOOM_OUT_KEY) ? 1 : 0;
  fdf->ops.trans_x += (key == MOVE_RIGHT_KEY) ? TRANS_SPEED : 0;
  fdf->ops.trans_x -= (key == MOVE_LEFT_KEY) ? TRANS_SPEED : 0;
  fdf->ops.trans_y -= (key == MOVE_UP_KEY) ? TRANS_SPEED : 0;
  fdf->ops.trans_y += (key == MOVE_DOWN_KEY) ? TRANS_SPEED : 0;
  fdf->ops.z += (key == EXTEND_Z_KEY) ? 10 : 0;
  fdf->ops.z -= (key == REDUCE_Z_KEY) ? 10 : 0;
  clear_image(fdf->img->data, fdf->img->end);
  draw_fdf(fdf);
  mlx_put_image_to_window(fdf->p->mlx_ptr, fdf->p->win_ptr, fdf->p->img_ptr,
			  0, 0);
}

int		manage_key(int key, void *p)
{
  if ((ROTATE_X_LEFT_KEY == key) || (ROTATE_X_RIGHT_KEY == key) ||
      (ROTATE_Y_LEFT_KEY == key) || (key == ROTATE_Y_RIGHT_KEY) ||
      (ROTATE_Z_LEFT_KEY == key) || (key == ROTATE_Z_RIGHT_KEY) ||
      (ZOOM_OUT_KEY == key) || (ZOOM_IN_KEY == key) ||
      (MOVE_LEFT_KEY == key) || (MOVE_RIGHT_KEY == key) ||
      (MOVE_UP_KEY == key) || (MOVE_DOWN_KEY == key) ||
      (EXTEND_Z_KEY == key) || (REDUCE_Z_KEY == key) ||
      (EXIT_KEY == key || RESET_KEY == key) ||
      (ANIMATE_KEY_X == key) || (ANIMATE_KEY_Y == key) ||
      (ANIMATE_KEY_Z == key))
    key_apply(key, p);
  return (0);
}
