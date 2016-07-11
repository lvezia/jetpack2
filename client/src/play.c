/*
** play.c for play in /home/vezia_l/rendu/jetpack2Tek3/client/src/
**
** Made by Louis Vezia
** Login   <vezia_l@epitech.eu>
**
** Started on  Sun Jul 10 11:37:05 2016 Louis Vezia
** Last update	Mon Jul 11 15:47:39 2016 Louis Vezia
*/

#include "client.h"

int	play(t_client *client, t_window *window)
{
  while (client->player.end == 0)
    {
      SDL_PollEvent(&window->event);
      switch (window->event.type)
	{
	  SDL_PollEvent(&window->event);
	  case SDL_QUIT:
	  client->player.end = 1;
	  return (0);
	  case SDL_KEYDOWN:
	  if (window->event.key.keysym.sym == SDLK_ESCAPE)
	    client->player.end = 1;
	  else if (window->event.key.keysym.sym == SDLK_SPACE)
	    fire_on(client);
	  break;
	  case SDL_KEYUP:
	  if (window->event.key.keysym.sym == SDLK_SPACE)
	    fire_off(client);
	  default:
	  break;
	}
      refresh_window(client, window);
      SDL_Flip(window->ecran);
    }
  return (0);
}
