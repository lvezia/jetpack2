/*
** parse.c for jetpack2Tek3 in /home/david/dev/syn_pool/jetpack2Tek3/server/src/
**
** Made by David Calo
** Login   <calo_d@epitech.eu>
**
** Started on  Sun Jul 10 12:37:10 2016 David Calo
** Last update Sun Jul 10 18:55:51 2016 David Calo
*/

#include "server.h"

#include <stdio.h>
#include <string.h>

int		parser(char const *s)
{
  size_t	i;
  static char	*tab[] = {"ID", "MAP", "READY", "FIRE "};

  for (i = 0; i < 4; i++)
    if (!strncasecmp(tab[i], s, 5))
      return (SUCCESS);
  return (FAIL);
}
