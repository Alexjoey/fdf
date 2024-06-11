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
