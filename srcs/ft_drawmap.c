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

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

void	ft_drawmap(t_fdf *obj)
{
	int	x;
	int	y;

	y = -1;
	obj->camera_zoom = ft_min((WINDOWWIDTH / obj->map->width / 2), \
								(WINDOWHEIGHT / obj->map->height / 2));
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
