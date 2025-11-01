/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakhoury <gakhoury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 10:52:42 by gakhoury          #+#    #+#             */
/*   Updated: 2024/08/26 11:31:03 by gakhoury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	init_center(t_map *map)
{
	int	x_min;
	int	x_max;
	int	y_min;
	int	y_max;

	x_min = map->x_begin;
	x_max = map->x_begin + map->width;
	y_min = map->y_begin;
	y_max = map->y_begin + map->height;
	map->center->z = 0;
	map->center->x = (x_min + x_max) / 2;
	map->center->y = (y_min + y_max) / 2;
}

int	init_map(t_map *map, char *filename)
{
	map->x_begin = 0.0f;
	map->y_begin = 0.0f;
	map->z_begin = 0.0f;
	map->theta = 0;
	map->gamma = 0;
	map->alpha = 0;
	map->current_z = 0;
	map->width = 0;
	map->zoom = ZOOM;
	map->mlx = NULL;
	map->win = NULL;
	map->img = NULL;
	map->shift_pressed = 0;
	map->center = (t_point *)malloc(sizeof(t_point));
	map->current = (t_point *)malloc(sizeof(t_point));
	map->next = (t_point *)malloc(sizeof(t_point));
	get_coordinates(filename, map);
	read_file_into_grid(filename, map);
	if (!init_mlx(map))
		return (0);
	map->min_z = get_min_z(map);
	map->max_z = get_max_z(map);
	return (1);
}

int	init_mlx(t_map *map)
{
	int	ret;

	map->mlx = mlx_init();
	if (map->mlx == NULL)
	{
		ret = write(2, "Error initializing MiniLibX\n", 28);
		return (ret);
	}
	map->win = mlx_new_window(map->mlx, WIN_WIDTH, WIN_HEIGHT, "FdF");
	if (map->win == NULL)
	{
		ret = write(2, "Error creating window\n", 22);
		return (ret);
	}
	return (1);
}
