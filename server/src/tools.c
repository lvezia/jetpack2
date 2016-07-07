/*
** tools.c for jetpack2Tek3 in /home/david/dev/syn_pool/jetpack2Tek3/server/src/
**
** Made by David Calo
** Login   <calo_d@epitech.eu>
**
** Started on  Thu Jul  7 19:01:33 2016 David Calo
** Last update Thu Jul  7 19:11:52 2016 David Calo
*/

#include <unistd.h>
#include <string.h>

int	xputerror(char const *msg)
{
  write(2, msg, strlen(msg));
  write(2, "\n", 1);
  return (1);
}
