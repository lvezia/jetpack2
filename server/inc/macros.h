/*
** macros.h for jetpack2Tek3 in /home/david/dev/syn_pool/jetpack2Tek3/server/inc/
**
** Made by David Calo
** Login   <calo_d@epitech.eu>
**
** Started on  Fri Jul  8 21:15:55 2016 David Calo
** Last update Mon Jul 11 20:30:57 2016 David Calo
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

# define ST_ID 0x1
# define ST_MAP 0x2
# define ST_READY 0x4
# define ST_ALL (ST_ID | ST_MAP | ST_READY)
# define HAS_ID(x) (((x) & ST_ID) == ST_ID)
# define HAS_MAP(x) (((x) & ST_MAP) == ST_MAP)
# define HAS_READY(x) (((x) & ST_READY) == ST_READY)
# define IS_READY(x) (((x) & ST_ALL) == ST_ALL)
# define SET_ID(x) ((x) |= ST_ID)
# define SET_MAP(x) ((x) |= ST_MAP)
# define SET_READY(x) ((x) |= ST_READY)

#endif
