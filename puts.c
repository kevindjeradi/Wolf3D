/*
** puts.c for wolf in /home/djerad_k/Desktop/Igraph/Wolf3d/MUL_2014_wolf3d
** 
** Made by kevin Djeradi
** Login   <djerad_k@epitech.net>
** 
** Started on  Tue Dec 23 13:20:12 2014 kevin Djeradi
** Last update Tue Dec 23 13:20:26 2014 kevin Djeradi
*/

void    my_putchar(char c)
{
  write(1, &c, 1);
}

void    my_putstr(char *str)
{
  int   a;

  a = 0;
  while (str[a] != '\0')
    {
      my_putchar(str[a]);
      a = a + 1;
    }
}

int     my_putnbr(int nb)
{
  int   a;
  int   b;

  a = 1;
  b = nb;
  if (nb == 0)
    {
      my_putchar('0');
      return (0);
    }
  if (nb < 0)
    {
      my_putchar('-');
      b = b * -1;
    }
  while (b / a != 0)
    a = a * 10;
  a = a / 10;
  while (a != 0)
    {
      my_putchar((b / a) % 10 + '0');
      a = a / 10;
    }
  return (nb);
}
