/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakhoury <gakhoury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 10:27:19 by gakhoury          #+#    #+#             */
/*   Updated: 2024/08/26 11:35:47 by gakhoury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

static void	slope_less_than_one(t_map *map, t_point *a, t_point *b)
{
	float	p;
	int		i;
	float	x;
	float	y;

	i = -1;
	p = 2 * ft_abs(ft_dy(a, b)) - ft_abs(ft_dx(a, b));
	y = a->y;
	x = a->x;
	while (++i < ft_abs(ft_dx(a, b)))
	{
		x += map->dir_1;
		if (p < 0)
			p += 2 * ft_abs(ft_dy(a, b));
		else
		{
			y += map->dir_2;
			p += 2 * ft_abs(ft_dy(a, b)) - 2 * ft_abs(ft_dx(a, b));
		}
		put_line(map, x, y);
	}
}

static void	slope_bigger_than_one(t_map *map, t_point *a, t_point *b)
{
	float	p;
	int		i;
	float	x;
	float	y;

	i = -1;
	p = 2 * ft_abs(ft_dx(a, b)) - ft_abs(ft_dy(a, b));
	y = a->y;
	x = a->x;
	while (++i < ft_abs(ft_dy(a, b)))
	{
		y += map->dir_2;
		if (p < 0)
			p += 2 * ft_abs(ft_dx(a, b));
		else
		{
			x += map->dir_1;
			p += 2 * ft_abs(ft_dx(a, b)) - 2 * ft_abs(ft_dy(a, b));
		}
		put_line(map, x, y);
	}
}

static void	give_direction(t_map *map, float dx, float dy)
{
	if (ft_abs(dx) > ft_abs(dy))
	{
		if (dx > 0)
			map->dir_1 = 1;
		else
			map->dir_1 = -1;
		if (dy > 0)
			map->dir_2 = 1;
		else
			map->dir_2 = -1;
	}
	else
	{
		if (dy > 0)
			map->dir_2 = 1;
		else
			map->dir_2 = -1;
		if (dx > 0)
			map->dir_1 = 1;
		else
			map->dir_1 = -1;
	}
}

void	bresenham(t_map *map, t_point *a, t_point *b)
{
	float	dx;
	float	dy;

	dx = b->x - a->x;
	dy = b->y - a->y;
	give_direction(map, dx, dy);
	if (ft_abs(dx) > ft_abs(dy))
	{
		slope_less_than_one(map, a, b);
	}
	else
		slope_bigger_than_one(map, a, b);
}
