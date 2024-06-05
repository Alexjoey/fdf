#ifndef FDF_H
# define FDF_H

# include "../libft/inc/libft.h"
# include <fcntl.h>
# include "../mlx/mlx.h"

# define WINDOWWIDTH 1920
# define WINDOWHEIGHT 1080
# define X_ANGLE -0.61547290
# define Y_ANGLE -0.523599
# define Z_ANGLE 0.61547290

typedef struct s_point
{
	int x;
	int y;
	int color;
}		t_point;

typedef struct s_map
{
	int	**array;
	int	width;
	int	height;
}		t_map;

typedef struct s_fdf
{
	t_map	*map;
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
	int		camera_zoom;
}			t_fdf;

void	ft_error(char *str);
void	ft_freemap(t_map *map);
void	map_init(t_fdf *obj, char *filename);
void	ft_hooks(t_fdf *obj);
void	ft_freestrarray(char **strarray);
void	ft_drawmap(t_fdf *obj);

#endif 
