/*
** player.c for player in /home/vezia_l/rendu/jetpack2Tek3/client/src/
**
** Made by Louis Vezia
** Login   <vezia_l@epitech.eu>
**
** Started on  Thu Jul  7 18:44:39 2016 Louis Vezia
** Last update	Sat Jul 09 18:32:11 2016 Louis Vezia
*/

#include "client.h"

void		set_value(t_client *client, fd_set *fd_read,
			  fd_set *fd_write, struct timeval *tv)
{
  FD_ZERO(fd_read);
  FD_SET(client->fd, fd_read);
  FD_ZERO(fd_write);
  FD_SET(client->fd, fd_write);
  tv->tv_sec = 0;
  tv->tv_usec = 50000;
}

int	 	communication(t_client *client)
{
  fd_set                fd_read;
  fd_set                fd_write;
  struct timeval        tv;

  set_value(client, &fd_read, &fd_write, &tv);
  usleep(100);
  while ((select((client->fd) + 1, &fd_read, &fd_write, NULL, &tv)) >= 0 &&
	 client->player.end == 0)
    {
      if (FD_ISSET(client->fd, &fd_read))
	{
	  if (stock_msg(client) == 1)
	    return (0);
	}
      if (FD_ISSET(client->fd, &fd_write))
	set_client(client);
      set_value(client, &fd_read, &fd_write, &tv);
    }
  return (0);
}

void		*play(t_client *client)
{
  client->ready = 0;
  client->player.msg = NULL;
  client->player.id = 0;
  client->map.map = NULL;
  client->player.end = 0;
  client->player.score = 0;
  communication(client);
  return (NULL);
}
