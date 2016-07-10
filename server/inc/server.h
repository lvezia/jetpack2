/*
** server.h for jetpack2Tek3 in /home/david/dev/syn_pool/jetpack2Tek3/server/inc/
**
** Made by David Calo
** Login   <calo_d@epitech.eu>
**
** Started on  Thu Jul  7 11:06:54 2016 David Calo
** Last update Sun Jul 10 18:51:35 2016 David Calo
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
  t_buffer	buf;
  char		rbuf[BUFFER_SIZE];
  char		wbuf[BUFFER_SIZE];
  t_fd_fn	fn[2];
  t_fd		*next;
};

struct	s_server
{
  PORT		port;
  double	gravity;
  char		*map;
  int		fd;
  int		max_fd;
  fd_set	fds[2];
  t_fd		*client;
};

# include "prototype.h"

#endif
