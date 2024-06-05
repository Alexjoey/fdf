#include "../includes/fdf.h"

void	ft_drawmap(t_fdf *obj)
{
	int	x;
	int	y;

	y = -1;
	while (++y < obj->map->height)
	{
		x = -1;
		while (++x < obj->map->width)
		{
			if (y != obj->map->height - 1)
				ft_draw_ver_line(x, y, obj->map->array[y][x], obj);
			if (x != obj->map->width - 1)
		}
	}
}
