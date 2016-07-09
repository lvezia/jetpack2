/*
** list.c for jetpack2Tek3 in /home/david/dev/syn_pool/jetpack2Tek3/server/src/
**
** Made by David Calo
** Login   <calo_d@epitech.eu>
**
** Started on  Fri Jul  8 16:25:27 2016 David Calo
** Last update Sat Jul  9 20:47:31 2016 David Calo
*/

#include "server.h"

#include <stdlib.h>

t_fd		*list_new(int fd, t_fd_fn fn_read, t_fd_fn fn_write)
{
  t_fd	*new;

  new = malloc(sizeof(*new));
  new->fd = fd;
  new->fn[0] = fn_read;
  new->fn[1] = fn_write;
  new->next = NULL;
  new->rbuf = NULL;
  new->wbuf = NULL;
  return (new);
}

int	list_add(t_fd *l, t_fd *n)
{
  t_fd	*t;

  if (!l || !n)
    return (FAIL);
  for (t = l; t->next; t = t->next)
    ;
  t->next = n;
  return (SUCCESS);
}

int	list_remove(t_fd *l, size_t n)
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
  if (f->rbuf)
    free(f->rbuf);
  if (f->wbuf)
    free(f->wbuf);
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
  return (t);
}
