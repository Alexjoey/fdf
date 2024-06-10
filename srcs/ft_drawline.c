/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amylle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:40:43 by amylle            #+#    #+#             */
/*   Updated: 2024/06/05 13:40:45 by amylle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	scalc(int start, int end)
{
	if (start < end)
		return 1;
	else
		return -1;
}

void	ft_draw_line(t_point s, t_point e, t_fdf *obj)
{
	int	dx;
	int	dy;
	int sx;
	int sy;
	int err;
	
	dx = ft_abs(e.x - s.x);
	dy = ft_abs(e.y - s.y);
	err = dx - dy;
	sx = scalc(s.x, e.x);
	sy = scalc(s.y, e.y);
	while (s.x != e.x && s.y != e.y)
	{
		my_pixel_put(obj, s.x, s.y, 0x00FFFFFF);
		if (err * 2 > -dy)
		{
			err -= dy;
			s.x += sx;
		}
		if (err * 2 < dx)
		{
			err += dx;
			s.y += sy;
		}
	}
	my_pixel_put(obj, s.x, s.y, 0x00FFFFFF);
}
