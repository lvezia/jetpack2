/*
** list.c for jetpack2Tek3 in /home/david/dev/syn_pool/jetpack2Tek3/server/src/
**
** Made by David Calo
** Login   <calo_d@epitech.eu>
**
** Started on  Fri Jul  8 16:25:27 2016 David Calo
** Last update Wed Jul 13 19:31:15 2016 David Calo
*/

#include "server.h"

#include <stdlib.h>
#include <string.h>

t_fd	*list_new(int fd, t_rw_fn fn_read, t_rw_fn fn_write)
{
  t_fd	*new;

  new = malloc(sizeof(*new));
  new->fd = fd;
  new->status = 0x0;
  new->fn[0] = fn_read;
  new->fn[1] = fn_write;
  new->next = NULL;
  memset(new->rbuf, 0, BUFFER_SIZE);
  memset(new->wbuf, 0, BUFFER_SIZE);
  return (new);
}

int	list_add(t_fd *l, t_fd *n)
{
  t_fd	*t;

  if (!l || !n)
    return (FAIL);
  for (t = l; t->next;)
    t = t->next;
  t->next = n;
  return (SUCCESS);
}

int		list_remove(t_fd *l, size_t n)
{
  size_t	i;
  t_fd		*t;
  t_fd		*f;

  if (!(t = l))
    return (FAIL);
  for (i = 1; t->next && i < n; i++)
    t = t->next;
  f = t->next;
  if (t->next)
  t->next = t->next->next;
  free(f);
  return (SUCCESS);
}

size_t		list_size(t_fd *l)
{
  size_t	i;
  t_fd		*t;

  if (l == NULL)
    return (0);
  t = l;
  for (i = 1; t->next; i++)
    t = t->next;
  return (i);
}

t_fd	*list_get(t_fd *l, size_t n)
{
  size_t	i;
  t_fd		*t;

  if (!(t = l))
    return (NULL);
  for (i = 0; t->next && i < n; i++)
    t = t->next;
  if (i != n)
    return (NULL);
  return (t);
}
