/*
** tools_check.c for jetpack2Tek3 in /home/david/dev/syn_pool/jetpack2Tek3/server/src/
**
** Made by David Calo
** Login   <calo_d@epitech.eu>
**
** Started on  Sun Jul 10 18:30:18 2016 David Calo
** Last update Sun Jul 10 18:53:17 2016 David Calo
*/

#include "macros.h"

#include <ctype.h>
#include <stddef.h>

int	check_int(char const *s)
{
  size_t	i;

  if (!s)
    return (FAIL);
  for (i = 0; s[i]; i++)
    if (!isdigit(s[i]))
      return (FAIL);
  return (SUCCESS);
}

int	check_float(char const *s)
{
  size_t	i;

  if (!s)
    return (FAIL);
  for (i = 0; s[i]; i++)
    if (!isdigit(s[i]) && s[i] != '.')
      return (FAIL);
  return (SUCCESS);
}
