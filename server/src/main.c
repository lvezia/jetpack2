/*
** main.c for jetpack2Tek3 in /home/david/dev/syn_pool/jetpack2Tek3/server/src/
**
** Made by David Calo
** Login   <calo_d@epitech.eu>
**
** Started on  Thu Jul  7 10:26:40 2016 David Calo
** Last update Fri Jul  8 10:09:29 2016 David Calo
*/

// #include <stdio.h>

#include "server.h"

int	main(int ac, char const *av[])
{
  // t_bool	run;
  t_server	server;

  arg_read(ac, av, &server);
  process_map(&server);
  set_socket(&server);
  bind_listen_socket(&server);
  // run = TRUE;
  // while (run)
  //   {
      // set_fds();
      // select();
      // socket_server();
      // while (clients)
      // {
      //   socket_client();
      // }
      // run = update_game();
    // }
  // free_all();
  return 0;
}
