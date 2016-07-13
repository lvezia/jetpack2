/*
** player.c for jetpack2Tek3 in /home/david/dev/syn_pool/jetpack2Tek3/server/src/
**
** Made by David Calo
** Login   <calo_d@epitech.eu>
**
** Started on  Mon Jul 11 16:57:06 2016 David Calo
** Last update Wed Jul 13 22:31:06 2016 David Calo
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

static double	update_time(t_game *g)
{
  struct timeval	ntime;
  double		step;

  if (TV_TO_SEC(g->stime) == 0)
    gettimeofday(&g->stime, NULL);
  gettimeofday(&ntime, NULL);
  ntime.tv_sec -= g->stime.tv_sec;
  ntime.tv_usec -= g->stime.tv_usec;
  step = TV_TO_SEC(ntime);
  if ((double)REFRESH_TIME > step)
    return (0.0f);
  gettimeofday(&g->stime, NULL);
  return (step);
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

int		player_move(t_game *g, t_fd *cl)
{
  size_t	i;
  double	step;
  char		s[BUFFER_SIZE];
  int		final;
  int		r;
  int		fire;

  final = 0;
  memset(s, 0, BUFFER_SIZE);
  if ((step = update_time(g)) == 0.0f)
    return (SUCCESS);
  for (i = 0; i < g->nplayer; i++)
    {
      fire = (HAS_FIRE(list_get(cl, i)->status) ? 1 : -1);
      if ((r = player_position(&g->player[i], g, step, fire)) == FAIL)
	final = (!final ? list_get(cl, i)->fd : -1);
      sprintf(s + strlen(s), "%sPLAYER %d %lf %lf %d", (*s ? "\n" : ""),
	      list_get(cl, i)->fd, g->player[i].x, g->player[i].y,
	      g->player[i].score);
      if (r == 2)
	map_coin(g, cl, i, &s);
      else if ((r / 10) == 1)
	final = winner_score(g, cl);
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
