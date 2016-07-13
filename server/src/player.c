/*
** player.c for jetpack2Tek3 in /home/david/dev/syn_pool/jetpack2Tek3/server/src/
**
** Made by David Calo
** Login   <calo_d@epitech.eu>
**
** Started on  Mon Jul 11 16:57:06 2016 David Calo
** Last update Wed Jul 13 09:44:38 2016 David Calo
*/

#include "server.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int	player_info(t_server const *s, int n, int *status)
{
  t_fd	*cl;

  if ((cl = list_get(s->client, n + 1)) == NULL ||
      !(*cl->rbuf))
    return (FAIL);
  printf("player_info: %d\n", *status);
  memset(cl->rbuf, 0, strlen(cl->rbuf));
  return (SUCCESS);
}

int			player_move(t_game *g, t_fd *cl)
{
  size_t		i;
  static struct timeval	stime = (struct timeval){0, 0};
  struct timeval	ntime;
  double		step;

  if (TV_TO_SEC(stime) == 0)
    gettimeofday(&stime, NULL);
  gettimeofday(&ntime, NULL);
  ntime.tv_sec -= stime.tv_sec;
  ntime.tv_usec -= stime.tv_usec;
  step = TV_TO_SEC(ntime);
  if (REFRESH_TIME > step)
    return (SUCCESS);
  gettimeofday(&stime, NULL);
  // for (i = 0; i < g->nplayer; i++)
  //   {
  //     int pos = (int)g->player[i].x
  //     g->map[]
  //     g->player[i].x;
  //     g->player[i].y;
  //
  //   }
  printf("STEP: %lf\n", step);
  for (i = 0; i < g->nplayer; i++)
    {
      printf("PLAYER %d, step: %lf, v: %lf, g: %lf\n", list_get(cl, i)->fd,
	     step, g->player[i].vel, g->gravity);
      g->player[i].fire = (HAS_FIRE(list_get(cl, i)->status) ? 1 : -1);
      g->player[i].x += MOV_SPEED * step;
      g->player[i].vel += step * (g->gravity * g->gravity) * g->player[i].fire;
      g->player[i].y += 0;
      // *step * g->player[i].vel
      sprintf(list_get(cl, i)->wbuf, "PLAYER %d %lf %lf %d",
	      list_get(cl, i)->fd, g->player[i].x, g->player[i].y,
	      g->player[i].score);
    }
  return (SUCCESS);
}

int		update_player(t_server *s)
{
  if (!s->game.start)
    return (SUCCESS);
  if (!s->game.player)
    return (player_init(&s->game, s->client->next));
  player_move(&s->game, s->client->next);
  return (SUCCESS);
}
