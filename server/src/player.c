/*
** player.c for jetpack2Tek3 in /home/david/dev/syn_pool/jetpack2Tek3/server/src/
**
** Made by David Calo
** Login   <calo_d@epitech.eu>
**
** Started on  Mon Jul 11 16:57:06 2016 David Calo
** Last update Tue Jul 12 18:00:51 2016 David Calo
*/

#include "server.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int	player_info(t_server const *s, int n, int *status)
{
  t_fd	*cl;

  if ((cl = list_get(s->client, n + 1)) == NULL ||
      !(*cl->rbuf))
    return (FAIL);
  printf("player_info: %d\n", *status);
  memset(cl->rbuf, 0, strlen(cl->rbuf));
  return (SUCCESS);
}

// player_struct.c
int		player_init(t_game *g, t_fd *cl)
{
  size_t	i;
  size_t	nb;

  printf("player_init\n");
  nb = list_size(cl);
  printf(" `- nb: %lu\n", nb);
  if ((g->player = malloc(sizeof(*g->player) * nb)) == NULL)
    return (FAIL);
  memset(g->player, 0, sizeof(*g->player) * nb);
  for (i = 0; i < nb; i++)
    g->player[i].y = (double)g->my / 2;
  printf(" `- [0]: %lf, %lf\n", g->player[0].x, g->player[0].y);
  printf(" `- [1]: %lf, %lf\n", g->player[1].x, g->player[1].y);
  return (SUCCESS);
}

int	update_player(t_server *s)
{
  if (s->game.start && !s->game.player)
    player_init(&s->game, s->client->next);

  return (SUCCESS);
}
