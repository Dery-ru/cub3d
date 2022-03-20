/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanel <achanel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:20:05 by achanel           #+#    #+#             */
/*   Updated: 2022/03/16 17:05:18 by achanel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <errno.h>
# include <stdlib.h>
# include <fcntl.h>
# include "mlx.h"
# include "../libft/libft.h"
# define WIDTH 800
# define HEIGHT 600
# define MINI_MAPW 160
# define MINI_MAPH 160
# define SQUARE_MAP_SIZE 20
# define BUFFER_SIZE 1000
# define ARROW_UP 126
# define ARROW_DOWN 125
# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define MV_SPEED 0.01
# define ROT_SPEED 0.03
# define W_KEY 13
# define S_KEY 1
# define A_KEY 0
# define D_KEY 2
# define KEY_ESC 53
# define HITBOX 0.3
# define SCALE 16 // условный размер каждого квадратика в карте

typedef struct s_win //структура для окна
{
	void		*mlx;
	void		*win;
}	t_win;

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			line_length;
	int			bits_per_pixel;
	int			endian;
	int			w;
	int			h;
}	t_img;

typedef struct s_point // структура для точки
{
	int			x;
	int			y;
}	t_point;

typedef struct s_plr //структура для игрока и луча
{
	float		x;
	float		y;
	float		dir_x;
	float		dir_y;
	float		plane_x;
	float		plane_y;
	float		start;
	float		end;
	int			up;
	int			down;
	int			left;
	int			right;
	float		angle;
}	t_plr;

typedef struct	s_ray
{
	float		posx;
	float		posy;

	float		dirx;
	float		diry;

	float		sidedx;
	float		sidedy;

	float		ddistx;
	float		ddisty;

	float		walldist;

	int			side;

	int			stepx;
	int			stepy;

	float		camerax;

	int			mapx;
	int			mapy;
	float		draw_start;
	float		draw_end;
	float		ray_r;
	float	plane_x;
	float	plane_y;
	int		hit;
	int		line_height;
	float	wall_x;
	int		tex;
	float	tex_stepy;
	float	tex_stepx;
	float	tex_pos;
	int		tex_x;
	int		tex_y;
	int		pix_x;
}				t_ray;

typedef struct	s_draw
{
	int			color;
	int			zi;
	int			zf;
	int			xi;
	int			yi;
	int			xf;
	int			yf;
	int			dx;
	int			dy;
	int			xinc;
	int			yinc;
	int			decalx;
	int			decaly;
	int			offsetx;
	int			offsety;
}				t_draw;

typedef struct s_all // структура для всего вместе
{
	t_win		win;
	t_plr		plr;
	t_img		txt[6];
	t_img		display;
	char		**map;
	int			colorsky;
	int			colorground;
	int			color_east;
	int			color_west;
	int			color_north;
	int			color_south;
}	t_all;
void	test_parser(char *av1, t_all *all);
//init
void	init_all(t_all *all);
//gnl
int		get_next_line(int fd, char **line);
//mlx_utils
unsigned int	get_texture_color(t_img txt, t_point point);
void	my_mlx_pixel_put(t_img img, t_point point, int color);
int		loop_hook(t_all *all);

//hooks
int		ft_exit(t_all *all);
int		keyboard_hook(int keycode, t_all *all);
//utils
void	ft_errors(char *error_str);
//raycasting
void    ft_raycasting(t_all *all);
//ray
void		draw_ray(t_all *all, double xf, double yf, int color);
//draw
void		draw_line(t_all *all, t_ray *ray, int x);
//moves
void	move_up(t_all *all);
void	move_down(t_all *all);
void	move_right(t_all *all);
void	move_left(t_all *all);

#endif