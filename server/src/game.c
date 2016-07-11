/*
** game.c for jetpack2Tek3 in /home/david/dev/syn_pool/jetpack2Tek3/server/src/
**
** Made by David Calo
** Login   <calo_d@epitech.eu>
**
** Started on  Fri Jul  8 09:28:59 2016 David Calo
** Last update Mon Jul 11 14:22:13 2016 David Calo
*/

#include "server.h"

#include <stdio.h>

int	count_lines(char const *s)
{
  return (*s ? count_lines(s + 1) + (*s == '\n') : 0);
}

int	process_game(t_game *g)
{
  if ((g->mx = xstrlenchr(g->map, '\n')) == 0)
    return (FAIL);
  g->my = count_lines(g->map);
  epur_str(g->map, '\n');
  printf("x: %d, y: %d\n", g->mx, g->my);
  return (SUCCESS);
}

int	update_game(t_server const *s)
{
  (void)s;
  return (SUCCESS);
}
