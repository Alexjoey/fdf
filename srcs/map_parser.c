/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amylle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:08:36 by amylle            #+#    #+#             */
/*   Updated: 2024/06/03 15:08:38 by amylle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <fcntl.h>

static int	map_getheight(char *filename)
{
	int		height;
	char	*line;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_error("open error");
	height = 0;
	line = get_next_line(fd);
	while (line)
	{
		height++;
		free (line);
		line = get_next_line(fd);
	}
	free (line);
	if (close(fd) == -1)
		ft_error("close error");
	return (height);
}

static int	map_getwidth(char *filename)
{
	int		width;
	int		r;
	char	*line;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_error("open error");
	line = gnl_nobuffer(fd);
	r = -1;
	width = 0;
	if (line[++r] != ' ')
		width++;
	while (line[++r])
		if (line[r] != ' ' && line[r] != '\n' && \
			(line[r - 1] == '\0' || line[r - 1] == ' '))
			width++;
	free (line);
	if (close(fd) == -1)
		ft_error("close error");
	return (width);
}

//fill line with values, in [0] z value, in [1] the color if given
void	fill_arrayline(int	**array, int width, char *line)
{
	int		i;
	int		j;
	char	**splitarray;

	i = -1;
	splitarray = ft_split(line, ' ');
	while (++i < width && splitarray[i])
	{
		array[i] = malloc(sizeof(int) * 2);
		if (!array)
			ft_error("malloc error");
		array[i][0] = ft_atoi(splitarray[i]);
		j = 0;
		while (splitarray[i][j] && splitarray[i][j] != ',')
			j++;
		if (splitarray[i][j] == ',')
			array[i][1] = ft_atoi_base(&splitarray[i][j + 3], \
										"0123456789ABCDEF");
		else
			array[i][1] = -1;
	}
	ft_freestrarray(splitarray);
	if (i != width)
		ft_error("map input error");
}

int	***initarray(int height, int width, char *filename)
{
	int		fd;
	char	*line;
	int		i;
	int		***array;

	array = malloc(sizeof(array) * height);
	if (!array)
		ft_error("malloc error");
	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	i = -1;
	while (line && ++i < height)
	{
		array[i] = malloc(sizeof(*array) * width);
		fill_arrayline(array[i], width, line);
		free (line);
		line = get_next_line(fd);
	}
	free (line);
	if (close(fd) == -1)
		ft_error("close error");
	return (array);
}

void	map_init(t_fdf *obj, char *filename)
{
	obj->map = ft_calloc(1, sizeof(*obj->map));
	if (!obj->map)
		ft_error("malloc error");
	obj->map->width = map_getwidth(filename);
	obj->map->height = map_getheight(filename);
	obj->map->array = initarray(obj->map->height, obj->map->width, filename);
	get_minmax(obj->map);
	obj->camera_zoom = ft_min((WINDOWWIDTH / obj->map->width / 2), \
							WINDOWHEIGHT / obj->map->height / 2);
	if (obj->map->max - obj->map->min != 0)
		obj->camera_zoom = ft_min(obj->camera_zoom, \
			WINDOWHEIGHT / (obj->map->max - obj->map->min));
}
