/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ohhh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlongfel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:22:29 by xlongfel          #+#    #+#             */
/*   Updated: 2020/03/02 16:22:31 by xlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_print_usage(void)
{
	ft_putstr("Usage: ./fractol [fractol number]\n\n");
	ft_putstr("1 - Mandelbrot Set\n");
	ft_putstr("2 - Julia Set\n");
	ft_putstr("3 - Burning Ship Set\n");
	ft_putstr("4 - Tricorn Set\n");
	exit(0);
}

void	print_instructions(t_mlx *m)
{
	mlx_string_put(m->mlx, m->win, 8, 0, 0xFFFFFF,
		"Hide Instructions > i");
	mlx_string_put(m->mlx, m->win, 8, 15, 0xFFFFFF, "Zoom > mouse wheel");
	mlx_string_put(m->mlx, m->win, 8, 30, 0xFFFFFF,
		"Move > mouse click");
	mlx_string_put(m->mlx, m->win, 8, 45, 0xFFFFFF,
		"Change iteration > - + ");
	mlx_string_put(m->mlx, m->win, 8, 60, 0xFFFFFF, "Change color palette > c");
	mlx_string_put(m->mlx, m->win, 8, 75, 0xFFFFFF, "Shift > arrow keys");
	mlx_string_put(m->mlx, m->win, 8, 90, 0xFFFFFF,
		"Change Fractols > 1 2 3 4");
	mlx_string_put(m->mlx, m->win, 8, 105, 0xFFFFFF, "Pause Julia Set > p");
	mlx_string_put(m->mlx, m->win, 8, 120, 0xFFFFFF, "Reset > r");
}

void	draw(t_mlx *m)
{
	m->draw.y = -1;
	while (++(m->draw.y) < HEIGHT)
	{
		m->draw.x = -1;
		while (++(m->draw.x) < WIDTH)
		{
			m->draw.index = ((HEIGHT - (m->draw.y + 1)) * WIDTH + m->draw.x);
			m->draw.i = display_fractal(m);
			if (m->draw.i <= m->max_iter)
				((unsigned int *)m->img.str)[m->draw.index] =
				m->color.palette[(m->draw.i) % 16];
			else
				((unsigned int *)m->img.str)[m->draw.index] = 0;
		}
	}
	mlx_put_image_to_window(m->mlx, m->win, m->img.ptr, 0, 0);
	if (m->hide == 1)
		print_instructions(m);
}
