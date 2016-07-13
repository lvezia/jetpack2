/*
** time.c for jetpack2Tek3 in /home/david/dev/syn_pool/jetpack2Tek3/server/src/
**
** Made by David Calo
** Login   <calo_d@epitech.eu>
**
** Started on  Wed Jul 13 23:44:22 2016 David Calo
** Last update Wed Jul 13 23:45:37 2016 David Calo
*/

#include "server.h"

#include <sys/time.h>

double			update_time(t_game *g)
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
