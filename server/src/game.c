/*
** game.c for jetpack2Tek3 in /home/david/dev/syn_pool/jetpack2Tek3/server/src/
**
** Made by David Calo
** Login   <calo_d@epitech.eu>
**
** Started on  Fri Jul  8 09:28:59 2016 David Calo
** Last update Wed Jul 13 13:52:23 2016 David Calo
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
  g->start = 0;
  g->player = NULL;
  g->stime.tv_sec = 0;
  g->stime.tv_usec = 0;
  return (SUCCESS);
}

int		update_game(t_server *s)
{
  size_t	i;
  size_t	size;
  char		status;

  status = ST_ALL | ST_START;
  if ((size = list_size(s->client)) < MAX_CLIENT + 1)
    return (SUCCESS);
  for (i = 1; i < size; i++)
    status &= list_get(s->client, i)->status;
  // printf("update_game fire: %x\n", status);
  if (!IS_READY(status))
    return (player_clear(&s->game));
  else if (!HAS_START(status))
    {
      for (i = 1; i < size; i++)
	{
	  sprintf(list_get(s->client, i)->wbuf, "START");
	  SET_START(list_get(s->client, i)->status);
	}
      s->game.start = 1;
      printf("*** START ***\n");
      return (SUCCESS);
    }
  return (update_player(s));
}
