/*
** run.c for run in /home/vezia_l/rendu/jetpack2Tek3/client/src/
**
** Made by Louis Vezia
** Login   <vezia_l@epitech.eu>
**
** Started on  Thu Jul  7 18:12:38 2016 Louis Vezia
** Last update	Fri Jul 08 13:09:36 2016 Louis Vezia
*/

#include "client.h"

int		run(t_client *client)
{
  pthread_t             thread;

  play(client);
  pthread_mutex_init(&client->map.mutex, NULL);
  pthread_create(&thread, NULL, graphique, &client);
  pthread_join(thread, NULL);
  return (0);
}
