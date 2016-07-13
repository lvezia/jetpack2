/*
** player_struct.c for jetpack2Tek3 in /home/david/dev/syn_pool/jetpack2Tek3/server/src/
**
** Made by David Calo
** Login   <calo_d@epitech.eu>
**
** Started on  Wed Jul 13 09:32:37 2016 David Calo
** Last update Wed Jul 13 09:44:14 2016 David Calo
*/

#include "server.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int		player_init(t_game *g, t_fd *cl)
{
  size_t	i;

  printf("player_init\n");
  g->nplayer = list_size(cl);
  printf(" `- nb: %lu\n", g->nplayer);
  if ((g->player = malloc(sizeof(*g->player) * g->nplayer)) == NULL)
    return (FAIL);
  memset(g->player, 0, sizeof(*g->player) * g->nplayer);
  for (i = 0; i < g->nplayer; i++)
    {
      g->player[i].y = (double)g->my / 2;
      g->player[i].vel = 0.0f;
    }
  printf(" `- [0]: %lf, %lf\n", g->player[0].x, g->player[0].y);
  printf(" `- [1]: %lf, %lf\n", g->player[1].x, g->player[1].y);
  g->stime.tv_sec = 0;
  g->stime.tv_usec = 0;
  return (SUCCESS);
}

int	player_clear(t_game *g)
{
  memset(g->player, 0, sizeof(*g->player) * g->nplayer);
  free(g->player);
  g->player = NULL;
  g->nplayer = 0;
  return (SUCCESS);
}
