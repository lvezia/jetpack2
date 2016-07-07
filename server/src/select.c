/*
** select.c for jetpack2Tek3 in /home/david/dev/syn_pool/jetpack2Tek3/server/src/
**
** Made by David Calo
** Login   <calo_d@epitech.eu>
**
** Started on  Thu Jul  7 18:29:27 2016 David Calo
** Last update Thu Jul  7 18:30:08 2016 David Calo
*/

void select(void)
{
  int		max_fd;
  fd_set	fd_read;
  fd_set	fd_write;
  int		client_fd;
  int		server_fd;
  struct sockaddr	addr;
  socklen_t		size;
  struct timeval	tv;

  tv.tv_sec = 0;
  tv.tv_usec = 100;
  size = sizeof(struct sockaddr);
  FD_ZERO(&fd_read);
  FD_ZERO(&fd_write);
  FD_SET(server_fd, &fd_read);
  FD_SET(server_fd, &fd_write);
  while (1)
    {
      if (select(max_fd + 1, &fd_read, &fd_write, NULL, &tv))
	perror(select);
      else if (FD_ISSET(server_fd, &fd_read))
	{
	  if ((client_fd = accept(server_fd, &addr, &size)) == -1)
	    perror("accept");
	  else
	    {
	      printf("[%d] connected\n", client_fd);
	    }
	}
    }
  printf("%s\n", SERVER_MSG);
}
