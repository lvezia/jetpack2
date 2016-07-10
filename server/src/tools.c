/*
** tools.c for jetpack2Tek3 in /home/david/dev/syn_pool/jetpack2Tek3/server/src/
**
** Made by David Calo
** Login   <calo_d@epitech.eu>
**
** Started on  Thu Jul  7 19:01:33 2016 David Calo
** Last update Sun Jul 10 18:23:36 2016 David Calo
*/

#include "server.h"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>


int	xputerror(char const *msg)
{
  write(2, msg, strlen(msg));
  write(2, "\n", 1);
  return (FAIL);
}

int	xperror(char const *msg)
{
  perror(msg);
  errno = 0;
  return (FAIL);
}

void	printlog(int fd, char const *msg)
{
  if (PRINT_LOG)
    dprintf(fd, "%s: %s\n", (fd == 2 ? "Err" : (fd == 3 ? "Debug" : "Log")),
	    msg);
}

char	*read_file(char const *name)
{
  FILE	*file;
  char	*buf;
  long	len;

  buf = NULL;
  if (!name || (file = fopen(name, "r")) == NULL)
    return (NULL);
  if (fseek(file, 0, SEEK_END) ||
      (len = ftell(file)) == -1 ||
      fseek(file, 0, SEEK_SET) ||
      (buf = malloc(len)) == NULL ||
      !fread(buf, 1, len, file))
    {
      free(buf);
      if (fclose(file))
	return (NULL);
      return (NULL);
    }
  if (fclose(file))
    {
      free(buf);
      return (NULL);
    }
  return (buf);
}
