/*
** my_putstr.c for my_putstr in /home/bourhi_a/rendu/Piscine-C-Jour_04
** 
** Made by bourhime amine
** Login   <bourhi_a@epitech.net>
** 
** Started on  Thu Oct  3 10:20:29 2013 bourhime amine
** Last update Sun Dec  8 17:29:52 2013 bourhime amine
*/

#include "../include/geo_struct.h"

int	my_putstr(char *str)
{
  int	i;

  if (!str)
    return (0);
  i = 0;
  while (str[i])
    {
      my_putchar(str[i]);
      i++;
    }
  return (i);
}
