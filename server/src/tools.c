/*
** tools.c for jetpack2Tek3 in /home/david/dev/syn_pool/jetpack2Tek3/server/src/
**
** Made by David Calo
** Login   <calo_d@epitech.eu>
**
** Started on  Thu Jul  7 19:01:33 2016 David Calo
** Last update Fri Jul  8 10:06:43 2016 David Calo
*/

#include "server.h"

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int	xputerror(char const *msg)
{
  write(2, msg, strlen(msg));
  write(2, "\n", 1);
  return (FAIL);
}

int	xperror(char const *msg)
{
  perror(msg);
  return (FAIL);
}
