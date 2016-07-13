/*
** macros.h for jetpack2Tek3 in /home/david/dev/syn_pool/jetpack2Tek3/server/inc/
**
** Made by David Calo
** Login   <calo_d@epitech.eu>
**
** Started on  Fri Jul  8 21:15:55 2016 David Calo
** Last update Wed Jul 13 10:17:16 2016 David Calo
*/

#ifndef MACROS_H_
# define MACROS_H_

# define PRINT_LOG 1

# define DEFAULT_PORT 4242
# define DEFAULT_GRAVITY -9.81

# define MAX_CLIENT 2
# define LISTEN_MAX_CLIENT 8
# define REFRESH_TIME (20 * 1e-3)
# define BUFFER_SIZE 4096
# define MOV_SPEED (5)
# define PLAYER_WEIGHT 1

# define TV_TO_SEC(x) (((double)(x).tv_sec + ((double)(x).tv_usec * 1e-6)))

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

# define ST_START 0x8
# define HAS_START(x) (((x) & ST_START) == ST_START)
# define SET_START(x) ((x) |= ST_START)

# define ST_FIRE 0x16
# define HAS_FIRE(x) (((x) & ST_FIRE) == ST_FIRE)
# define SET_FIRE(x) ((x) |= ST_FIRE)
# define UNSET_FIRE(x) ((x) &= (~ST_FIRE))

#endif
