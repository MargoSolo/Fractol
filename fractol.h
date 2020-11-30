/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlongfel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 15:41:30 by xlongfel          #+#    #+#             */
/*   Updated: 2020/03/02 15:41:31 by xlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIN_X 800
# define WIN_Y 800
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <mlx.h>
# include <pthread.h>

# define HEIGHT 777
# define WIDTH 888
# define ESCAPE 53
# define KEY_P 35
# define KEY_R 15
# define KEY_C 8
# define KEY_I 34
# define PLUS 27
# define MINUS 24
# define LEFT 123
# define RIGHT 124
# define DOWN 125
# define UP 126
# define ONE 18
# define TWO 19
# define THREE 20
# define FOUR 21

typedef struct	s_img
{
	void	*ptr;
	char	*str;
	int		bpp;
	int		size_line;
	int		endian;
}				t_img;

typedef struct	s_coor
{
	double min_x;
	double max_x;
	double min_y;
	double max_y;
	double scale_x;
	double scale_y;
}				t_coor;

typedef struct	s_point
{
	double x;
	double y;
}				t_point;

typedef struct	s_draw
{
	int x;
	int y;
	int i;
	int index;
}				t_draw;

typedef struct	s_julia
{
	double	x;
	double	y;
	char	pause;
}				t_julia;

typedef struct	s_color
{
	int			index;
	const int	*palette;
}				t_color;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	int			mode_num;
	int			max_iter;
	int			hide;

	t_img		img;
	t_coor		coor;
	t_point		mouse;
	t_point		pixel_coor;
	t_point		mid;
	t_point		new_mid;
	t_draw		draw;
	t_julia		julia;
	t_color		color;
}				t_mlx;

void			setup(t_mlx *m);
double			calc_x(t_mlx *m, int x);
double			calc_y(t_mlx *m, int y);
double			calc_draw_x(t_mlx *m);
double			calc_draw_y(t_mlx *m);

int				deal_key(int key, t_mlx *m);
int				deal_mouse(int button, int x, int y, t_mlx *m);
int				julia_mouse_tracker(int x, int y, t_mlx *m);

int				iterate_mandelbrot(t_mlx *m);
int				iterate_julia(t_mlx *m);
int				iterate_ship(t_mlx *m);
int				iterate_tricorn(t_mlx *m);
int				display_fractal(t_mlx *m);

void			switch_colorset(t_mlx *m);
void			ft_print_usage(void);
void			print_instructions(t_mlx *m);
void			draw(t_mlx *m);
int				close_win(void *param);

#endif
