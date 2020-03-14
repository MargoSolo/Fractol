/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlongfel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 10:10:11 by xlongfel          #+#    #+#             */
/*   Updated: 2019/11/26 15:05:22 by xlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		close_win(void *param)
{
	(void)param;
	exit(1);
	return (0);
}

int		read_arg(t_map *map, char *str)
{
	if (strcmp(str, "Mandelbrot") == 0)
		map->mode = mandelbrot;
	else if (strcmp(str, "Julia") == 0)
		map->mode = julia;
	else if (strcmp(str, "Ship") == 0)
		map->mode = ship;
	else
	{
		ft_putstr("Valid arguments:\n");
		ft_putstr("'Mandelbrot'\n'Julia'\n'Ship'\n");
		return (0);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	t_map	*map;

	if (argc < 2)
	{
		ft_putstr("Enter arguments :\n");
		ft_putstr("'Mandelbrot'\n'Julia'\n'Ship'\n");
		return (0);
	}
	if (!(map = malloc(sizeof(t_map))))
		return (0);
	if (!read_arg(map, argv[1]))
		return (0);
	init(map);
	mlx_mouse_hook(map->win_p, control_mouse, (void *)(map));
	mlx_hook(map->win_p, 2, 5, control_keyboard, (void *)(map));
	mlx_hook(map->win_p, 6, 5, mouse_move, (void *)(map));
	mlx_hook(map->win_p, 17, 5, close_win, (void *)(map));
	mlx_loop(map->mlx_p);
	return (0);
}
