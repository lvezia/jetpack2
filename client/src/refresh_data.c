/*
** refresh_data.c for refresh_data in /home/vezia_l/rendu/jetpack2Tek3/client/src/
**
** Made by Louis Vezia
** Login   <vezia_l@epitech.eu>
**
** Started on  Sat Jul  9 16:25:04 2016 Louis Vezia
** Last update	Sat Jul 09 18:35:46 2016 Louis Vezia
*/

#include "client.h"

void		refresh_player(t_client *client, char **tab)
{
  if (atoi(tab[1]) == client->player.id)
    {
      client->player.x = atoi(tab[2]);
      client->player.y = atoi(tab[3]);
      client->player.score = atoi(tab[4]);
    }
}

void	refresh_coins(t_client *client, char **tab)
{
  int	pos;
  int	x;
  int	y;

  if (atoi(tab[1]) == client->player.id)
    {
      x = atoi(tab[2]);
      y = atoi(tab[3]);
      pos = (x * y) + atoi(tab[3]);
      client->map.map[pos] = '_';
    }
}
