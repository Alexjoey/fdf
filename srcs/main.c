#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	*obj;

	if (argc == 2)
	{
		obj = ft_calloc(1, sizeof(*obj));
		map_init(obj, argv[1]);
		ft_printf("width is: %i\n height is: %i\n", obj->map->width, obj->map->height);
	}
	ft_freemap(obj);
	free (obj);
}
