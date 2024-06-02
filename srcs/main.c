#include "../includes/fdf.h"

static t_fdf	*fdf_init(char *windowtitle)
{
	t_fdf	*obj;

	obj = ft_calloc(1, (sizeof(t_fdf)));
	if (!obj)
		ft_error("malloc error for fdf");
	obj->mlx = mlx_init();
	if (!obj->mlx)
		ft_error("mlx malloc error");
	obj->win = mlx_new_window(obj->mlx, WINDOWWIDTH, WINDOWHEIGHT, windowtitle);
	if (!obj->win)
		ft_error("window malloc error");
	obj->img = mlx_new_image(obj->mlx, WINDOWWIDTH, WINDOWHEIGHT);
	if (!obj->img)
		ft_error("img malloc error");
	obj->addr = mlx_get_data_addr(obj->mlx, &obj->bits_per_pixel, &obj->line_len, &obj->endian);
	if (!obj->addr)
		ft_error("data adress init error");
	return (obj);
}

int	ft_close_win(void	*var)
{
	t_fdf	*obj;

	obj = (t_fdf *) var;

	mlx_destroy_window(obj->mlx, obj->win);
	mlx_destroy_image(obj->mlx, obj->img);
	mlx_destroy_display(obj->mlx);
	ft_freemap(obj->map);
	free (obj->mlx);
	free (obj);
	exit (0);
}
int	main(int argc, char **argv)
{
	t_fdf	*obj;

	if (argc == 2)
	{
		obj = fdf_init(argv[1]);
		map_init(obj, argv[1]);
		mlx_hook(obj->win, 17 , 0, ft_close_win, obj);
		mlx_loop(obj->mlx);
	}
}

void	my_pixel_put(t_fdf *obj, int x, int y, int color)
{
	char *dst;

	dst = obj->addr + (y *obj->line_len + x * (obj->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

/*int	main(void)
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
	mlx_hook(mlx_win, 17 , 0, ft_close_win, )
	mlx_destroy_image(mlx, img.img);
	mlx_destroy_window(mlx, mlx_win);
	mlx_destroy_display(mlx);
	free (mlx);
}*/
