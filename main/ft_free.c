/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakhoury <gakhoury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:22:05 by gakhoury          #+#    #+#             */
/*   Updated: 2024/08/20 16:01:20 by gakhoury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	handle_error(t_map *map, const char *error_msg)
{
	int	ret;

	if (map)
	{
		free(map->center);
		free(map->current);
		free(map->next);
		free(map->dst);
		free(map);
	}
	if (error_msg)
	{
		ret = write(2, error_msg, ft_strlen(error_msg));
		(void)ret;
	}
	exit(EXIT_FAILURE);
}

void	free_grid(int **grid, int height)
{
	int	i;

	i = -1;
	while (++i < height)
		free(grid[i]);
	free(grid);
}

void	free_map_components(t_map *map)
{
	int	i;

	i = 0;
	free(map->center);
	free(map->current);
	free(map->next);
	while (i < map->height)
	{
		free(map->grid[i]);
		i++;
	}
	free(map->grid);
}

void	cleanup(t_map *map)
{
	if (map->img)
		mlx_destroy_image(map->mlx, map->img);
	if (map->win)
	{
		mlx_destroy_window(map->mlx, map->win);
	}
	if (map->mlx)
		mlx_destroy_display(map->mlx);
}

void	free_char_array(char **array)
{
	int	i;

	if (array == NULL)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
