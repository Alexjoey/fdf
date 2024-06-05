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
	int		width;
	char	*line;
	int		i;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_error("open error");
	width = 0;
	line = get_next_line(fd);
	while (line)
	{
		i = -1;
		while (line[++i])
			if (line[i] == '\n')
				width++;
		free (line);
		line = get_next_line(fd);
	}
	free (line);
	if (close(fd) == -1)
		ft_error("close error");
	return (width);
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
	while (line[++r])
		if (line[r] != ' ' && (line[r + 1] == '\0' || line[r + 1] == ' '))
			width++;
	free (line);
	if(close(fd) == -1)
		ft_error("close error");
	return (width);
}

void fill_arrayline(int	*array, int width, char *line)
{
	int		i;
	char	**splitarray;

	i = -1;
	splitarray = ft_split(line, ' ');
	while (++i < width && splitarray[i])
		array[i] = ft_atoi(splitarray[i]);
	ft_freestrarray(splitarray);
	if (i != width)
		ft_error("map input error");
}

int	**map_initarray(int height, int width, char *filename)
{
	int		fd;
	char	*line;
	int		i;
	int		**array;

	array = malloc(sizeof(array) * height);
	if (!array)
		ft_error("malloc error");
	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	i = -1;
	while (line && ++i < height)
	{
		array[i] = malloc(sizeof(int) * width);
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
	int	fd;

	obj->map = ft_calloc(1, sizeof(*obj->map));
	if (!obj->map)
		ft_error("malloc error");
	obj->map->width = map_getwidth(filename);
	obj->map->height = map_getheight(filename);
	obj->map->array = map_initarray(obj->map->height, obj->map->width, filename);
}
