/*
** manage_msg.c for manage_msg in /home/vezia_l/rendu/jetpack2Tek3/client/src/
**
** Made by Louis Vezia
** Login   <vezia_l@epitech.eu>
**
** Started on  Fri Jul  8 11:55:32 2016 Louis Vezia
** Last update	Fri Jul 08 16:21:26 2016 Louis Vezia
*/

#include "client.h"

void		stock_msg(t_client *client)
{
  int		pos;
  char		tmp[2];

  pos = 0;
  memset(tmp, '\0', 2);
  while (read(client->fd, tmp, 1) > 0)
    {
      client->player.msg[pos] = tmp[0];
      pos++;
      if (client->player.msg[pos -1] == '\n')
	break;
    }
  printf("%s\n", client->player.msg);
}
