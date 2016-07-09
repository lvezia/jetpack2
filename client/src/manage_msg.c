/*
** manage_msg.c for manage_msg in /home/vezia_l/rendu/jetpack2Tek3/client/src/
**
** Made by Louis Vezia
** Login   <vezia_l@epitech.eu>
**
** Started on  Fri Jul  8 11:55:32 2016 Louis Vezia
** Last update	Sat Jul 09 18:36:08 2016 Louis Vezia
*/

#include "client.h"

void		get_info_player(t_client *client)
{
  int		i;
  char		*tab[5];
  char		*msg;

  i = 0;
  msg = client->player.msg;
  if (strstr(msg, "PLAYER") != 0)
    {
      tab[i] = strtok(msg, " ");
      i++;
      while (i < 5)
	{
	  if (i != 4)
	    {
	      tab[i] = strtok(NULL, " ");
	    }
	  else
	    tab[i] = strtok(NULL, "\n");
	  i++;
	}
      refresh_player(client, tab);
    }
}

void		get_info_coins(t_client *client)
{
  int		i;
  char		*tab[4];
  char		*msg;

  i = 0;
  msg = client->player.msg;
  if (strstr(msg, "COIN") != 0)
    {
      tab[i] = strtok(msg, " ");
      i++;
      while (i < 4)
	{
	  if (i != 3)
	    {
	      tab[i] = strtok(NULL, " ");
	    }
	  else
	    tab[i] = strtok(NULL, "\n");
	  printf("%s\n", tab[i]);
	  i++;
	}
      refresh_coins(client, tab);
    }
}

void		handle_game(t_client *client)
{
  get_info_player(client);
  get_info_coins(client);
}

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
  handle_game(client);
  return (check_end(client));
}
