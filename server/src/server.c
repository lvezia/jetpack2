/*
** server.c for jetpack2Tek3 in /home/david/dev/syn_pool/jetpack2Tek3/server/src/
**
** Made by David Calo
** Login   <calo_d@epitech.eu>
**
** Started on  Fri Jul  8 14:59:50 2016 David Calo
** Last update Fri Jul  8 20:58:41 2016 David Calo
*/

#include "server.h"

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	server_read(t_server *s)
{
  int	fd;

  if ((fd = client_accept(s->client->fd)) == FAIL)
    return (FAIL);
  return (list_add(s->client, list_new(fd, &client_read, &client_write)));
  return (SUCCESS);
}
int	server_write(t_server *s)
{
  (void)s;
  write(1, "SERVER_WRITE\n", 13);
  return (SUCCESS);
}

int	server_init(t_server *s)
{
  int	fd;
  if ((fd = get_socket()) == FAIL ||
      bind_listen_socket(fd, s->port))
    return (FAIL);
  printf("sfd: %d\n", fd);
  s->client = list_new(fd, &server_read, &server_write);
  s->max_fd = s->client->fd;
  // s->cl.size = 0;
  // s->cl.fd = malloc(sizeof(s->cl.fd) * 2);
  return (SUCCESS);
}
