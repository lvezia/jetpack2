/*
** server.h for jetpack2Tek3 in /home/david/dev/syn_pool/jetpack2Tek3/server/inc/
**
** Made by David Calo
** Login   <calo_d@epitech.eu>
**
** Started on  Thu Jul  7 11:06:54 2016 David Calo
** Last update Thu Jul  7 19:10:48 2016 David Calo
*/

#ifndef SERVER_H_
# define SERVER_H_

# define TABLEN(x) (sizeof(x) / sizeof(*x))
# define SERVER_MSG "HELLO FORM SERVER"

typedef enum	e_bool
{
  FALSE,
  TRUE
}		t_bool;

typedef unsigned short	PORT;

typedef struct	s_server
{
  PORT		port;
  double	gravity;
  char		*map;
}		t_server;

t_bool	arg_read(int, char const *[], t_server *);
t_bool	arg_port(char const *, t_server *);
t_bool	arg_gravity(char const *, t_server *);
t_bool	arg_map(char const *, t_server *);

int	xputerror(char const *);

#endif
