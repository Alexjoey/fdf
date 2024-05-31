#ifndef FDF_H
# define FDF_H

# include "../libft/inc/libft.h"
# include <fcntl.h>

typedef struct s_map
{
	int	**array;
	int	width;
	int	height;
}		t_map;

typedef struct s_fdf
{
	t_map	*map;
}			t_fdf;

void	ft_error(char *str);
void	ft_freemap(t_fdf *obj);
void	map_init(t_fdf *obj, char *filename);
#endif 
