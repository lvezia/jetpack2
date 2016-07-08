/*
** server.h for jetpack2Tek3 in /home/david/dev/syn_pool/jetpack2Tek3/server/inc/
**
** Made by David Calo
** Login   <calo_d@epitech.eu>
**
** Started on  Thu Jul  7 11:06:54 2016 David Calo
** Last update Fri Jul  8 21:18:33 2016 David Calo
*/

#ifndef SERVER_H_
# define SERVER_H_

# include <sys/select.h>
# include <stddef.h>

# include "types.h"
# include "macros.h"

struct	s_fd
{
  int		fd;
  t_fd_fn	fn[2];
  struct s_fd	*next;
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
