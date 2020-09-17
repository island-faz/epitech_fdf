/*
** my_putchar.c for FDF in /home/bourhi_a/rendu/MUL_2013_fdf/lib
** 
** Made by bourhime amine
** Login   <bourhi_a@epitech.net>
** 
** Started on  Fri Dec  6 00:24:27 2013 bourhime amine
** Last update Sun Dec  8 17:41:47 2013 bourhime amine
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}
