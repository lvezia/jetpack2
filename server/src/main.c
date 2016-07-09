/*
** main.c for jetpack2Tek3 in /home/david/dev/syn_pool/jetpack2Tek3/server/src/
**
** Made by David Calo
** Login   <calo_d@epitech.eu>
**
** Started on  Thu Jul  7 10:26:40 2016 David Calo
** Last update Fri Jul  8 21:14:45 2016 David Calo
*/

// #include <stdio.h>

#include "server.h"
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

static t_server	s;

static void	signal_handler(int sig)
{
  dprintf(2, "[server] Received signal %d\n", sig);
  if (sig == 2)
    exit(EXIT_SUCCESS);
}

void	server_free()
{
  size_t	i;

  for (i = 1; i < list_size(s.client); list_remove(s.client, i))
    close(list_get(s.client, i)->fd);
  close(s.client->fd);
  free(s.client);
  free(s.map);
}

int	main(int ac, char const *av[])
{
  struct sigaction	sig;
  size_t	i;
  size_t	j;

  sig.sa_handler = &signal_handler;
  if (sigaction(SIGINT, &sig, NULL) || sigaction(SIGPIPE, &sig, NULL))
    return (xperror("sigaction"));
  if (atexit(server_free))
    return (xputerror("atexit: failed"));
  arg_read(ac, av, &s);
  // process_map(&s);
  if (server_init(&s))
    return (84);
  while (1)
    {
      server_select(&s);
      for (i = 0; i < list_size(s.client); i++)
	for (j = 0; j < 2; j++)
	  if (FD_ISSET(list_get(s.client, i)->fd, &s.fds[j]) &&
	      list_get(s.client, i)->fn[j](&s))
	    client_close(s.client, i--);
    // update_game();
    }
  return (0);
}
