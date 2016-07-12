/*
** tools_string.c for jetpack2Tek3 in /home/david/dev/syn_pool/jetpack2Tek3/server/src/
**
** Made by David Calo
** Login   <calo_d@epitech.eu>
**
** Started on  Mon Jul 11 17:24:15 2016 David Calo
** Last update Mon Jul 11 17:49:14 2016 David Calo
*/

int	xstrlenchr(char const *s, char c)
{
  return ((*s && *s != c) ? xstrlenchr(++s, c) + 1 : 0);
}

void	epur_str(char *s, char c)
{
  char	*pr;
  char	*pw;

  pr = s;
  pw = s;
  while (*pr)
    {
      *pw = *pr++;
      pw += (*pw != c);
    }
  *pw = '\0';
}
