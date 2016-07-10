/*
** pars_arg.c for pars_arg in /home/vezia_l/rendu/jetpack2Tek3/client/src/
**
** Made by Louis Vezia
** Login   <vezia_l@epitech.eu>
**
** Started on  Thu Jul  7 14:22:46 2016 Louis Vezia
** Last update	Sun Jul 10 10:16:26 2016 Louis Vezia
*/

#include "client.h"

int	pars_arg(int ac, char **av, t_client *client)
{
  int	pos;

  pos = 0;
  client->port = 0;
  while (pos < ac)
    {
      if (strcmp(av[pos], "-p") == 0 && atoi(av[pos + 1]) > 1)
        client->port = atoi(av[pos + 1]);
      if (strcmp(av[pos], "-h") == 0 && av[pos + 1][0] != '-' && av[pos + 1])
	{
	  if (strcmp(av[pos + 1], "localhost") == 0)
	    client->ip = strdup("127.0.0.1");
	  else
	    client->ip = strdup(av[pos + 1]);
	}
      pos++;
    }
  if (client->port == 0)
    return (my_put_error("USAGE : ./clientJ2T3 -h <ip> -p <port>"));
  return (0);
}
