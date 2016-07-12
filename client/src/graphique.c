/*
** graphique.c for graphique in /home/vezia_l/rendu/jetpack2Tek3/client/src/
**
** Made by Louis Vezia
** Login   <vezia_l@epitech.eu>
**
** Started on  Thu Jul  7 18:46:09 2016 Louis Vezia
** Last update	Tue Jul 12 10:24:18 2016 Louis Vezia
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
  t_window	window;

  window.ecran = NULL;
  client = (t_client *)arg;
  pthread_mutex_lock(&client->status);
  pthread_mutex_unlock(&client->status);
  set_window(client);
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) == -1)
      printf("%s\n", "Error SDL Init");
  else
    {
      window.ecran = SDL_SetVideoMode(client->map.windowX, client->map.windowY,
			       32, SDL_HWSURFACE | SDL_DOUBLEBUF);
      SDL_EnableKeyRepeat(50, 50);
      SDL_WM_SetCaption("jetpack2Tek3", NULL);
      SDL_FillRect(window.ecran, NULL, SDL_MapRGB(window.ecran->format,
						  51, 0, 153));
      play(client, &window);
    }
  SDL_Quit();
  return (NULL);
}
