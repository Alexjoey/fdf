/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amylle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:41:09 by amylle            #+#    #+#             */
/*   Updated: 2024/06/05 13:41:11 by amylle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <X11/keysym.h>

int	ft_close_win(void *param)
{
	t_fdf	*obj;

	obj = (t_fdf *) param;

	mlx_destroy_window(obj->mlx, obj->win);
	mlx_destroy_image(obj->mlx, obj->img);
	mlx_destroy_display(obj->mlx);
	ft_freemap(obj->map);
	free (obj->mlx);
	free (obj);
	exit (0);
}

int	ft_keypress(int keycode, void *param)
{
	if (keycode == XK_Escape)
		ft_close_win(param);
	return (0);
}

void	ft_hooks(t_fdf *obj)
{
	mlx_hook(obj->win, 17 , 0, ft_close_win, obj);
	mlx_hook(obj->win, 2 , 1L<<0, ft_keypress, obj);
}
