/*
** server.h for jetpack2Tek3 in /home/david/dev/syn_pool/jetpack2Tek3/server/inc/
**
** Made by David Calo
** Login   <calo_d@epitech.eu>
**
** Started on  Thu Jul  7 11:06:54 2016 David Calo
** Last update Wed Jul 13 09:42:50 2016 David Calo
*/

#ifndef SERVER_H_
# define SERVER_H_

# include <sys/select.h>
# include <stddef.h>

# include "types.h"
# include "macros.h"

struct	s_buffer
{
  char		buffer[BUFFER_SIZE];
  size_t	head;
  size_t	tail;
  size_t	writen;
};

struct	s_fd
{
  int		fd;
  char		status;
  char		rbuf[BUFFER_SIZE];
  char		wbuf[BUFFER_SIZE];
  t_rw_fn	fn[2];
  t_fd		*next;
};

struct	s_player
{
  double	x;
  double	y;
  double	vel;
  int		score;
  char		fire;
};

struct	s_game
{
  int		mx;
  int		my;
  char		*map;
  double	gravity;
  char		start;
  size_t	nplayer;
  t_player	*player;
  struct timeval	stime;
};

struct	s_server
{
  PORT		port;
  t_game	game;
  int		fd;
  int		max_fd;
  fd_set	fds[2];
  t_fd		*client;
};

# include "prototype.h"

#endif
