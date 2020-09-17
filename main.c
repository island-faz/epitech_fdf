/*
** main.c for FDF in /home/bourhi_a/rendu/MUL_2013_fdf
** 
** Made by bourhime amine
** Login   <bourhi_a@epitech.net>
** 
** Started on  Tue Dec  3 01:01:47 2013 bourhime amine
** Last update Wed Dec 18 04:30:07 2013 
*/

#include "include/geo_struct.h"

int			main(int ac, char **av)
{
  int			fd;
  t_fdf			fdf;

  if (ac < 2)
    {
      my_putstr(MISSING_MAP);
      exit(1);
    }
  if (ac < 2 || (fd = open(av[1], O_RDONLY)) == -1)
    {
      perror("fdf");
      exit(1);
    }
  if (!(fdf.img = malloc(sizeof(t_image))))
    return (1);
  if (!(fdf.p = malloc(sizeof(t_graphics))))
    return (1);
  run_fdf(&fdf, fd);
  mlx_expose_hook(fdf.p->win_ptr, gere_expose, fdf.p);
  mlx_hook(fdf.p->win_ptr, KeyPress, KeyPressMask, &manage_key, &fdf);
  mlx_do_key_autorepeaton(fdf.p->mlx_ptr);
  mlx_loop(fdf.p->mlx_ptr);
}
