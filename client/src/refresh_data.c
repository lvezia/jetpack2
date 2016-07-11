/*
** refresh_data.c for refresh_data in /home/vezia_l/rendu/jetpack2Tek3/client/src/
**
** Made by Louis Vezia
** Login   <vezia_l@epitech.eu>
**
** Started on  Sat Jul  9 16:25:04 2016 Louis Vezia
** Last update	Mon Jul 11 16:08:52 2016 Louis Vezia
*/

#include "client.h"

void		refresh_player(t_client *client, char **tab)
{
  if (atoi(tab[1]) == client->player.id)
    {
      pthread_mutex_lock(&client->player.mutex);
      client->player.x = atoi(tab[2]);
      client->player.y = atoi(tab[3]);
      client->player.score = atoi(tab[4]);
      pthread_mutex_unlock(&client->player.mutex);
    }
  else
    {
      pthread_mutex_lock(&client->player.mutex);
      client->player.x1 = atoi(tab[2]);
      client->player.y1 = atoi(tab[3]);
      client->player.score1 = atoi(tab[4]);
      pthread_mutex_unlock(&client->player.mutex);
    }
}

void	refresh_coins(t_client *client, char **tab)
{
  int	pos;
  int	x;
  int	y;

  x = atoi(tab[2]);
  y = atoi(tab[3]);
  pos = (x * y) + atoi(tab[3]);
  pthread_mutex_lock(&client->player.mutex);
  client->map.map[pos] = '_';
  pthread_mutex_unlock(&client->player.mutex);
    }
}

void	get_start(t_client *client)
{
  char	*msg;

  msg = client->player.msg;
  if (strstr(msg, "START") != 0)
    {
      pthread_mutex_lock(&client->player.mutex);
      client->start = 1;
      pthread_mutex_unlock(&client->player.mutex);
      printf("%s\n", "START");
    }
}
