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

int	ft_lerp(int start, int end, double percent)
{
	if (start == end)
		return (start);
	return ((int)(double) start + (end - start) * percent);
}

int	interpol_color(int scolor, int ecolor, double percent)
{
	int	r;
	int	g;
	int	b;

	r = ft_lerp((scolor >> 16) & 0xFF, (ecolor >> 16) & 0xFF, percent);
	g = ft_lerp((scolor >> 8) & 0xFF, (ecolor >> 8) & 0xFF, percent);
	b = ft_lerp(scolor & 0xFF, ecolor & 0xFF, percent);
	return ((r << 16) | (g << 8) | b);
}

// who said you would never use pythagoras ever again ...
int	get_gradient(t_point start, t_point end, t_point curr)
{
	double	linelen;
	double	currlen;
	double	percent;
	int		color;

	if (start.color == end.color)
		return (start.color);
	linelen = sqrt(pow(end.x - start.x, 2) + pow(end.y - start.y, 2));
	currlen = sqrt(pow(curr.x - start.x, 2) + pow(curr.y - start.y, 2));
	percent = currlen / linelen;
	color = interpol_color(start.color, end.color, percent);
	return (color);
}

//bresenhams line algo
//norminette should go fucking end itself right now
void	ft_draw_line(t_point start, t_point end, t_fdf *obj)
{
	t_lineargs	a;

	a.curr = start;
	a.dx = ft_abs(end.x - start.x);
	a.dy = ft_abs(end.y - start.y);
	a.err = a.dx - a.dy;
	a.sx = scalc(start.x, end.x);
	a.sy = scalc(start.y, end.y);
	while (1)
	{
		a.err2 = a.err * 2;
		my_pixel_put(obj, a.curr.x, a.curr.y, get_gradient(start, end, a.curr));
		if (a.curr.x == end.x && a.curr.y == end.y)
			break ;
		if (a.err2 > -a.dy)
		{
			a.err -= a.dy;
			a.curr.x += a.sx;
		}
		if (a.err2 < a.dx)
		{
			a.err += a.dx;
			a.curr.y += a.sy;
		}
	}
}
