#include "../includes/fdf.h"

/*int	main(int argc, char **argv)
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
}*/
void	my_pixel_put(t_data *img, int x, int y, int color)
{
	char *dst;

	dst = img->addr + (y *img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		i;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	i = 0;	
	while (++i < 1000)
		my_pixel_put(&img, i + 5, i + 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
