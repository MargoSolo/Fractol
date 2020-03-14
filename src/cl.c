
#include "fractol.h"

void	move_julia(t_map *m, int x, int y)
{
	m->move = 1;
	m->x = x;
	m->y = y;
	update_image(m);
}