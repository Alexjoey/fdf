#include "../includes/fdf.h"

void	ft_error(char *str)
{
	ft_putendl_fd(str, 1);
	exit (-1);
}

void	ft_freemap(t_fdf *obj)
{
	int	i;

	i = -1;
	while (++i < obj->map->height)
		free (obj->map->array[i]);
	free (obj->map->array);
	free (obj->map);

}
