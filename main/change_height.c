/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_height.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakhoury <gakhoury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:37:52 by gakhoury          #+#    #+#             */
/*   Updated: 2024/08/19 11:38:03 by gakhoury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	ft_increment(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			map->grid[i][j] *= 1.1;
		}
	}
	map->max_z = get_max_z(map);
	map->min_z = get_min_z(map);
}

void	ft_decrement(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			map->grid[i][j] /= 1.1;
		}
	}
	map->max_z = get_max_z(map);
	map->min_z = get_min_z(map);
}
