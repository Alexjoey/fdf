#include "../includes/fdf.h"

void	ft_error(char *str)
{
	ft_putendl_fd(str, 1);
	exit (-1);
}
