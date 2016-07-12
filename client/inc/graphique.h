/*
** graphique.h for graphique in /home/vezia_l/rendu/jetpack2Tek3/client/inc/
**
** Made by Louis Vezia
** Login   <vezia_l@epitech.eu>
**
** Started on  Thu Jul  7 18:47:09 2016 Louis Vezia
** Last update	Tue Jul 12 09:45:42 2016 Louis Vezia
*/

#ifndef GRAPHIQUE_H_
# define GRAPHIQUE_H_

# include <pthread.h>
# include <SDL/SDL.h>

typedef struct s_window	t_window;

typedef struct		s_map
{
  int			sizeX;
  int			sizeY;
  int			windowX;
  int			windowY;
  char			*map;
  pthread_mutex_t       mutex;
}			t_map;

void	*graphique(void *arg);
void	set_window(t_client *);
int	play(t_client *, t_window *);
void	show_players(t_client *, t_window *);
void	fire_on(t_client *);
void	fire_off(t_client *);

#endif /* !GRAPHIQUE_H_ */
