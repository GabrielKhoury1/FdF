/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakhoury <gakhoury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 10:54:18 by gakhoury          #+#    #+#             */
/*   Updated: 2024/08/20 08:51:39 by gakhoury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

static void	draw_line(t_map *map)
{
	t_point	*a;
	t_point	*b;

	a = (t_point *)malloc(sizeof(t_point));
	b = (t_point *)malloc(sizeof(t_point));
	a->x = map->current->x;
	a->y = map->current->y;
	a->z = map->grid[ft_round(map->current->x - map->x_begin)]
	[ft_round(map->current->y - map->y_begin)];
	b->x = map->next->x;
	b->y = map->next->y;
	b->z = map->grid[ft_round(map->next->x - map->x_begin)]
	[ft_round(map->next->y - map->y_begin)];
	map->current_z = ft_abs(a->z);
	apply_view(b, map);
	apply_view(a, map);
	isometric(a);
	isometric(b);
	scale_offset(a, map->zoom);
	scale_offset(b, map->zoom);
	bresenham(map, a, b);
	free(a);
	free(b);
}

static void	draw_map2(t_map *map, float x, float y)
{
	if (x + 1 < map->height + map->x_begin)
	{
		map->next->x = x + 1;
		map->next->y = y;
		map->next->z = map->grid[ft_round(map->next->x - map->x_begin)]
		[ft_round(map->next->y - map->y_begin)];
		draw_line(map);
	}
	if (y + 1 < map->width + map->y_begin)
	{
		map->next->x = x;
		map->next->y = y + 1;
		map->next->z = map->grid[ft_round(map->next->x - map->x_begin)]
		[ft_round(map->next->y - map->y_begin)];
		draw_line(map);
	}
}

static void	draw_map(t_map *map)
{
	float	x;
	float	y;

	init_center(map);
	x = map->x_begin;
	while (x < map->height + map->x_begin)
	{
		y = map->y_begin;
		while (y < map->width + map->y_begin)
		{
			map->current->x = x;
			map->current->y = y;
			map->current->z = map->grid[ft_round(x - map->x_begin)]
			[ft_round(y - map->y_begin)];
			draw_map2(map, x, y);
			y++;
		}
		x++;
	}
}

static void	draw_panel(t_map *map, int width, int height, int color)
{
	int	x;
	int	y;

	y = -1;
	while (++y < height)
	{
		x = -1;
		while (++x < width)
			put_pixel(map, x, y, color);
	}
}

void	draw_image(t_map *map)
{
	if (map->img)
		mlx_destroy_image(map->mlx, map->img);
	map->img = mlx_new_image(map->mlx, WIN_WIDTH, WIN_HEIGHT);
	map->data = mlx_get_data_addr(map->img, &map->bpp,
			&map->size_line, &map->endian);
	ft_memset(map->data, 0, WIN_WIDTH * WIN_HEIGHT * (map->bpp / 8));
	draw_map(map);
	draw_panel(map, PANEL_WIDTH, PANEL_HEIGHT, PANEL_COLOR);
	mlx_put_image_to_window(map->mlx, map->win, map->img, 0, 0);
	print_binds(map);
}
