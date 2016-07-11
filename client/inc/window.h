/*
** window.h for window in /home/vezia_l/rendu/jetpack2Tek3/client/inc/
**
** Made by Louis Vezia
** Login   <vezia_l@epitech.eu>
**
** Started on  Mon Jul 11 10:18:25 2016 Louis Vezia
** Last update	Mon Jul 11 14:21:06 2016 Louis Vezia
*/

#ifndef WINDOW_H_
# define WINDOW_H_

# include <SDL/SDL.h>

typedef struct	s_window
{
  SDL_Surface	*ecran;
  SDL_Event	event;
}		t_window;

void	refresh_window(t_client *, t_window *);
void	create_rect(t_window *, SDL_Rect);
void	show_players();

#endif /* !WINDOW_H_ */
