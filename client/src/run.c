/*
** run.c for run in /home/vezia_l/rendu/jetpack2Tek3/client/src/
**
** Made by Louis Vezia
** Login   <vezia_l@epitech.eu>
**
** Started on  Thu Jul  7 18:12:38 2016 Louis Vezia
** Last update	Thu Jul 07 19:24:27 2016 Louis Vezia
*/

#include "client.h"

int		run(t_client *client)
{
  pthread_mutex_init(&client->player.mutex, NULL);
  pthread_mutex_init(&client->map.mutex, NULL);
  pthread_create(&client->player.thread, NULL, play, &client->player);
  pthread_create(&client->map.thread, NULL, graphique, &client->map);
  pthread_join(client->player.thread, NULL);
  pthread_join(client->map.thread, NULL);
  return (0);
}
