#include "../includes/fdf.h"

void	ft_error(char *str)
{
	ft_putendl_fd(str, 1);
	exit (-1);
}

void	ft_freemap(t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->height)
		free (map->array[i]);
	free (map->array);
	free (map);
}

void	ft_freestrarray(char **strarray)
{
	int	i;

	i = -1;
	while (strarray[++i])
		free (strarray[i]);
	free (strarray);
}
