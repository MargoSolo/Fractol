
#include "fractol.h"

void	write_menu(t_map *map)
{
	int value;
	int value2;

	value = 30;
	value2 = 40;
	mlx_string_put(map->mlx_p, map->win_p, value2, value, 0,
		"Change fractal      : 1 2 3");
	mlx_string_put(map->mlx_p, map->win_p, value2, value + 20, 0,
		"Zoom                : mouse wheel");
	mlx_string_put(map->mlx_p, map->win_p, value2, value + 40, 0,
		"Move Fractal        : arrows");
	mlx_string_put(map->mlx_p, map->win_p, value2, value + 60, 0,
		"Change colors       : num pad");
	mlx_string_put(map->mlx_p, map->win_p, value2, value + 80, 0,
		"Hide menu           : right click");
	mlx_string_put(map->mlx_p, map->win_p, value2, value + 100, 0,
		"Lock Julia          : L");
	mlx_string_put(map->mlx_p, map->win_p, value2, value + 120, 0,
		"Quit                : echap");
}