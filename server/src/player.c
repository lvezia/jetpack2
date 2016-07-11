/*
** player.c for jetpack2Tek3 in /home/david/dev/syn_pool/jetpack2Tek3/server/src/
**
** Made by David Calo
** Login   <calo_d@epitech.eu>
**
** Started on  Mon Jul 11 16:57:06 2016 David Calo
** Last update Mon Jul 11 18:02:50 2016 David Calo
*/

#include "server.h"

int	player_id(t_fd *cl, int id)
{
  if (*cl->rbuf ||
      strcmp(cl->rbuf, "ID"))
    return (FAIL);
  if (sprintf(cl->wbuf, "ID %d", id))
    return (FAIL);
  return (SUCCESS);
}

int	player_map(t_fd *cl, t_game const *g)
{
  if (*cl->rbuf ||
      strcmp(cl->rbuf, "MAP"))
    return (FAIL);
  if (sprintf(cl->wbuf, "MAP %d %d %s", g->mx, g->my, g->map))
    return (FAIL);
  return (SUCCESS);
}


int	player_info(t_server const *s, int n)
{
  t_fd	*cl;

  if ((cl = list_get(s->client, n)) == NULL)
    return (FAIL);
  if (player_id(cl, n))
}
