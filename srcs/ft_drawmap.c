/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amylle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:40:50 by amylle            #+#    #+#             */
/*   Updated: 2024/06/05 13:40:54 by amylle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_drawmap(t_fdf *obj)
{
	int	x;
	int	y;

	obj->camera_zoom = ft_min((WINDOWWIDTH / obj->map->width / 2), \
							WINDOWHEIGHT / obj->map->height / 2);
	if (obj->map->max - obj->map->min != 0)
		obj->camera_zoom = ft_min(obj->camera_zoom, \
			WINDOWHEIGHT / (obj->map->max - obj->map->min));
	y = -1;
	while (++y < obj->map->height)
	{
		x = -1;
		while (++x < obj->map->width)
		{
			if (y != obj->map->height - 1)
				ft_draw_line(project(x, y, obj), project(x, y + 1, obj), obj);
			if (x != obj->map->width - 1)
				ft_draw_line(project(x, y, obj), project(x + 1, y, obj), obj);
		}
	}
}
