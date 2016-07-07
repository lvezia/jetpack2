/*
** init.c for init in /home/vezia_l/rendu/jetpack2Tek3/client/src/
**
** Made by Louis Vezia
** Login   <vezia_l@epitech.eu>
**
** Started on  Thu Jul  7 14:00:17 2016 Louis Vezia
** Last update	Thu Jul 07 17:45:36 2016 Louis Vezia
*/

#include "client.h"

int     init_socket(t_client *client)
{
  struct protoent       *pe;
  struct sockaddr_in    s_in;

  if (!client)
    return (1);
  if ((pe = getprotobyname("TCP")) == NULL)
    return (1);
  if ((client->fd = socket(AF_INET, SOCK_STREAM, pe->p_proto)) == -1)
    return (my_put_error("Error : Socket"));
  s_in.sin_family = AF_INET;
  s_in.sin_port = htons(client->port);
  s_in.sin_addr.s_addr = inet_addr(client->ip);
  if (connect(client->fd, (struct sockaddr *)&(s_in), sizeof(s_in)) == -1)
    return (my_put_error("Error : Cannot listen on port"));
  return (0);
}
