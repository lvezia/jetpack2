/*
** client.c for jetpack2Tek3 in /home/david/dev/syn_pool/jetpack2Tek3/server/src/
**
** Made by David Calo
** Login   <calo_d@epitech.eu>
**
** Started on  Fri Jul  8 11:17:29 2016 David Calo
** Last update Fri Jul  8 19:15:18 2016 David Calo
*/

#include "server.h"

#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>

int	client_read(t_server *s)
{
  (void)s;
  return (SUCCESS);
}
int	client_write(t_server *s)
{
  (void)s;
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
