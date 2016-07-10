/*
** play.c for play in /home/vezia_l/rendu/jetpack2Tek3/client/src/
**
** Made by Louis Vezia
** Login   <vezia_l@epitech.eu>
**
** Started on  Sun Jul 10 11:37:05 2016 Louis Vezia
** Last update	Sun Jul 10 17:43:17 2016 Louis Vezia
*/

#include "client.h"

int	play(t_client *client)
{
  SDL_Event	event;

  while (client->player.end == 0)
    {
      SDL_WaitEvent(&event);
      switch (event.type)
	{
	  SDL_WaitEvent(&event);
	  case SDL_QUIT:
	  client->player.end = 1;
	  return (0);
	  break;
	}
    }
  return (0);
}
