/*
** move.c for wolf3d in /home/djerad_k/Desktop/Igraph/Wolf3d/MUL_2014_wolf3d
** 
** Made by kevin Djeradi
** Login   <djerad_k@epitech.net>
** 
** Started on  Tue Dec 23 14:03:08 2014 kevin Djeradi
** Last update Fri May 29 15:00:19 2015 kevin djeradi
*/

#include "wolf.h"

int	mappy[YMAP][XMAP] = {
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 1, 1, 1, 1, 0, 0, 1},
  {1, 0, 0, 0, 1, 0, 0, 0, 1, 1},
  {1, 0, 1, 0, 1, 0, 0, 0, 0, 1},
  {1, 0, 1, 0, 0, 0, 1, 1, 0, 1},
  {1, 0, 1, 0, 0, 0, 1, 1, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 1, 1},
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

void	move_up(t_all *start)
{
  float	stock_x;
  float	stock_y;

  stock_x = start->pos.x0;
  stock_y = start->pos.y0;
  start->pos.x0 += cosf(start->pos.a) * 0.15;
  start->pos.y0 += sinf(start->pos.a) * 0.15;
  if (get_map(I start->pos.x0, I start->pos.y0) == 1)
    {
      start->pos.x0 = stock_x;
      start->pos.y0 = stock_y;
    }
}

void	move_down(t_all *start)
{
  float	stock_x;
  float	stock_y;

  stock_x = start->pos.x0;
  stock_y = start->pos.y0;
  start->pos.x0 -= cosf(start->pos.a) * 0.15;
  start->pos.y0 -= sinf(start->pos.a) * 0.15;
  if (get_map(I start->pos.x0, I start->pos.y0) == 1)
    {
      start->pos.x0 = stock_x;
      start->pos.y0 = stock_y;
    }
}

int	get_map(int x, int y)
{
  return (mappy[y][x]);
}

int	gere_key(int keycode, t_all *start)
{
  if (keycode == 65307)
    exit(my_putstr("Exit with success\n"));
  else if (keycode == 65362 || keycode == 122)
    move_up(start);
  else if (keycode == 65364 || keycode == 115)
    move_down(start);
  else if (keycode == 65363 || keycode == 100)
    start->pos.a += 0.1;
  else if (keycode == 65361 || keycode == 113)
    start->pos.a -= 0.1;
  main_aff(start);
  return (0);
}
