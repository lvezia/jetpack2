/*
** client.c for jetpack2Tek3 in /home/david/dev/syn_pool/jetpack2Tek3/server/src/
**
** Made by David Calo
** Login   <calo_d@epitech.eu>
**
** Started on  Fri Jul  8 11:17:29 2016 David Calo
** Last update Sat Jul  9 14:41:42 2016 David Calo
*/

#include "server.h"

#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

int	client_read(t_server *s, size_t n)
{
  char		*line;
  size_t	len;
  ssize_t	read;
  FILE		*sock;

  if ((sock = fdopen(list_get(s->client, n)->fd, "r")) == NULL)
    return (xperror("fdopen"));
  line = NULL;
  len = 0;
  if ((read = getline(&line, &len, sock)) == -1)
    {
      if (errno == EINVAL)
	perror("getline");
      perror("get_line");
      return (FAIL);
    }
  line[read - 1] = 0;
  printf("[%d] %s", list_get(s->client, n)->fd, line);
  free(line);
  return (SUCCESS);
}
int	client_write(t_server *s, size_t n)
{
  (void)s;
  (void)n;
  return (SUCCESS);
}
int	client_close(t_fd *cl, size_t n)
{
  close(list_get(cl, n)->fd);
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
