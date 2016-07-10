/*
** client.h for client in /home/vezia_l/rendu/jetpack2Tek3/client/inc
**
** Made by louis vezia
** Login   <vezia_l@epitech.net>
**
** Started on  Thu Jul  7 11:16:32 2016 louis vezia
** Last update	Sun Jul 10 16:18:55 2016 Louis Vezia
*/

#ifndef CLIENT_H_
# define CLIENT_H_

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/time.h>
# include <sys/select.h>
# include <netdb.h>
# include <netinet/in.h>
# include <arpa/inet.h>

# include "player.h"
# include "graphique.h"

typedef struct	s_client
{
  int		port;
  int		fd;
  char		*ip;
  int		ready;
  int		start;
  pthread_mutex_t       status;
  t_player	player;
  t_map		map;
}		t_client;

void	init_data(t_client *);
int	run(t_client *);
int	my_put_error(char *);
int     init_socket(t_client *);
int	pars_arg(int, char **, t_client *);

#endif /* !CLIENT_H_ */
