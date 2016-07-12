/*
** refresh_window.c for refresh_window in /home/vezia_l/rendu/jetpack2Tek3/client/src/
**
** Made by Louis Vezia
** Login   <vezia_l@epitech.eu>
**
** Started on  Mon Jul 11 10:31:47 2016 Louis Vezia
** Last update	Tue Jul 12 10:53:17 2016 Louis Vezia
*/

#include "client.h"

void		refresh_window(t_client *client, t_window *window)
{
  int		i;
  double	xi;
  double	yi;
  char		*grid;
  SDL_Rect	position;

  set_color(window);
  i = 0;
  grid = client->map.map;
  while (i < (client->map.sizeX * client->map.sizeY))
    {
      xi = i % client->map.sizeX;
      yi = i / client->map.sizeX;
      position.x = xi * 15;
      position.y = yi * 15;
      if (grid[i] == 'c')
	create_rect(window, position, window->yellow);
      else if (grid[i] == 'e')
	create_rect(window, position, window->red);
      else
	create_rect(window, position, window->background);
      i++;
    }
  if (client->start == 1)
    show_players(client, window);
}

void		show_players(t_client *client, t_window *window)
{
  SDL_Rect	pos;
  SDL_Rect	pos1;
  SDL_Surface	*player = NULL;
  SDL_Surface	*player1 = NULL;

  pos.x = client->player.x * (double)15;
  pos.y = client->player.y * (double)15;
  pos1.x = client->player.x1 * (double)15;
  pos1.y = client->player.y1 * (double)15;
  player = SDL_CreateRGBSurface(SDL_HWSURFACE, 15, 15, 32, 0, 0, 0, 0);
  player1 = SDL_CreateRGBSurface(SDL_HWSURFACE, 15, 15, 32, 0, 0, 0, 0);
  SDL_FillRect(player, NULL, window->white);
  SDL_FillRect(player1, NULL, window->green);
  SDL_BlitSurface(player, NULL, window->ecran, &pos);
  SDL_BlitSurface(player1, NULL, window->ecran, &pos1);
  SDL_FreeSurface(player);
  SDL_FreeSurface(player1);
}

void		create_rect(t_window *window, SDL_Rect position, Uint32 color)
{
  SDL_Surface	*rectangle = NULL;

  rectangle = SDL_CreateRGBSurface(SDL_HWSURFACE, 15, 15, 32, 0, 0, 0, 0);
  SDL_FillRect(rectangle, NULL, color);
  SDL_BlitSurface(rectangle, NULL, window->ecran, &position);
  SDL_FreeSurface(rectangle);
}

void		set_color(t_window *window)
{
  window->red = SDL_MapRGB(window->ecran->format, 153, 0, 51);
  window->yellow = SDL_MapRGB(window->ecran->format, 255, 204, 51);
  window->white = SDL_MapRGB(window->ecran->format, 255, 255, 255);
  window->green = SDL_MapRGB(window->ecran->format, 255, 102, 255);
  window->background = SDL_MapRGB(window->ecran->format, 51, 0, 153);
}
