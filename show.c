/*
** show.c for wolf3d in /home/djerad_k/Desktop/Igraph/Wolf3d/MUL_2014_wolf3d
** 
** Made by kevin Djeradi
** Login   <djerad_k@epitech.net>
** 
** Started on  Tue Dec 23 14:09:37 2014 kevin Djeradi
** Last update Fri May 29 15:05:42 2015 kevin djeradi
*/

#include "wolf.h"
#define img start->init.img

void	distance(t_all *start, float vx, float vy, t_wall *wall)
{
  float	k;
  float	xxi;
  float	yyi;

  k = 0;
  start->pos.xi = start->pos.x0;
  start->pos.yi = start->pos.y0;
  while (get_map(start->pos.xi, start->pos.yi) != 1)
    {
      xxi = start->pos.xi;
      yyi = start->pos.yi;
      start->pos.xi = start->pos.x0 + k * vx;
      start->pos.yi = start->pos.y0 + k * vy;
      k += 0.01;
    }
  if (I xxi > I start->pos.xi)
    wall->color = 0x505050;
  if (I xxi < I start->pos.xi)
    wall->color = 0x404040;
  if (I yyi > I start->pos.yi)
    wall->color = 0x606060;
  if (I yyi < I start->pos.yi)
    wall->color = 0x545454;
  wall->distance = k;
}

void		my_pixel_put_to_image(t_point *p1, t_all *start)
{
  int		a;
  int		opp;
  unsigned int	color;

  a = 0;
  opp = OPP;
  color = mlx_get_color_value(start->init.mlx, p1->color);
  while (a < opp)
    {
      start->init.data[(SIZELINE * p1->y)
		       + (opp * p1->x) + a] = (color >> (a * 8));
      a++;
    }
}

void		draw_line(t_all *start, t_point *p1, t_point *p2)
{
  while (p1->y != p2->y)
    {
      p1->y++;
      my_pixel_put_to_image(p1, start);
    }
}

void	draw_column(t_all *start, int x, t_wall *wall)
{
  t_point	p1;
  t_point	p2;
  int		cst;
  int		cst2;
  int		cst3;

  p1.x = x;
  p2.x = x;
  cst = (wall->distance != 0) ? SIZE_Y / (1.5 * wall->distance) : 0;
  cst2 = ((SIZE_Y / 2) - cst);
  cst3 = ((SIZE_Y / 2) + cst);
  p1.y = 0;
  p1.color = 0x77B5FE;
  p2.y = (cst < (SIZE_Y / 2)) ? cst2 : 0;
  draw_line(start, &p1, &p2);
  p1.color = wall->color;
  p2.y = (cst < (SIZE_Y / 2)) ? cst3 : SIZE_Y;
  draw_line(start, &p1, &p2);
  p1.color = 0x798933;
  p2.y = SIZE_Y;
  if (p1.y < SIZE_Y)
    draw_line(start, &p1, &p2);
}

void		main_aff(t_all *start)
{
  t_wall	wall;
  int		x;
  float		vx;
  float		vy;

  x = 0;
  while (x < SIZE_X)
    {
      vx = 0.5 * cosf(ANG) - (((F (SIZE_X / 2)) - F x) / F SIZE_X) * sinf(ANG);
      vy = 0.5 * sinf(ANG) + (((F (SIZE_X / 2)) - F x) / F SIZE_X) * cosf(ANG);
      distance(start, vx, vy, &wall);
      draw_column(start, SIZE_X - x, &wall);
      x++;
    }
  mlx_put_image_to_window(start->init.mlx, start->init.win, img, 0, 0);
}
