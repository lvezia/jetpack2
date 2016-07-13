/*
** map.c for jetpack2Tek3 in /home/david/dev/syn_pool/jetpack2Tek3/server/src/
**
** Made by David Calo
** Login   <calo_d@epitech.eu>
**
** Started on  Wed Jul 13 19:47:23 2016 David Calo
** Last update Wed Jul 13 22:25:47 2016 David Calo
*/

#include "server.h"

#include <stdio.h>
#include <string.h>

int	map_border(t_player *p, t_game *g)
{
  if (p->y < 0.0f)
    {
      p->vel = 0.0f;
      p->y = 0.0f;
    }
  else if (p->y >= g->my - PL_SIZE)
    {
      p->vel = 0.0f;
      p->y = g->my - PL_SIZE;
    }
  if (p->x >= g->mx)
    return (10);
  return (SUCCESS);
}

void	map_set_pos(t_game *g, int n, char c)
{
  g->map[n] = c;
}

int	map_get_pos(t_player *p, t_game *g, char (*c)[], char del)
{
  int	n[4];
  int	of;

  of = (g->my);
  n[0] = ((int)(of - p->y) * (g->mx)) + (int)(p->x);
  n[1] = ((int)(of - (p->y + PL_SIZE)) * (g->mx)) + (int)(p->x);
  n[2] = ((int)(of - p->y) * (g->mx)) + (int)(p->x  + PL_SIZE);
  n[3] = ((int)(of - (p->y + PL_SIZE)) * (g->mx)) + (int)(p->x + PL_SIZE);
  (*c)[0] = g->map[n[0]];
  g->map[n[0]] = (del && g->map[n[0]] == 'c' ? '_' : g->map[n[0]]);
  (*c)[1] = g->map[n[1]];
  g->map[n[1]] = (del && g->map[n[1]] == 'c' ? '_' : g->map[n[1]]);
  (*c)[2] = g->map[n[2]];
  g->map[n[2]] = (del && g->map[n[2]] == 'c' ? '_' : g->map[n[2]]);
  (*c)[3] = g->map[n[3]];
  g->map[n[3]] = (del && g->map[n[3]] == 'c' ? '_' : g->map[n[3]]);
  return (SUCCESS);
}

int	map_object(t_player *p, t_game *g)
{
  char	c[4];

  memset(c, 0, TABLEN(c));
  map_get_pos(p, g, &c, 0);
  if (c[0] != '_' || c[1] != '_' || c[2] != '_' || c[3] != '_')
    {
      if (c[0] == 'e' || c[1] == 'e' || c[2] == 'e' || c[3] == 'e')
	return (FAIL);
      if (c[0] == 'c' || c[1] == 'c' || c[2] == 'c' || c[3] == 'c')
	return (2);
    }
  return (SUCCESS);
}

int		map_coin(t_game *g, t_fd *cl, int n, char (*s)[])
{
  char		c[4];
  size_t	i;
  // int	x;
  // int	y;

  memset(c, 0, 4);
  map_get_pos(&g->player[n], g, &c, 1);
  for (i = 0; i < 4; i++)
    {
      if (c[i] == 'c')
	{
	  sprintf(*s + strlen(*s), "%sCOIN %d %d %d", (**s ? "\n" : ""),
		  list_get(cl, n)->fd,
		  (int)(g->player[n].x + (i > 1 ? PL_SIZE : 0.0f)),
		  (int)(g->player[n].y + (i % 2 ? PL_SIZE : 0.0f)));
	  g->player[n].score += 1;
	//   map_set_pos(g, n, '_');
	}
    }
  return (SUCCESS);
}
