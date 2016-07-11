/*
** player.c for jetpack2Tek3 in /home/david/dev/syn_pool/jetpack2Tek3/server/src/
**
** Made by David Calo
** Login   <calo_d@epitech.eu>
**
** Started on  Mon Jul 11 16:57:06 2016 David Calo
** Last update Mon Jul 11 21:40:14 2016 David Calo
*/

#include "server.h"

#include <string.h>
#include <stdio.h>

int	player_id(t_fd *cl, int id)
{
  if (strcasecmp(cl->rbuf, "ID"))
    return (FAIL);
  printf("ID %d\n", id);
  if (sprintf(cl->wbuf, "ID %d", id))
    return (FAIL);
  return (SUCCESS);
}

int	player_map(t_fd *cl, t_game const *g)
{
  if (strcasecmp(cl->rbuf, "MAP"))
    return (FAIL);
  printf("MAP %d %d\n", g->mx, g->my);
  if (sprintf(cl->wbuf, "MAP %d %d %s", g->mx, g->my, g->map))
    return (FAIL);
  return (SUCCESS);
}

int	player_ready(t_fd *cl)
{
  if (strcasecmp(cl->rbuf, "READY"))
    return (FAIL);
  printf("READY\n");
  return (SUCCESS);
}

int	player_info(t_server const *s, int n, int *status)
{
  t_fd	*cl;

  if ((cl = list_get(s->client, n + 1)) == NULL ||
      !(*cl->rbuf))
    return (FAIL);
  else if ((!player_id(cl, n) && SET_ID(*status)) ||
	   (!player_map(cl, &s->game) && SET_MAP(*status)) ||
	   (!player_ready(cl) && SET_READY(*status)))
    {
      printf("*status: %d\n", *status);
      return (SUCCESS);
    }
  printf("player_info: %d\n", *status);
  memset(cl->rbuf, 0, strlen(cl->rbuf));
  return (SUCCESS);
}
