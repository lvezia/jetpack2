/*
** argument.c for jetpack2Tek3 in /home/david/dev/jetpack2Tek3/server/src/
**
** Made by David Calo
** Login   <calo_d@epitech.eu>
**
** Started on  Thu Jul  7 14:58:19 2016 David Calo
** Last update Thu Jul  7 19:03:33 2016 David Calo
*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#include "server.h"

t_bool		arg_read(int ac, char const *av[], t_server *s)
{
  static char	*args[] = {"-p", "-g", "-m"};
  t_bool	(*fn[6])(char const *, t_server *);
  int		i;
  size_t	j;

  fn[0] = &arg_port;
  fn[1] = &arg_gravity;
  fn[2] = &arg_map;
  if (ac % 2 == 0)
    return (FALSE);
  for (i = 1; i < ac; i += 2)
    for (j = 0; j < TABLEN(args); j++)
      if (strcmp(args[j], av[i]) == 0)
	if (!fn[j](av[i + 1], s))
	  {
	    return (xputerror("Invalid argument"));
	  }
  return (TRUE);
}

t_bool		arg_port(char const *arg, t_server *s)
{
  size_t	i;

  if (!arg)
    return (FALSE);
  for (i = 0; arg[i]; i++)
    if (!isdigit(arg[i]))
      return (FALSE);
  s->port = atoi(arg);
  return (TRUE);
}

t_bool		arg_gravity(char const *arg, t_server *s)
{
  size_t	i;

  if (!arg)
    return (FALSE);
  for (i = 0; arg[i]; i++)
    if (!isdigit(arg[i]) && arg[i] != '.')
      return (FALSE);
  s->gravity = atof(arg);
  return (TRUE);
}

t_bool	arg_map(char const *arg, t_server *s)
{
  FILE	*file;
  char	*buf;
  long	len;

  if (!arg)
    return (FALSE);
  if ((file = fopen(arg, "r")) == NULL)
    return (FALSE);
  if (fseek(file, 0, SEEK_END) ||
      (len = ftell(file)) == -1 ||
      fseek(file, 0, SEEK_SET) ||
      (buf = malloc(len)) == NULL ||
      !fread(buf, 1, len, file))
    {
      if (fclose(file))
	return (FALSE);
      return (FALSE);
    }
  s->map = buf;
  if (fclose(file))
    return (FALSE);
  return (TRUE);
}
