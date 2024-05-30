#include "../includes/fdf.h"

static int	map_getwidth(char *filename)
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

static int	map_getheight(char *filename)
{
	int		height;
	int		r;
	char	*line;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_error("open error");
	line = gnl_nobuffer(fd);
	r = -1;
	height = 0;
	while (line[++r])
		if (line[r] != ' ' && (line[r + 1] == '\0' || line[r + 1] == ' '))
			height++;
	free (line);
	if(close(fd) == -1)
		ft_error("close error");
	return (height);
}

void	map_init(t_fdf *obj, char *filename)
{
	int	fd;

	obj->map = ft_calloc(1, sizeof(*obj->map));
	if (!obj->map)
		ft_error("malloc error");
	obj->map->width = map_getwidth(filename);
	obj->map->height = map_getheight(filename);
}
