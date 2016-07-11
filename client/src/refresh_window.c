/*
** refresh_window.c for refresh_window in /home/vezia_l/rendu/jetpack2Tek3/client/src/
**
** Made by Louis Vezia
** Login   <vezia_l@epitech.eu>
**
** Started on  Mon Jul 11 10:31:47 2016 Louis Vezia
** Last update	Mon Jul 11 18:00:53 2016 Louis Vezia
*/

#include "client.h"

void		show_players()
{

}

void		create_rect(t_window *window, SDL_Rect position, Uint32 color)
{
  SDL_Surface	*rectangle = NULL;

  rectangle = SDL_CreateRGBSurface(SDL_HWSURFACE, 15, 30, 32, 0, 0, 0, 0);
  SDL_FillRect(rectangle, NULL, color);
  SDL_BlitSurface(rectangle, NULL, window->ecran, &position);
  SDL_FreeSurface(rectangle);
}

void		refresh_window(t_client *client, t_window *window)
{
  int		i;
  int		xi;
  int		yi;
  char		*grid;
  SDL_Rect	position;
  Uint32	red = SDL_MapRGB(window->ecran->format, 153, 0, 51);
  Uint32	yellow = SDL_MapRGB(window->ecran->format, 255, 204, 51);
  // Uint32	blue = SDL_MapRGB(window->ecran->format, 0, 0, 102);

  i = 0;
  grid = client->map.map;
  while (i < (client->map.sizeX * client->map.sizeY))
    {
      xi = i % client->map.sizeX;
      yi = i / client->map.sizeX;
      position.x = xi * 15;
      position.y = yi * 30;
      if (grid[i] == 'c')
	{
	//   printf("x: %d y: %d  MX %d & MY %d\n", position.x, position.y, client->map.sizeX, client->map.sizeY);
	  create_rect(window, position, yellow);
	}
      else if (grid[i] == 'e')
	{
	//   printf("x: %d y: %d  MX %d MY %d\n", position.x, position.y, client->map.sizeX, client->map.sizeY);
	  create_rect(window, position, red);
	}
      i++;
    }
}
