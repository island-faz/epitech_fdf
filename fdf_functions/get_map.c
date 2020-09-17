/*
** get_map.c for fdf in /home/bourhi_a/rendu/MUL_2013_fdf
** 
** Made by bourhime amine
** Login   <bourhi_a@epitech.net>
** 
** Started on  Sun Dec  8 15:55:37 2013 bourhime amine
** Last update Sun Dec  8 17:41:16 2013 bourhime amine
*/

#include "../lib/get_next_line.h"
#include "../include/geo_struct.h"

t_array			get_map(int fd)
{
  int			i;
  int			j;
  t_array		map;
  char			*s;

  i = 0;
  map.j = -1;
  map.i = 0;
  while ((s = get_next_line(fd)))
    map = my_realloc(&map, s, i++);
  if (map.i == 0)
    {
      my_putstr(EMPTY_MAP);
      exit (1);
    }
  i = 0;
  while (i < map.i)
    {
      j = 0;
      while (j < map.j)
	j++;
      i++;
    }
  return (map);
}
