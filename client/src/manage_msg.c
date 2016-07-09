/*
** manage_msg.c for manage_msg in /home/vezia_l/rendu/jetpack2Tek3/client/src/
**
** Made by Louis Vezia
** Login   <vezia_l@epitech.eu>
**
** Started on  Fri Jul  8 11:55:32 2016 Louis Vezia
** Last update	Sat Jul 09 11:57:32 2016 Louis Vezia
*/

#include "client.h"

int		check_end(t_client *client)
{
  int		i;
  int		tmp_id;
  char		*msg;
  char		*check;

  i = 0;
  msg = client->player.msg;
  if ((check = strstr(client->player.msg, "FINISH")) != 0)
    {
      while (msg[i] && msg[i] != ' ')
	i++;
      tmp_id = atoi(&msg[i]);
      if (tmp_id == client->player.id)
	printf("%s\n", "You win!");
      else if (tmp_id == -1)
        printf("%s\n", "Nobody wins");
      else
	printf("%s\n", "You loose!");
      return (1);
    }
  return (0);
}

int		stock_msg(t_client *client)
{
  int		pos;
  char		tmp[2];
  char		buffer[1024];

  pos = 0;
  memset(tmp, '\0', 2);
  memset(buffer, 0, 1024);
  while (read(client->fd, tmp, 1) > 0)
    {
      buffer[pos] = tmp[0];
      pos++;
      if (buffer[pos -1] == '\n')
	break;
    }
  client->player.msg = buffer;
  return (check_end(client));
}
