/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amylle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:41:21 by amylle            #+#    #+#             */
/*   Updated: 2024/06/05 13:41:24 by amylle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <math.h>

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
	obj->addr = mlx_get_data_addr(obj->img, &obj->bpp, \
									&obj->line_len, &obj->endian);
	if (!obj->addr)
		ft_error("data adress init error");
	return (obj);
}

void	printintarray(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
			ft_printf("%i ", map->array[i][j]);
		ft_printf("\n");
	}
}

int	main(int argc, char **argv)
{
	t_fdf	*obj;

	if (argc == 2)
	{
		obj = fdf_init(argv[1]);
		map_init(obj, argv[1]);
		ft_drawmap(obj);
		ft_hooks(obj);
		mlx_put_image_to_window(obj->mlx, obj->win, obj->img, 0, 0);
		mlx_loop(obj->mlx);
	}
	else
		ft_printf("wrong input, valid input should be: ./fdf FILENAME\n");
}

void	my_pixel_put(t_fdf *obj, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x > WINDOWWIDTH || y < 0 || y > WINDOWHEIGHT)
		return ;
	dst = obj->addr + (y * obj->line_len + x * (obj->bpp / 8));
	*(unsigned int *)dst = color;
}

int	ft_atoi_base(char *num, char *base)
{
	int	ret;
	int	i;
	int	j;

	ret = 0;
	i = ft_strlen(num);
	while (--i >= 0)
	{
		j = -1;
		while (base[++j])
			if (base[j] == num[i])
				ret += j * (pow(ft_strlen(base), ft_strlen(num) - i - 1));
	}
	return (ret);	
}
