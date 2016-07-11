/*
** client.c for jetpack2Tek3 in /home/david/dev/syn_pool/jetpack2Tek3/server/src/
**
** Made by David Calo
** Login   <calo_d@epitech.eu>
**
** Started on  Fri Jul  8 11:17:29 2016 David Calo
** Last update Mon Jul 11 10:20:54 2016 David Calo
*/

#include "server.h"

#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

int	client_read(t_server *s, size_t n)
{
  char		line[BUFFER_SIZE];
  t_fd		*cl;
  ssize_t	r;

  cl = list_get(s->client, n);
  memset(line, 0, BUFFER_SIZE);
  if ((r = read(cl->fd, line, BUFFER_SIZE)) < 1)
    {
      if (errno == EINVAL)
	perror("getline");
      return (FAIL);
    }
  line[r - 1] = 0;
  if (*cl->rbuf)
    memset(cl->rbuf, 0, strlen(cl->rbuf));
  if (!parser(line))
    {
      strcpy(cl->rbuf, line);
      strcpy(cl->wbuf, "Received");
      printf("[%d] \"%s\"\n", cl->fd, cl->rbuf);
    }
  return (SUCCESS);
}

int	client_write(t_server *s, size_t n)
{
  t_fd	*cl;

  cl = list_get(s->client, n);
  if (*cl->wbuf)
    {
      if (write(cl->fd, cl->wbuf, strlen(cl->wbuf)) < 1 ||
	  write(cl->fd, "\n", 1) < 1)
	return (errno != ECONNRESET ? xperror("write") : FAIL);
      memset(cl->wbuf, 0, strlen(cl->wbuf));
    }
  return (SUCCESS);
}

int	client_close(t_fd *cl, size_t n)
{
  int	fd;

  if ((fd = list_get(cl, n)->fd) <= 3)
    return (SUCCESS);
  printf("[%d] disconnected\n", fd);
  if (close(fd))
    return (xperror("close"));
  list_remove(cl, n);
  return (SUCCESS);
}

int	client_accept(int sfd)
{
  struct sockaddr	addr;
  socklen_t		size;
  int			fd;

  size = sizeof(struct sockaddr);
  if ((fd = accept(sfd, &addr, &size)) == -1)
    return (xperror("accept"));
  return (fd);
}
