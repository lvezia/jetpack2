/*
** main.c for jetpack2Tek3 in /home/david/dev/syn_pool/jetpack2Tek3/server/src/
**
** Made by David Calo
** Login   <calo_d@epitech.eu>
**
** Started on  Thu Jul  7 10:26:40 2016 David Calo
** Last update Tue Jul 12 20:55:08 2016 David Calo
*/

// #include <stdio.h>

#include "server.h"
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

static t_server	s;

static void	signal_handler(int sig)
{
  dprintf(2, "[server] Received signal %d\n", sig);
  if (sig == 2)
    exit(EXIT_SUCCESS);
}

static void		server_free()
{
  size_t	i;

  for (i = 1; i < list_size(s.client); list_remove(s.client, i))
    close(list_get(s.client, i)->fd);
  if (s.client && s.client->fd)
    close(s.client->fd);
  free(s.client);
  free(s.game.map);
}

static int			signal_init()
{
  struct sigaction	sig;

  memset(&sig, 0, sizeof(struct sigaction));
  sig.sa_handler = &signal_handler;
  if (sigaction(SIGINT, &sig, NULL) || sigaction(SIGPIPE, &sig, NULL))
    return (xperror("sigaction"));
  if (atexit(server_free))
    return (xputerror("atexit: failed"));
  return (SUCCESS);
}

int		main(int ac, char const *av[])
{
  size_t	i;
  size_t	j;

  if (signal_init() ||
      arg_read(ac, av, &s) ||
      server_init(&s))
    return (84);
  process_game(&s.game);
  while (1)
    {
      if (!server_select(&s))
	for (i = 0; i < list_size(s.client); i++)
	  for (j = 0; j < 2; j++)
	    if (FD_ISSET(list_get(s.client, i)->fd, &s.fds[j]) &&
		list_get(s.client, i)->fn[j](&s, i))
	      client_close(s.client, i--);
      update_game(&s);
    }
  return (0);
}
