
#include "fractol.h"

void	update_image(t_map *map)
{
	set_fractal_values(map);
	mlx_put_image_to_window(map, map->win_p, map->image_ptr,
			0, 0);
	if (map->menu_on)
		display_menu(map);
}

void	destroy_image(t_map *map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	map->destroy = 1;
	mlx_put_image_to_window(map, map->win_p, map->image_ptr,
			WIN_X / 2, WIN_Y / 2);
	mlx_destroy_image(map->mlx_p, map->image_ptr);
	map->destroy = 0;
}

void	create_image(t_map *map)
{
	int bpp;
	int s_l;
	int endian;

	map->image_ptr = mlx_new_image(map->mlx_p, WIN_X, WIN_Y);
	map->my_image_str = mlx_get_data_addr(map->image_ptr, &(bpp),
			&(s_l), &(endian));
}

void	create_mlx(t_map *map)
{
	map->mlx_p = mlx_init();
	map->win_p = mlx_new_window(map->mlx_p, WIN_X, WIN_Y, "Fractol");
}

int		init(t_map *map)
{
	create_mlx(map);
	create_image(map);
	map->move = 0;
	map->code = 1;
	map->i_max = 50;
	map->lock = 0;
	map->set_v = 0;
	map->form_c = set_form_color(map->form_c, 1);
	map->origin_c = modify_color(map, map->origin_c, 1, 0);
	set_fractal_values(map);
	mlx_put_image_to_window(map, map->win_p, map->image_ptr,
	0, 0);
	create_menu(map);
	return (1);
}
