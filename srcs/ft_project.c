/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_project.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amylle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:41:02 by amylle            #+#    #+#             */
/*   Updated: 2024/06/05 13:41:03 by amylle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <math.h>

static void	ft_rotate_x_axis(int *y, int *z)
{
	int	temp_y;

	temp_y = *y;
	*y = temp_y * cos(X_ANGLE) + *z * sin(X_ANGLE);
	*z = temp_y * -sin(X_ANGLE) + *z * cos(X_ANGLE);
}

static void	ft_rotate_y_axis(int *x, int *z)
{
	int	temp_x;

	temp_x = *x;
	*x = temp_x * cos(Y_ANGLE) + *z * sin(Y_ANGLE);
	*z = temp_x * -sin(Y_ANGLE) + *z * cos(Y_ANGLE);
}

static void	ft_rotate_z_axis(int *x, int *y)
{
	int	temp_x;
	int	temp_y;

	temp_x = *x;
	temp_y = *y;
	*x = temp_x * cos(Z_ANGLE) - temp_y * sin(Z_ANGLE);
	*y = temp_x * sin(Z_ANGLE) + temp_y * cos(Z_ANGLE);
}

int	get_defaultcolors(int z, t_fdf *obj)
{
	double	percent;
	int		dz;

	dz = obj->map->max - obj->map->min;
	if (dz == 0)
		return (0xFFFFFF);
	percent = (double)(obj->map->min - z) / dz * -1;
	if (percent > 0.9)
		return (0xE308E7);
	if (percent > 0.8)
		return (0x7823EA);
	if (percent > 0.7)
		return (0x495CE2);
	if (percent > 0.6)
		return (0x6CB9DD);
	if (percent > 0.5)
		return (0x8DDBC9);
	if (percent > 0.4)
		return (0xAADCB5);
	if (percent > 0.3)
		return (0xCDE0C4);
	if (percent > 0.2)
		return (0xE6E7DB);
	return (0xFFFFFF);
}

t_point	project(int x, int y, t_fdf *obj)
{
	t_point	point;
	int		z;

	if (obj->map->array[y][x][1] >= 0)
		point.color = obj->map->array[y][x][1];
	else
		point.color = get_defaultcolors(obj->map->array[y][x][0], obj);
	z = obj->map->array[y][x][0] * obj->camera_zoom;
	point.y = (y - obj->map->height / 2) * obj->camera_zoom;
	point.x = (x - obj->map->width / 2) * obj->camera_zoom;
	ft_rotate_x_axis(&point.y, &z);
	ft_rotate_y_axis(&point.x, &z);
	ft_rotate_z_axis(&point.x, &point.y);
	point.x += WINDOWWIDTH / 2;
	point.y += (WINDOWHEIGHT + obj->map->height / 2 * obj->camera_zoom) / 2;
	return (point);
}
