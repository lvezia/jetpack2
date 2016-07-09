/*
** types.h for jetpack2Tek3 in /home/david/dev/syn_pool/jetpack2Tek3/server/inc/
**
** Made by David Calo
** Login   <calo_d@epitech.eu>
**
** Started on  Fri Jul  8 21:15:55 2016 David Calo
** Last update Sat Jul  9 11:45:49 2016 David Calo
*/

#ifndef TYPES_H_
# define TYPES_H_

typedef unsigned short	PORT;
typedef struct s_fd	t_fd;
typedef struct s_buffer	t_buffer;
typedef struct s_server	t_server;
typedef int		(*t_fd_fn)(t_server *, size_t);
typedef int		(*t_arg_fn)(char const *, t_server *);

#endif
