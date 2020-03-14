
#include "fractol.h"

void	create_menu(t_map *map)
{
	int bpp;
	int s_l;
	int endian;

	map->menu_ptr = mlx_new_image(map->mlx_p, 400, 200);
	map->menu_str = (unsigned char*)
		mlx_get_data_addr(map->menu_ptr, &(bpp), &(s_l), &(endian));
	map->menu_on = 1;
	map->menu_on = 1;
	display_menu(map);
}

void	display_menu(t_map *map)
{
	int i;

	i = 0;
	while (i < 400 * 200 * 4)
	{
		map->menu_str[i] = 255;
		map->menu_str[i + 1] = 255;
		map->menu_str[i + 2] = 255;
		map->menu_str[i + 3] = 50;
		i += 4;
	}
	mlx_put_image_to_window(map->mlx_p, map->win_p, map->menu_ptr, 10, 10);
	write_menu(map);
	map->menu_on = 1;
}

void	hide_menu(t_map *map)
{
	int i;

	i = 0;
	while (i < 400 * 200 * 4)
	{
		map->menu_str[i] = 0;
		map->menu_str[i + 1] = 0;
		map->menu_str[i + 2] = 0;
		i += 4;
	}
	mlx_put_image_to_window(map->mlx_p, map->win_p, map->menu_ptr, 10, 10);
	map->menu_on = 0;
	update_image(map);
}

