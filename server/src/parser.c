/*
** parse.c for jetpack2Tek3 in /home/david/dev/syn_pool/jetpack2Tek3/server/src/
**
** Made by David Calo
** Login   <calo_d@epitech.eu>
**
** Started on  Sun Jul 10 12:37:10 2016 David Calo
** Last update Tue Jul 12 21:26:57 2016 David Calo
*/

#include "server.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int		parser(t_fd *cl, char *s)
{
  size_t	i;
  t_pars_fn	tab[] = {&parser_id, &parser_map, &parser_ready, &parser_fire};

  for (i = 0; i < TABLEN(tab); i++)
    if (!tab[i](cl, s))
      return (SUCCESS);
  return (FAIL);
}

int	parser_id(t_fd *cl, char *s)
{
  if (strcasecmp("ID", s))
    return (FAIL);
  if (strlen(cl->wbuf) > 0)
    strcat(cl->wbuf, "\n");
  if (sprintf(cl->wbuf + strlen(cl->wbuf), "ID %d", cl->fd) < 0)
    return (FAIL);
  SET_ID(cl->status);
  return (SUCCESS);
}

int	parser_map(t_fd *cl, char *s)
{
  if (strcasecmp("MAP", s))
    return (FAIL);
  if (strlen(cl->wbuf) > 0)
    strcat(cl->wbuf, "\n");
  if (sprintf(cl->wbuf + strlen(cl->wbuf), "MAP") < 0)
    return (FAIL);
  SET_MAP(cl->status);
  return (SUCCESS);
}

int	parser_ready(t_fd *cl, char *s)
{
  if (strcasecmp("READY", s))
    return (FAIL);
  SET_READY(cl->status);
  return (SUCCESS);
}

int	parser_fire(t_fd *cl, char *s)
{
  char	*tok;

  if (!(IS_READY(cl->status)) ||
      !(tok = strtok(s, " ")) ||
      strcasecmp("FIRE", tok) ||
      !(tok = strtok(NULL, " ")) ||
      (strlen(tok) > 1) ||
      !isdigit(*tok))
    return (FAIL);
  if (atoi(tok) == 1)
    SET_FIRE(cl->status);
  else if (atoi(tok) == 0)
    UNSET_FIRE(cl->status);
  else
    return (FAIL);
  return (SUCCESS);
}
