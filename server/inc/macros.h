/*
** macros.h for jetpack2Tek3 in /home/david/dev/syn_pool/jetpack2Tek3/server/inc/
**
** Made by David Calo
** Login   <calo_d@epitech.eu>
**
** Started on  Fri Jul  8 21:15:55 2016 David Calo
** Last update Fri Jul  8 21:17:52 2016 David Calo
*/

#ifndef MACROS_H_
# define MACROS_H_

# define TABLEN(x) (sizeof(x) / sizeof(*x))
# define SERVER_MSG "HELLO FORM SERVER"
# define LISTEN_MAX_CLIENT 8
# define PRINT_LOG 1
# define DEFAULT_PORT 4242
# define DEFAULT_GRAVITY -9.81

# ifndef NULL
#  define NULL ((void *)0)
# endif

# define SUCCESS 0
# define FAIL -1

#endif
