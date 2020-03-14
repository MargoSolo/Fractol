/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlongfel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:20:38 by xlongfel          #+#    #+#             */
/*   Updated: 2020/03/02 16:20:40 by xlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

short	switch_bool(short v)
{
	if (v == 1)
		v = 0;
	else if (v == 0)
		v = 1;
	else
		v = 0;
	return (v);
}

int	control_keyboard(int key, void *map)
{
	t_map *m;

	m = (t_map *)map;
	if (key >= 18 && key <= 20)
		change_mode(m, key);
	if (key == 69 || key == 78)
		modify_details(m, key);
	else if (key == 53)
		exit(1);
	else if (key == 37)
		m->lock = switch_bool(m->lock);
	else if (key >= 83 && key <= 91)
	{
		get_color_code(m, key);
		update_image(m);
	}
	else if (key == 92)
	{
		get_color_code(m, key);
		m->rdm = set_color(m->rdm, rand(), rand(), rand());
		update_image(m);
	}
	else if (key >= 123 && key <= 126)
		move_fractal(m, key);
	return (1);
}

int	mouse_move(int x, int y, void *map)
{
	t_map *m;

	m = (t_map *)map;
	if (m->mode == julia && !m->lock)
		move_julia(m, x, y);
	return (1);
}

int	control_mouse(int button, int x, int y, void *map)
{
	t_map	*m;
	double	mouse_re;
	double	mouse_im;

	m = (t_map *)map;
	if (button == 4 || button == 5)
	{
		mouse_re = (double)x / (WIN_X / (m->x2 - m->x1)) + m->x1;
		mouse_im = (double)y / (WIN_Y / (m->y2 - m->y1)) + m->y1;
		apply_zoom(m, mouse_re, mouse_im, button == 4 ? 1.2 : 0.8);
	}
	if (button == 1 && !m->menu_on)
		display_menu(map);
	else if (button == 2 && m->menu_on)
		hide_menu(map);
	return (1);
}