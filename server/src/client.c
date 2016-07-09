/*
** client.c for jetpack2Tek3 in /home/david/dev/syn_pool/jetpack2Tek3/server/src/
**
** Made by David Calo
** Login   <calo_d@epitech.eu>
**
** Started on  Fri Jul  8 11:17:29 2016 David Calo
** Last update Sat Jul  9 21:00:37 2016 David Calo
*/

#include "server.h"

#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

int	client_read(t_server *s, size_t n)
{
  char		line[BUFFER_SIZE];
  t_fd		*cl;
  ssize_t	r;

  cl = list_get(s->client, n);
  memset(line, 0, BUFF_SIZE);
  if ((r = read(cl->fd, line, BUFFER_SIZE)) < 1)
    {
      if (errno == EINVAL)
	perror("getline");
      return (FAIL);
    }
  line[r - 1] = 0;
  if (cl->rbuf)
    free(cl->rbuf);
  cl->rbuf = strdup(line);
  cl->wbuf = strdup("Received\n");
  printf("[%d] \"%s\"\n", cl->fd, cl->rbuf);
  return (SUCCESS);
}
int	client_write(t_server *s, size_t n)
{
  t_fd	*cl;

  cl = list_get(s->client, n);
  if (cl->wbuf)
    {
      if (write(cl->fd, cl->wbuf, strlen(cl->wbuf)) < 1)
	return (errno != ECONNRESET ? xperror("write") : FAIL);
      free(cl->wbuf);
      cl->wbuf = NULL;
    }
  return (SUCCESS);
}
int	client_close(t_fd *cl, size_t n)
{
  int	fd;

  fd = list_get(cl, n)->fd;
  printf("[%d] disconnected\n", fd);
  close(fd);
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
  printf("[%d] connected\n", fd);
  return (fd);
}
