/*
** main.c for jetpack2Tek3 in /home/vezia_l/rendu/jetpack2Tek3/client/src/
**
** Made by Louis Vezia
** Login   <vezia_l@epitech.eu>
**
** Started on  Thu Jul  7 11:09:35 2016 Louis Vezia
** Last update	Sat Jul 09 10:29:41 2016 Louis Vezia
*/

#include "client.h"

int	my_put_error(char *str)
{
  write(2, str, strlen(str));
  write(2, "\n", 1);
  return (84);
}

int		main(int ac, char **av)
{
  t_client	client;

  if (ac != 5)
    return (my_put_error("USAGE : ./clientJ2T3 -h <ip> -p <port>"));
  pars_arg(ac, av, &client);
  if (init_socket(&client) == 84)
    return (84);
  run(&client);
  return (0);
}
