/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakhoury <gakhoury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 10:49:20 by gakhoury          #+#    #+#             */
/*   Updated: 2024/08/19 10:50:12 by gakhoury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

static void	rotate_z(t_point *a, double gamma, t_map *map)
{
	double	tmp_x;
	double	tmp_y;

	tmp_x = a->x - map->center->x;
	tmp_y = a->y - map->center->y;
	a->x = tmp_x * cos(gamma) - tmp_y * sin(gamma) + map->center->x;
	a->y = tmp_x * sin(gamma) + tmp_y * cos(gamma) + map->center->y;
}

static void	rotate_y(t_point *a, double theta, t_map *map)
{
	double	tmp_x;
	double	tmp_z;

	tmp_x = a->x - map->center->x;
	tmp_z = a->z - map->center->z;
	a->x = tmp_x * cos(theta) + tmp_z * sin(theta) + map->center->x;
	a->z = tmp_z * cos(theta) - tmp_x * sin(theta) + map->center->z;
}

static void	rotate_x(t_point *a, double alpha, t_map *map)
{
	double	tmp_y;
	double	tmp_z;

	tmp_y = a->y - map->center->y;
	tmp_z = a->z - map->center->z;
	a->y = tmp_y * cos(alpha) - tmp_z * sin(alpha) + map->center->y;
	a->z = tmp_y * sin(alpha) + tmp_z * cos(alpha) + map->center->z;
}

void	apply_view(t_point *a, t_map *map)
{
	rotate_x(a, map->alpha, map);
	rotate_y(a, map->theta, map);
	rotate_z(a, map->gamma, map);
}
