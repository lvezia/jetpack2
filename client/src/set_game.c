/*
** set_game.c for set_game in /home/vezia_l/rendu/jetpack2Tek3/client/src/
**
** Made by Louis Vezia
** Login   <vezia_l@epitech.eu>
**
** Started on  Fri Jul  8 16:20:12 2016 Louis Vezia
** Last update	Fri Jul 08 17:58:48 2016 Louis Vezia
*/

#include "client.h"

void		ask_id(t_client *client)
{
  char                  tmp[1024];
  char                  tmp2[1024];
  int                   pos;
  int			posId;

  pos = 0;
  posId = 0;
  write (client->fd, "ID\n", 3);
  memset(tmp, '\0', 1024);
  memset(tmp2, '\0', 1024);
  if (read(client->fd, tmp, 1024) == -1)
    return;
  while (tmp[pos] != '\n' && tmp[pos])
    {
      if (tmp[pos] > 47 && tmp[pos] < 58)
	{
	  tmp2[posId] = tmp[pos];
	  posId++;
	}
      pos++;
    }
  client->player.id = atoi(tmp2);
  printf("ID player : %d\n", client->player.id);
}

void		ask_map(t_client *client)
{
  char                  tmp[1024];
  char                  tmp2[1024];
  int                   pos;

  pos = 0;
  printf("%s\n", "On demande la map\n");
  write (client->fd, "MAP\n", 4);
  memset(tmp, '\0', 1024);
  memset(tmp2, '\0', 1024);
  if (read(client->fd, tmp, 1024) == -1)
    return;
  while (tmp[pos] != '\n' && tmp[pos])
    {
      tmp2[pos] = tmp[pos];
      pos++;
    }
  printf("%s\n", tmp);
  client->map.map = tmp2;
}

void		call_ready(t_client *client)
{
  client->ready = 1;
  return;
}
