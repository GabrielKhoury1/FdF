/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakhoury <gakhoury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:16:25 by gakhoury          #+#    #+#             */
/*   Updated: 2024/08/26 10:12:02 by gakhoury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

static void	put_line_2(t_map *map, float x, float y)
{
	float	z_fraction;
	float	current;

	if (map->current->z > map->next->z)
		current = map->next->z;
	else
		current = map->current->z;
	z_fraction = ft_fraction(3 * map->max_z / 4, map->max_z,
			ft_abs(current));
	put_pixel(map, x, y, interpolate_color(0xd0d4d7, 0xe6e9f1, z_fraction));
}

void	put_line(t_map *map, float x, float y)
{
	float	z_fraction;
	float	current;

	if (map->current->z > map->next->z)
		current = map->next->z;
	else
		current = map->current->z;
	if (map->current->z < map->max_z / 4)
	{
		z_fraction = ft_fraction(map->min_z, map->max_z / 4,
				ft_abs(current));
		put_pixel(map, x, y, interpolate_color(0x003f6c, 0x6B8E23, z_fraction));
	}
	else if (map->current->z < map->max_z / 2)
	{
		z_fraction = ft_fraction(map->max_z / 4, map->max_z / 2,
				ft_abs(current));
		put_pixel(map, x, y, interpolate_color(0x6B8E23, 0xd0d4d7, z_fraction));
	}
	else
		put_line_2(map, x, y);
}
