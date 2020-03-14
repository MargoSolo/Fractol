/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jul.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlongfel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:17:39 by xlongfel          #+#    #+#             */
/*   Updated: 2020/03/02 16:17:40 by xlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	apply_zoom(t_map *map, double mouse_re, double mouse_im,
		double zoom_factor)
{
	double interpolation;

	if (map->zoom_x > 10 || zoom_factor > 1)
	{
		interpolation = 1.0 / zoom_factor;
		map->x1 = interpolate(mouse_re, map->x1, interpolation);
		map->y1 = interpolate(mouse_im, map->y1, interpolation);
		map->x2 = interpolate(mouse_re, map->x2, interpolation);
		map->y2 = interpolate(mouse_im, map->y2, interpolation);
		if (map->i_max < 500 && zoom_factor > 1)
			map->i_max += 1;
		update_image(map);
	}
}

double	interpolate(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}