/*
** manage_msg.c for manage_msg in /home/vezia_l/rendu/jetpack2Tek3/client/src/
**
** Made by Louis Vezia
** Login   <vezia_l@epitech.eu>
**
** Started on  Fri Jul  8 11:55:32 2016 Louis Vezia
** Last update	Wed Jul 13 15:31:40 2016 Louis Vezia
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
	  tab[i] = strtok(NULL, " ");
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
	  tab[i] = strtok(NULL, " ");
	  i++;
	}
      refresh_coins(client, tab);
    }
}

void		handle_game(t_client *client)
{
  get_info_player(client);
  get_info_coins(client);
  get_start(client);
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
      client->player.end = 1;
      while (msg[i] && msg[i] != ' ')
	i++;
      tmp_id = atoi(&msg[i]);
      printf("Score : %d\n", client->player.score);
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
  int		p;
  int		c;
  char		tmp[2];
  char		buffer[1024];

  memset(tmp, '\0', 2);
  memset(buffer, '\0', 1024);
  for (p = 0, c = 0; c < 1024; p++, c++)
    {
      if (read(client->fd, tmp, 1) < 1)
	  return ((client->player.end = 1));
      buffer[p] = tmp[0];
      if (buffer[p] == '\n')
	break;
    }
  buffer[p] = '\0';
  pthread_mutex_lock(&client->player.mutex);
  if (client->player.msg != NULL)
    free(client->player.msg);
  client->player.msg = strdup(buffer);
  pthread_mutex_unlock(&client->player.mutex);
  handle_game(client);
  return (check_end(client));
}
