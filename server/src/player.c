/*
** player.c for jetpack2Tek3 in /home/david/dev/syn_pool/jetpack2Tek3/server/src/
**
** Made by David Calo
** Login   <calo_d@epitech.eu>
**
** Started on  Mon Jul 11 16:57:06 2016 David Calo
** Last update Wed Jul 13 23:47:40 2016 David Calo
*/

#include "server.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int		player_position(t_player *p, t_game *g, double step, int has_fire)
{
  int		r;

  p->fire = has_fire;
  if ((r = map_object(p, g)) == 1)
    return (r);
  p->x += MOV_SPEED * step;
  p->vel += step * -(g->gravity) * p->fire;
  p->y += step * p->vel;
  r += map_border(p, g);
  return (r);
}

int		winner_score(t_game *g, t_fd *cl)
{
  size_t	i;
  int		score;
  int		fd;

  score = 0;
  fd = -1;
  for (i = 0; i < g->nplayer; i++)
    {
      if (g->player[i].score > score)
	{
	  score = g->player[i].score;
	  fd = list_get(cl, i)->fd;
	}
      else if (g->player[i].score == score)
	fd = -1;
    }
  return (fd);
}

int	fn_entrop(t_game *g, t_fd *cl, int r[], char (*s)[])
{
  int final;

  final = 0;
  sprintf(*s + strlen(*s), "%sPLAYER %d %lf %lf %d", (**s ? "\n" : ""),
	  list_get(cl, r[2])->fd, g->player[r[2]].x, g->player[r[2]].y,
	  g->player[r[2]].score);
  if (r[0] == 2)
    map_coin(g, cl, r[2], s);
  else if ((r[0] / 10) == 1)
    final = winner_score(g, cl);
  return (final);
}

int		player_move(t_game *g, t_fd *cl)
{
  size_t	i;
  double	step;
  char		s[BUFFER_SIZE];
  int		final;
  int		r[2];
  int		fire;

  final = 0;
  memset(s, 0, BUFFER_SIZE);
  if ((step = update_time(g)) == 0.0f)
    return (SUCCESS);
  for (i = 0; i < g->nplayer; i++)
    {
      r[2] = i;
      fire = (HAS_FIRE(list_get(cl, i)->status) ? 1 : -1);
      if ((r[0] = player_position(&g->player[i], g, step, fire)) == FAIL)
	final = (!final ? list_get(cl, i)->fd : -1);
      final = ((r[1] = fn_entrop(g, cl, r, &s)) ? r[1] : final);
    }
  if (final)
    sprintf(s + strlen(s), "%sFINISH %d", (*s ? "\n" : ""), final);
  client_notify(cl, s);
  return (SUCCESS);
}

int		update_player(t_server *s)
{
  if (!s->game.start)
    return (SUCCESS);
  if (!s->game.player)
    return (player_init(&s->game, s->client->next));
  if (list_size(s->client->next) < MAX_CLIENT)
    return (player_clear(&s->game));
  player_move(&s->game, s->client->next);
  return (SUCCESS);
}
