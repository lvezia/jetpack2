/*
** player.h for player in /home/vezia_l/rendu/jetpack2Tek3/client/inc/
**
** Made by Louis Vezia
** Login   <vezia_l@epitech.eu>
**
** Started on  Thu Jul  7 18:43:39 2016 Louis Vezia
** Last update	Fri Jul 08 17:24:20 2016 Louis Vezia
*/

#ifndef PLAYER_H_
# define PLAYER_H_

# include <pthread.h>

typedef struct s_client t_client;

typedef struct	s_player
{
  int		x;
  int		y;
  int		id;
  int		end;
  char		*msg;
}		t_player;

void	*play(t_client *client);
void	communication(t_client *);
void	set_value(t_client *, fd_set *, fd_set *, struct timeval *);
void	communication(t_client *);
void	stock_msg(t_client *);
void	ask_id(t_client *);
void	ask_map(t_client *);
void	call_ready(t_client *);

#endif /* !PLAYER_H_ */
