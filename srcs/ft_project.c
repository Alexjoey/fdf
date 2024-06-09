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

static void ft_rotate_x_axis(int *y, int *z)
{
	int	temp_y;

	temp_y = *y;

	*y = temp_y * cos(X_ANGLE) + *z * sin(X_ANGLE);
	*z = temp_y * -sin(X_ANGLE) + *z * cos(X_ANGLE);
}

static void	ft_rotate_y_axis(int *x, int *z)
{
	int temp_x;

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

t_point	project(int x, int y, t_fdf *obj)
{
	t_point	point;
	int	z;

	z = obj->map->array[y][x] * obj->camera_zoom;
	point.y = (y - obj->map->height / 2) * obj->camera_zoom;
	point.x = (x - obj->map->width / 2) * obj->camera_zoom;
	ft_rotate_x_axis(&point.y , &z);
	ft_rotate_y_axis(&point.x , &z);
	ft_rotate_z_axis(&point.x , &point.y);
	point.x += WINDOWWIDTH / 2;
	point.y += (WINDOWHEIGHT + obj->map->height / 2 * obj->camera_zoom) / 2;
	ft_printf("x is: %i y is: %i\n", point.x, point.y);
	return (point);
}
