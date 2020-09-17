/*
** rotate.c for rotate in /home/bourhi_a/rendu/MUL_2013_fdf
** 
** Made by bourhime amine
** Login   <bourhi_a@epitech.net>
** 
** Started on  Sat Dec  7 15:46:31 2013 bourhime amine
** Last update Sat Dec  7 17:14:58 2013 bourhime amine
*/

#include <math.h>
#include "../include/geo_struct.h"

void		rot_x(t_point *coor, float v_cos, float v_sin)
{
  t_point	tmp;

  tmp.y = (v_cos * coor->y) - (v_sin * coor->z);
  tmp.z = (v_sin * coor->y) + (v_cos * coor->z);
  coor->y = tmp.y;
  coor->z = tmp.z;
}

void		rot_y(t_point *p, float v_cos, float v_sin)
{
  t_point	tmp;

  tmp.x = (v_cos * p->x) + (v_sin * p->z);
  tmp.z = (v_cos * p->z) - (v_sin * p->x);
  p->x = tmp.x;
  p->z = tmp.z;
}

void		rot_z(t_point *coor, float v_cos, float v_sin)
{
  t_point	tmp;

  tmp.x = (v_cos * coor->x) - (v_sin * coor->y);
  tmp.y = (v_sin * coor->x) + (v_cos * coor->y);
  coor->x = tmp.x;
  coor->y = tmp.y;
}

void		rotate(t_point *coor, float angle_x, float angle_y, float angle_z)
{
  if (angle_x != 0.0)
    rot_x(coor, cos(angle_x), sin(angle_x));
  if (angle_y != 0.0)
    rot_y(coor, cos(angle_y), sin(angle_y));
  if (angle_z != 0.0)
    rot_z(coor, cos(angle_z), sin(angle_z));
}
