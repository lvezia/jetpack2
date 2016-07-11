/*
** refresh_window.c for refresh_window in /home/vezia_l/rendu/jetpack2Tek3/client/src/
**
** Made by Louis Vezia
** Login   <vezia_l@epitech.eu>
**
** Started on  Mon Jul 11 10:31:47 2016 Louis Vezia
** Last update	Mon Jul 11 14:22:08 2016 Louis Vezia
*/

#include "client.h"

void		show_players()
{

}

void		create_rect(t_window *window, SDL_Rect position)
{
  SDL_Surface	*rectangle = NULL;
  // Uint32	color = SDL_MapRGB(window->ecran->format, 153, 0, 51);

  rectangle = SDL_CreateRGBSurface(SDL_HWSURFACE, 220, 180, 32, 0, 0, 0, 0);
  SDL_FillRect(rectangle, NULL, SDL_MapRGB(window->ecran->format, 153, 0, 51));
  SDL_BlitSurface(rectangle, NULL, window->ecran, &position);
  SDL_FreeSurface(rectangle);
}

void		refresh_window(t_client *client, t_window *window)
{
  SDL_Rect	position;

  position.x = client->map.windowX / 2 - 110;
  position.y = client->map.windowY / 2 - 90;
  create_rect(window, position);
}
