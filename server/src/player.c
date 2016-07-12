/*
** player.c for jetpack2Tek3 in /home/david/dev/syn_pool/jetpack2Tek3/server/src/
**
** Made by David Calo
** Login   <calo_d@epitech.eu>
**
** Started on  Mon Jul 11 16:57:06 2016 David Calo
** Last update Tue Jul 12 16:27:16 2016 David Calo
*/

#include "server.h"

#include <string.h>
#include <stdio.h>

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
