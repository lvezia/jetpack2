/*
** select.c for jetpack2Tek3 in /home/david/dev/syn_pool/jetpack2Tek3/server/src/
**
** Made by David Calo
** Login   <calo_d@epitech.eu>
**
** Started on  Thu Jul  7 18:29:27 2016 David Calo
** Last update Sat Jul  9 21:20:22 2016 David Calo
*/

#include "server.h"

#include <sys/select.h>
#include <unistd.h>

static int	set_fds_tv(t_server *s, struct timeval *tv)
{
  t_fd		*tmp;

  tv->tv_sec = 0;
  tv->tv_usec = 100;
  FD_ZERO(&s->fds[0]);
  FD_ZERO(&s->fds[1]);
  for (tmp = s->client; tmp; tmp = tmp->next)
    {
      FD_SET(tmp->fd, &s->fds[0]);
      FD_SET(tmp->fd, &s->fds[1]);
    }
  return (SUCCESS);
}

int	server_select(t_server *s)
{
  struct timeval	tv;

  set_fds_tv(s, &tv);
  usleep(1);
  if (select(s->max_fd + 1, &s->fds[0], &s->fds[1], NULL, &tv) == -1)
    return (xperror("select"));
  return (SUCCESS);
}
