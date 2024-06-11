/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amylle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:16:33 by amylle            #+#    #+#             */
/*   Updated: 2024/06/11 12:43:48 by amylle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			if (map->array[y][x][0] < min)
				min = map->array[y][x][0];
			if (map->array[y][x][0] > max)
				max = map->array[y][x][0];
		}
	}
	map->max = max;
	map->min = min;
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
	int	baselen;

	baselen = ft_strlen(base);
	ret = 0;
	i = -1;
	while (num[++i])
	{
		j = -1;
		while (base[++j])
			if (base[j] == num[i])
				ret += ret * baselen + j;
	}
	return (ret);
}
