/*
** socket.c for jetpack2Tek3 in /home/david/dev/syn_pool/jetpack2Tek3/server/src/
**
** Made by David Calo
** Login   <calo_d@epitech.eu>
**
** Started on  Fri Jul  8 09:34:31 2016 David Calo
** Last update Fri Jul  8 19:21:26 2016 David Calo
*/

#include "server.h"

#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <stdio.h>

int			get_socket()
{
  struct protoent	*pe;
  int			opt;
  int			fd;

  if ((pe = getprotobyname("TCP")) == NULL)
    return (xputerror("getprotobyname: Failed"));
  if ((fd = socket(AF_INET, SOCK_STREAM, pe->p_proto)) == -1)
    return (xperror("socket"));
  opt = 1;
  if (setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)))
    return (xperror("setsockopt"));
  return (fd);
}

int	bind_listen_socket(int fd, PORT port)
{
  struct sockaddr_in	sin;

  sin.sin_family = AF_INET;
  printf("%hu - %hu\n", port, htons(port));
  sin.sin_port = htons(port);
  sin.sin_addr.s_addr = INADDR_ANY;
  if (bind(fd, (struct sockaddr *)&sin, sizeof(sin)))
    return (xperror("bind"));
  if (listen(fd, LISTEN_MAX_CLIENT))
    return (xperror("listen"));
  return (SUCCESS);
}
