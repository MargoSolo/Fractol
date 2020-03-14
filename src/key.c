#include "fractol.h"

int	create_thread(t_map *map)
{
	pthread_t	threads[8];
	int			i;

	i = 0;
	while (i < 8)
	{
		if (pthread_create(&threads[i++], NULL, draw_mend, (void *)map) == -1)
			return (EXIT_FAILURE);
	}
	i = 0;
	while (i < 8)
	{
		if (pthread_join(threads[i++], NULL))
			return (EXIT_FAILURE);
	}
	return (1);
}