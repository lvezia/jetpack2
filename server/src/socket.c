/*
** socket.c for jetpack2Tek3 in /home/david/dev/syn_pool/jetpack2Tek3/server/src/
**
** Made by David Calo
** Login   <calo_d@epitech.eu>
**
** Started on  Fri Jul  8 09:34:31 2016 David Calo
** Last update Fri Jul  8 10:02:56 2016 David Calo
*/

#include "server.h"

#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

int			set_socket(t_server *s)
{
  struct protoent	*pe;
  int			opt;

  if ((pe = getprotobyname("TCP")) == NULL)
    return (xputerror("getprotobyname: Failed"));
  if ((s->fd = socket(AF_INET, SOCK_STREAM, pe->p_proto)) == -1)
    return (xperror("socket"));
  opt = 1;
  if (setsockopt(s->fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)))
    return (xperror("setsockopt"));
  s->max_fd = s->fd;
  return (SUCCESS);
}

int	bind_listen_socket(t_server *s)
{
  struct sockaddr_in	sin;

  sin.sin_family = AF_INET;
  sin.sin_port = htons(s->port);
  sin.sin_addr.s_addr = INADDR_ANY;
  if (bind(s->fd, (struct sockaddr *)&sin, sizeof(sin)))
    return (xperror("bind"));
  if (listen(s->fd, LISTEN_MAX_CLIENT))
    return (xperror("listen"));
  return (SUCCESS);
}
