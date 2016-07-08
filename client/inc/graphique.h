/*
** graphique.h for graphique in /home/vezia_l/rendu/jetpack2Tek3/client/inc/
**
** Made by Louis Vezia
** Login   <vezia_l@epitech.eu>
**
** Started on  Thu Jul  7 18:47:09 2016 Louis Vezia
** Last update	Fri Jul 08 16:25:31 2016 Louis Vezia
*/

#ifndef GRAPHIQUE_H_
# define GRAPHIQUE_H_

# include <pthread.h>

typedef struct	s_map
{
  pthread_mutex_t       mutex;
  int		sizeX;
  int		sizeY;
  char		*map;
}		t_map;

void *graphique(void *arg);

#endif /* !GRAPHIQUE_H_ */
