/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amylle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:41:43 by amylle            #+#    #+#             */
/*   Updated: 2024/06/11 12:27:16 by amylle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/inc/libft.h"
# include <fcntl.h>
# include "../mlx/mlx.h"
# include <math.h>
# define WINDOWWIDTH 1920
# define WINDOWHEIGHT 1080
# define X_ANGLE -0.615472907
# define Y_ANGLE -0.523599
# define Z_ANGLE 0.615472907

typedef struct s_point
{
	int	x;
	int	y;
	int	color;
}		t_point;

typedef struct s_lineargs
{
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		err;
	int		err2;
	t_point	curr;
}			t_lineargs;

typedef struct s_map
{
	int	***array;
	int	width;
	int	height;
	int	min;
	int	max;
}		t_map;

typedef struct s_fdf
{
	t_map	*map;
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		camera_zoom;
}			t_fdf;

void	ft_error(char *str);
void	my_pixel_put(t_fdf *obj, int x, int y, int color);
void	ft_freemap(t_map *map);
void	map_init(t_fdf *obj, char *filename);
void	ft_hooks(t_fdf *obj);
void	ft_freestrarray(char **strarray);
void	ft_drawmap(t_fdf *obj);
void	ft_draw_line(t_point start, t_point end, t_fdf *obj);
t_point	project(int x, int y, t_fdf *obj);
int		ft_atoi_base(char *num, char *base);
void	get_minmax(t_map *map);
int		ft_atoi_base(char *num, char *base);
void	printintarray(t_map *map);

#endif 
