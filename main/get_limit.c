/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_limit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakhoury <gakhoury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 10:11:38 by gakhoury          #+#    #+#             */
/*   Updated: 2024/08/19 12:17:35 by gakhoury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

float	get_max_z(t_map *map)
{
	int		i;
	int		j;
	float	max;

	max = INT_MIN;
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (ft_abs(map->grid[i][j]) > max)
				max = ft_abs(map->grid[i][j]);
			j++;
		}
		i++;
	}
	return (ft_abs(max));
}

float	get_min_z(t_map *map)
{
	int		i;
	int		j;
	float	min;

	min = INT_MAX;
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (ft_abs(map->grid[i][j]) < min)
				min = ft_abs(map->grid[i][j]);
			j++;
		}
		i++;
	}
	return (ft_abs(min));
}
