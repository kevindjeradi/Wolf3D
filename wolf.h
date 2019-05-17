/*
** list.h for wolf3d in /home/djerad_k/Desktop/Igraph/Wolf3d/MUL_2014_wolf3d
** 
** Made by kevin Djeradi
** Login   <djerad_k@epitech.net>
** 
** Started on  Tue Dec 23 12:47:31 2014 kevin Djeradi
** Last update Sun Jan  4 16:54:46 2015 kevin Djeradi
*/

#ifndef WOLF_H_
# define WOLF_H_
# define BUFF_SIZE 4096
# define OPP (start->init.param.bpp / 8)
# define SIZE_X 1900
# define SIZE_Y 1000
# define ANG (start->pos.a)
# define F (float)
# define I (int)
# define SIZELINE (start->init.param.sizeline)
# define YMAP 10
# define XMAP 10

# include <stdlib.h>
# include <mlx.h>
# include <X11/X.h>
# include <math.h>

typedef struct	s_point
{
  int		x;
  int		y;
  int		color;
}		t_point;

typedef struct	s_param
{
  int		bpp;
  int		sizeline;
  int		endian;
}		t_param;

typedef struct	s_init
{
  void		*mlx;
  void		*win;
  void		*img;
  char		*data;
  t_param	param;
}		t_init;

typedef struct	s_pos
{
  float		x0;
  float		xi;
  float		y0;
  float		yi;
  float		a;
}		t_pos;

typedef struct	s_all
{
  t_init	init;
  t_pos		pos;
}		t_all;

typedef struct	s_wall
{
  float		distance;
  unsigned int	color;
}		t_wall;

int	gere_key(int keycode, t_all *start);
int	get_map(int x, int y);

#endif /* !WOLF_H_ */
