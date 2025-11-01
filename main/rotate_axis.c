/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_axis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakhoury <gakhoury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:17:26 by gakhoury          #+#    #+#             */
/*   Updated: 2024/08/19 11:17:53 by gakhoury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	top_side_rotate(t_map *map)
{
	map->alpha += ROTATION_INCREMENT;
	if (map->alpha >= 2 * M_PI)
		map->alpha -= 2 * M_PI;
	draw_image(map);
}

void	front_side_rotate(t_map *map)
{
	map->theta += ROTATION_INCREMENT;
	if (map->theta >= 2 * M_PI)
		map->theta -= 2 * M_PI;
	draw_image(map);
}

void	right_side_rotate(t_map *map)
{
	map->gamma += ROTATION_INCREMENT;
	if (map->gamma >= 2 * M_PI)
		map->gamma -= 2 * M_PI;
	draw_image(map);
}
