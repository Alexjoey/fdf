/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amylle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:40:33 by amylle            #+#    #+#             */
/*   Updated: 2024/06/05 13:40:38 by amylle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_error(char *str)
{
	ft_putendl_fd(str, 1);
	exit (-1);
}

void	ft_freemap(t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->height)
		free (map->array[i]);
	free (map->array);
	free (map);
}

void	ft_freestrarray(char **strarray)
{
	int	i;

	i = -1;
	while (strarray[++i])
		free (strarray[i]);
	free (strarray);
}
