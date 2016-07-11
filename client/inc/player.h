/*
** player.h for player in /home/vezia_l/rendu/jetpack2Tek3/client/inc/
**
** Made by Louis Vezia
** Login   <vezia_l@epitech.eu>
**
** Started on  Thu Jul  7 18:43:39 2016 Louis Vezia
** Last update	Mon Jul 11 16:10:12 2016 Louis Vezia
*/

#ifndef PLAYER_H_
# define PLAYER_H_

# include <pthread.h>

typedef struct s_client t_client;

typedef struct	s_player
{
  int		x;
  int		y;
  int		x1;
  int		y1;
  int		id;
  int		score;
  int		score1;
  int		end;
  char		*msg;
  pthread_mutex_t       mutex;
}		t_player;

int	stock_msg(t_client *);
int	check_end(t_client *);
int	communication(t_client *);
void	handle_game(t_client *);
void	get_start(t_client *);
void	get_info_player(t_client *client);
void	get_info_coins(t_client *client);
void	refresh_player(t_client *, char **);
void	refresh_coins(t_client *, char **);
void	set_value(t_client *, fd_set *, fd_set *, struct timeval *);
void	set_client(t_client *);
void	ask_id(t_client *);
void	ask_map(t_client *);
void	call_ready(t_client *);

#endif /* !PLAYER_H_ */
