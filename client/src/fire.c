/*
** fire.c for fire in /home/vezia_l/rendu/jetpack2Tek3/client/src/
**
** Made by Louis Vezia
** Login   <vezia_l@epitech.eu>
**
** Started on  Mon Jul 11 10:12:54 2016 Louis Vezia
** Last update	Tue Jul 12 10:14:45 2016 Louis Vezia
*/

#include "client.h"

void		fire_on(t_client *client)
{
  write(client->fd, "FIRE 1\n", 7);
}

void		fire_off(t_client *client)
{
  write(client->fd, "FIRE 0\n", 7);
}
