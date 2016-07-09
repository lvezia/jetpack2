/*
** set_game.c for set_game in /home/vezia_l/rendu/jetpack2Tek3/client/src/
**
** Made by Louis Vezia
** Login   <vezia_l@epitech.eu>
**
** Started on  Fri Jul  8 16:20:12 2016 Louis Vezia
** Last update	Sat Jul 09 18:32:46 2016 Louis Vezia
*/

#include "client.h"

void		set_client(t_client *client)
{
  if (client->player.id == 0)
    ask_id(client);
  if (client->map.map == NULL)
    ask_map(client);
  if (client->map.map != NULL && client->player.id != 0 && client->ready == 0)
    call_ready(client);
}

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
  int		i;
  char		tmp[2048];
  char		*tab[4];

  i = 0;
  write (client->fd, "MAP\n", 4);
  memset(tmp, '\0', 1024);
  if (read(client->fd, tmp, 1024) == -1)
    return;
  tab[i] = strtok(tmp, " ");
  i++;
  while (i < 4)
    {
      if (i != 3)
	tab[i] = strtok(NULL, " ");
      else
	tab[i] = strtok(NULL, "\n");
      i++;
    }
  client->map.sizeX = atoi(tab[1]);
  printf("Mon size X : %d\n", client->map.sizeX);
  client->map.sizeY = atoi(tab[2]);
  printf("Mon size Y : %d\n", client->map.sizeY);
  client->map.map = strdup(tab[3]);
  printf("MAP : %s\n", client->map.map);
}

void		call_ready(t_client *client)
{
  write (client->fd, "READY\n", 6);
  client->ready = 1;
  printf("%s\n", "READY");
  return;
}
