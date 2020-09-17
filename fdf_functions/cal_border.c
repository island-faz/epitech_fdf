/*
** cal_border.c for fdf in /home/bourhi_a/rendu/MUL_2013_fdf
** 
** Made by bourhime amine
** Login   <bourhi_a@epitech.net>
** 
** Started on  Sun Dec  8 01:21:46 2013 bourhime amine
** Last update Sun Dec  8 15:50:52 2013 bourhime amine
*/

#include "../include/geo_struct.h"

void	project_borders(t_point *b1, t_point *b2, t_point *b3, t_point *b4)
{
  calc_projection(b1, 0);
  calc_projection(b2, 0);
  calc_projection(b3, 0);
  calc_projection(b4, 0);
}

t_point		cal_border(t_array *arr, t_angle angle, t_ops ops)
{
  t_point	border_1;
  t_point	border_2;
  t_point	border_3;
  t_point	border_4;

  border_1.x = 0;
  border_1.y = (arr->i - 1) * (ops.zoom);
  border_1.z = arr->array[arr->i - 1][0];
  border_2.x = 0;
  border_2.y = 0;
  border_2.z = arr->array[0][0];
  border_3.x = (arr->j - 1) * (ops.zoom);
  border_3.y = 0;
  border_3.z = arr->array[0][arr->j - 1];
  border_4.x = (arr->j - 1) *  (ops.zoom);
  border_4.y = (arr->i - 1) * (ops.zoom);
  border_4.z = arr->array[arr->i - 1][arr->j - 1];
  rotate(&border_1, angle.x, angle.y, angle.z);
  rotate(&border_2, angle.x, angle.y, angle.z);
  rotate(&border_3, angle.x, angle.y, angle.z);
  rotate(&border_4, angle.x, angle.y, angle.z);
  project_borders(&border_1, &border_2, &border_3, &border_4);
  border_1.x = (WIDTH / 2) - (border_3.x - ((border_3.x - border_1.x) / 2));
  border_1.y = (HEIGHT / 2) - (border_4.y - ((border_4.y - border_2.y) / 2));
  return (border_1);
}
