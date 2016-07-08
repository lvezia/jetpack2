/*
** server.h for jetpack2Tek3 in /home/david/dev/syn_pool/jetpack2Tek3/server/inc/
**
** Made by David Calo
** Login   <calo_d@epitech.eu>
**
** Started on  Thu Jul  7 11:06:54 2016 David Calo
** Last update Fri Jul  8 10:14:01 2016 David Calo
*/

#ifndef SERVER_H_
# define SERVER_H_

# define TABLEN(x) (sizeof(x) / sizeof(*x))
# define SERVER_MSG "HELLO FORM SERVER"
# define LISTEN_MAX_CLIENT 8

# ifndef NULL
#  define NULL ((void *)0)
# endif

# define SUCCESS 0
# define FAIL -1

typedef enum	e_bool
{
  FALSE,
  TRUE
}		t_bool;

typedef unsigned short	PORT;

typedef struct s_server	t_server;
typedef struct s_fd	t_fd;
typedef int		(*t_fd_fn)(t_server *);

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
  t_client	cl;
};

typedef int	(*t_arg_fn)(char const *, t_server *);

int	arg_read(int, char const *[], t_server *);
int	arg_port(char const *, t_server *);
int	arg_gravity(char const *, t_server *);
int	arg_map(char const *, t_server *);

int	xputerror(char const *);
int	xperror(char const *);

int	set_socket(t_server *);
int	bind_listen_socket(t_server *);

void	process_map(t_server const *);

t_fd		*list_new(int, t_fd_fn, t_fd_fn);
int		list_add(t_fd *, t_fd *);
int		list_remove(t_fd *, size_t);
size_t		list_size(t_fd *);
t_fd const	*list_get(t_fd *, size_t);

#endif
