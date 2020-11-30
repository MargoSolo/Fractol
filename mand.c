/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mand.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlongfel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:19:45 by xlongfel          #+#    #+#             */
/*   Updated: 2020/03/02 16:19:47 by xlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	iterate_mandelbrot(t_mlx *m)
{
	int		iter;
	double	ci;
	double	cr;
	double	temp;

	iter = 1;
	ci = 0;
	cr = 0;
	m->pixel_coor.x = calc_draw_x(m);
	m->pixel_coor.y = calc_draw_y(m);
	while (iter < m->max_iter && ci * ci + cr * cr <= 4.0)
	{
		temp = ci * ci - cr * cr + m->pixel_coor.x;
		cr = 2 * ci * cr + m->pixel_coor.y;
		ci = temp;
		iter++;
	}
	return (iter);
}

int	iterate_julia(t_mlx *m)
{
	int		iter;
	double	ci;
	double	cr;
	double	temp;

	iter = 1;
	ci = calc_draw_x(m);
	cr = calc_draw_y(m);
	while (iter < m->max_iter && ci * ci + cr * cr <= 4.0)
	{
		temp = ci * ci - cr * cr + m->julia.y;
		cr = 2 * ci * cr + m->julia.x;
		ci = temp;
		iter++;
	}
	return (iter);
}

int	iterate_ship(t_mlx *m)
{
	int		iter;
	double	ci;
	double	cr;
	double	temp;

	iter = 1;
	ci = 0;
	cr = 0;
	m->pixel_coor.x = calc_draw_x(m);
	m->pixel_coor.y = calc_draw_y(m);
	while (iter < m->max_iter && ci * ci + cr * cr <= 4.0)
	{
		ci = fabs(ci);
		cr = fabs(cr);
		temp = ci * ci - cr * cr + m->pixel_coor.x;
		cr = 2 * ci * cr + m->pixel_coor.y;
		ci = temp;
		iter++;
	}
	return (iter);
}

int	iterate_tricorn(t_mlx *m)
{
	int		iter;
	double	ci;
	double	cr;
	double	temp;

	iter = 1;
	ci = 0;
	cr = 0;
	m->pixel_coor.x = calc_draw_x(m);
	m->pixel_coor.y = calc_draw_y(m);
	while (iter++ < m->max_iter && ci * ci + cr * cr <= 4.0)
	{
		temp = ci * ci - cr * cr + m->pixel_coor.x;
		cr = -2 * ci * cr + m->pixel_coor.y;
		ci = temp;
		iter++;
	}
	return (iter);
}

int	display_fractal(t_mlx *m)
{
	if (m->mode_num == 0)
		return (iterate_mandelbrot(m));
	else if (m->mode_num == 1)
		return (iterate_julia(m));
	else if (m->mode_num == 2)
		return (iterate_ship(m));
	else if (m->mode_num == 3)
		return (iterate_tricorn(m));
	else
		return (0);
}
