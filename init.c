/*
** init.c for wolf3d in /home/djerad_k/Desktop/Igraph/Wolf3d/MUL_2014_wolf3d
** 
** Made by kevin Djeradi
** Login   <djerad_k@epitech.net>
** 
** Started on  Tue Dec 23 13:17:56 2014 kevin Djeradi
** Last update Mon May 11 18:39:02 2015 kevin djeradi
*/

#include "wolf.h"

void	my_tab_0(t_init *start)
{
  int	a;

  a = 0;
  while (a < start->param.sizeline * SIZE_Y)
    {
      start->data[a] = 0;
      a++;
    }
}

int	gere_expose(t_init *start)
{
  mlx_put_image_to_window(start->mlx, start->win, start->img, 0, 0);
  return (0);
}

void	init_pos(t_all *start)
{
  start->pos.a = 0;
  start->pos.x0 = 1.5;
  start->pos.y0 = 8.5;
  start->pos.xi = start->pos.x0;
  start->pos.yi = start->pos.y0;
  main_aff(start);
}

int	main(int argc, char **argv)
{
  t_all	start;

  if (argc > 1)
    {
      my_putstr("You aren't allowed to use arguments with this project\n");
      return (1);
    }
  if ((start.init.mlx = mlx_init()) == NULL)
    return (1);
  start.init.win = mlx_new_window(start.init.mlx, SIZE_X, SIZE_Y, "Wolf3d");
  start.init.img = mlx_new_image(start.init.mlx, SIZE_X, SIZE_Y);
  start.init.data = mlx_get_data_addr(start.init.img, &start.init.param.bpp,
				      &start.init.param.sizeline, &start.init.param.endian);
  my_tab_0(&start.init);
  init_pos(&start);
  mlx_expose_hook(start.init.win, gere_expose, &start);
  mlx_hook(start.init.win, KeyPress, KeyPressMask, gere_key, &start);
  mlx_loop(start.init.mlx);
  return (0);
}
