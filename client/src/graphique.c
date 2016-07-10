/*
** graphique.c for graphique in /home/vezia_l/rendu/jetpack2Tek3/client/src/
**
** Made by Louis Vezia
** Login   <vezia_l@epitech.eu>
**
** Started on  Thu Jul  7 18:46:09 2016 Louis Vezia
** Last update	Sun Jul 10 17:45:06 2016 Louis Vezia
*/

#include "client.h"

void		set_window(t_client *client)
{
  pthread_mutex_lock(&client->map.mutex);
  client->map.windowX = client->map.sizeX * 15;
  client->map.windowY = client->map.sizeY * 30;
  pthread_mutex_unlock(&client->map.mutex);
}

void		*graphique(void *arg)
{
  t_client	*client;
  SDL_Surface	*ecran = NULL;
  SDL_Surface	*rectangle = NULL;
  SDL_Rect	position;

  client = (t_client *)arg;
  pthread_mutex_lock(&client->status);
  pthread_mutex_unlock(&client->status);
  set_window(client);
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) == -1)
      printf("%s\n", "Error SDL Init");
  else
    {
      position.x = client->map.windowX / 2 - 110;
      position.y = client->map.windowY / 2 - 90;
      ecran = SDL_SetVideoMode(client->map.windowX, client->map.windowY,
			       32, SDL_HWSURFACE | SDL_DOUBLEBUF);
      SDL_WM_SetCaption("jetpack2Tek3", NULL);
      rectangle = SDL_CreateRGBSurface(SDL_HWSURFACE, 220, 180, 32, 0, 0, 0, 0);
      SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 51, 0, 153));
      SDL_FillRect(rectangle, NULL, SDL_MapRGB(ecran->format, 153, 0, 51));
      SDL_BlitSurface(rectangle, NULL, ecran, &position);
      SDL_Flip(ecran);
      play(client);
    }
  SDL_FreeSurface(rectangle);
  SDL_Quit();
  return (NULL);
}
