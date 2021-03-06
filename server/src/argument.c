/*
** argument.c for jetpack2Tek3 in /home/david/dev/jetpack2Tek3/server/src/
**
** Made by David Calo
** Login   <calo_d@epitech.eu>
**
** Started on  Thu Jul  7 14:58:19 2016 David Calo
** Last update Wed Jul 13 11:18:05 2016 David Calo
*/

#include <string.h>
#include <stdlib.h>

#include "server.h"

int		arg_read(int ac, char const *av[], t_server *s)
{
  static char	*args[] = {"-p", "-g", "-m"};
  t_arg_fn	fn[3];
  int		i;
  size_t	j;

  s->port = 0;
  s->game.gravity = 0;
  s->game.map = NULL;
  fn[0] = &arg_port;
  fn[1] = &arg_gravity;
  fn[2] = &arg_map;
  if (ac % 2 == 0)
    return (print_usage(av[0]));
  for (i = 1; i < ac; i += 2)
    for (j = 0; j < TABLEN(args); j++)
      if (strcmp(args[j], av[i]) == 0)
	if (fn[j](av[i + 1], s))
	  return (print_usage(av[0]));
  if (!s->port || !s->game.gravity || s->game.map == NULL)
    return (print_usage(av[0]));
  return (SUCCESS);
}

int		arg_port(char const *arg, t_server *s)
{
  if (check_int(arg))
    return (FAIL);
  s->port = atoi(arg);
  return (SUCCESS);
}

int		arg_gravity(char const *arg, t_server *s)
{
  if (check_float(arg))
    return (FAIL);
  s->game.gravity = atof(arg);
  return (SUCCESS);
}

int	arg_map(char const *arg, t_server *s)
{
  if ((s->game.map = read_file(arg)) == NULL)
    return (xputerror("read_file: Failed"));
  return (SUCCESS);
}
