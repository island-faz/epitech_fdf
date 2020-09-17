/*
** calc_projection.c for fdf in /home/bourhi_a/rendu/MUL_2013_fdf
** 
** Made by bourhime amine
** Login   <bourhi_a@epitech.net>
** 
** Started on  Sun Dec  8 16:00:07 2013 bourhime amine
** Last update Sun Dec  8 16:02:15 2013 bourhime amine
*/

#include "../include/geo_struct.h"

void		calc_projection(t_point *p1, t_point *p2)
{
  int		x;

  x = p1->x;
  p1->x = (CT1 * x - CT2 * p1->y);
  p1->y = (p1->z + (CT1 / 2) * x + (CT2 / 2) * p1->y);
  if (p2)
    {
      x = p2->x;
      p2->x = (CT1 * x - CT2 * p2->y);
      p2->y = (p2->z + (CT1 / 2) * x + (CT2 / 2) * p2->y);
    }
}
