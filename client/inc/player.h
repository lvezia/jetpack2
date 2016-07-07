/*
** player.h for player in /home/vezia_l/rendu/jetpack2Tek3/client/inc/
**
** Made by Louis Vezia
** Login   <vezia_l@epitech.eu>
**
** Started on  Thu Jul  7 18:43:39 2016 Louis Vezia
** Last update	Thu Jul 07 19:22:48 2016 Louis Vezia
*/

#ifndef PLAYER_H_
# define PLAYER_H_

# include <pthread.h>

typedef struct	s_player
{
  pthread_t             thread;
  pthread_mutex_t       mutex;
  int		x;
  int		y;
  int		end;
}		t_player;

void *play(void *arg);

#endif /* !PLAYER_H_ */
