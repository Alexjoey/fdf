#include "../includes/fdf.h"

void	get_minmax(t_map *map)
{
	int	min;
	int	max;
	int	y;
	int	x;

	min = map->array[0][0][0];
	max = map->array[0][0][0];
	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			if (map->array[x][y][0] < min)
				min = map->array[x][y][0];
			if (map->array[x][y][0] > max)
				max = map->array[x][y][0];
		}
	}
	map->max = max;
	map->min = min;
}
