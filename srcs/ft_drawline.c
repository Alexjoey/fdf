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

int	scalc(int start, int end)
{
	if (start < end)
		return (1);
	else
		return (-1);
}

//bresenhams line algo
//norminette should go fucking end itself right now
void	ft_draw_line(t_point s, t_point e, t_fdf *obj)
{
	t_lineargs	a;

	a.dx = ft_abs(e.x - s.x);
	a.dy = ft_abs(e.y - s.y);
	a.err = a.dx - a.dy;
	a.sx = scalc(s.x, e.x);
	a.sy = scalc(s.y, e.y);
	while (1)
	{
		a.err2 = a.err * 2;
		my_pixel_put(obj, s.x, s.y, 0x00FFFFFF);
		if (s.x == e.x && s.y == e.y)
			break ;
		if (a.err2 > -a.dy)
		{
			a.err -= a.dy;
			s.x += a.sx;
		}
		if (a.err2 < a.dx)
		{
			a.err += a.dx;
			s.y += a.sy;
		}
	}
}
