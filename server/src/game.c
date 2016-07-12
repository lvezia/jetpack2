/*
** game.c for jetpack2Tek3 in /home/david/dev/syn_pool/jetpack2Tek3/server/src/
**
** Made by David Calo
** Login   <calo_d@epitech.eu>
**
** Started on  Fri Jul  8 09:28:59 2016 David Calo
** Last update Tue Jul 12 11:23:07 2016 David Calo
*/

#include "server.h"

#include <stdio.h>
#include <string.h>

int	process_game(t_game *g)
{
  if ((g->mx = xstrlenchr(g->map, '\n')) == 0)
    return (FAIL);
  g->my = count_lines(g->map);
  epur_str(g->map, '\n');
  printf("x: %d, y: %d\n", g->mx, g->my);
  return (SUCCESS);
}

int		update_game(t_server *s)
{
  // size_t	i;

  (void)s;
  // for (i = 1; i < MAX_CLIENT + 1; i++)
  //   if (player_info(s, i, &s->game.status[i]))
  //     return (FAIL);
  return (SUCCESS);
}
