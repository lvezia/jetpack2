/*
** run.c for run in /home/vezia_l/rendu/jetpack2Tek3/client/src/
**
** Made by Louis Vezia
** Login   <vezia_l@epitech.eu>
**
** Started on  Thu Jul  7 18:12:38 2016 Louis Vezia
** Last update	Sun Jul 10 16:29:05 2016 Louis Vezia
*/

#include "client.h"

void		init_data(t_client *client)
{
  client->ready = 0;
  client->start = 0;
  client->player.msg = NULL;
  client->player.id = 0;
  client->map.map = NULL;
  client->player.end = 0;
  client->player.score = 0;
}

int		run(t_client *client)
{
  pthread_t             thread;

  init_data(client);
  pthread_mutex_init(&client->map.mutex, NULL);
  pthread_mutex_init(&client->player.mutex, NULL);
  pthread_mutex_init(&client->status, NULL);
  pthread_mutex_lock(&client->status);
  pthread_create(&thread, NULL, graphique, client);
  communication(client);
  pthread_join(thread, NULL);
  return (0);
}
