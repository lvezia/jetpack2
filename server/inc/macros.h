/*
** macros.h for jetpack2Tek3 in /home/david/dev/syn_pool/jetpack2Tek3/server/inc/
**
** Made by David Calo
** Login   <calo_d@epitech.eu>
**
** Started on  Fri Jul  8 21:15:55 2016 David Calo
** Last update Mon Jul 11 10:07:01 2016 David Calo
*/

#ifndef MACROS_H_
# define MACROS_H_

# define PRINT_LOG 1

# define DEFAULT_PORT 4242
# define DEFAULT_GRAVITY -9.81

# define ACCEPT_MAX_CLIENT 2

# define LISTEN_MAX_CLIENT 8
# define BUFFER_SIZE 4096

# define TABLEN(x) (sizeof(x) / sizeof(*x))

# ifndef NULL
#  define NULL ((void *)0)
# endif

# define SUCCESS 0
# define FAIL -1

#endif
