/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binds.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakhoury <gakhoury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:38:40 by gakhoury          #+#    #+#             */
/*   Updated: 2024/09/13 13:36:50 by gakhoury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	print_binds(t_map *map)
{
	mlx_string_put(map->mlx, map->win, 10, 20, 0xFFFFFF, "Rotate X: Z");
	mlx_string_put(map->mlx, map->win, 10, 60, 0xFFFFFF, "Rotate Y: X");
	mlx_string_put(map->mlx, map->win, 10, 100, 0xFFFFFF, "Rotate Z: C");
	mlx_string_put(map->mlx, map->win,
		170, 20, 0xFFFFFF, "Reverse Rotate X: Shift + Z");
	mlx_string_put(map->mlx, map->win,
		170, 60, 0xFFFFFF, "Reverse Rotate Y: Shift + X");
	mlx_string_put(map->mlx, map->win, 170, 100,
		0xFFFFFF, "Reverse Rotate Z: Shift + C");
	mlx_string_put(map->mlx, map->win, 10, 300, 0xADD8E6, "Translate Up: W");
	mlx_string_put(map->mlx, map->win, 10, 340, 0xADD8E6, "Translate Down: A");
	mlx_string_put(map->mlx, map->win, 170, 300, 0xADD8E6, "Translate Left: S");
	mlx_string_put(map->mlx, map->win, 170, 340,
		0xADD8E6, "Translate Right: D");
	mlx_string_put(map->mlx, map->win, 10, 500, 0x90EE90, "Zoom In: Q");
	mlx_string_put(map->mlx, map->win, 10, 540, 0x90EE90, "Zoom Out: E");
	mlx_string_put(map->mlx, map->win, 170, 500,
		0x90EE90, "Increment Height: R");
	mlx_string_put(map->mlx, map->win, 170, 540,
		0x90EE90, "Decrement Height: T");
}

int	key_release(int keycode, t_map *map)
{
	if (keycode == 65505 || keycode == 65506)
		map->shift_pressed = 0;
	return (0);
}

static void	key_hook2(int keycode, t_map *map)
{
	if (map->shift_pressed)
	{
		if (keycode == 122)
			top_side_rrotate(map);
		else if (keycode == 120)
			front_side_rrotate(map);
		else if (keycode == 99)
			right_side_rrotate(map);
	}
	else
	{
		if (keycode == 122)
			top_side_rotate(map);
		else if (keycode == 120)
			front_side_rotate(map);
		else if (keycode == 99)
			right_side_rotate(map);
		else if (keycode == 116)
			ft_decrement(map);
		else if (keycode == 114)
			ft_increment(map);
	}
}

int	key_hook(int keycode, t_map *map)
{
	if (keycode == 65505 || keycode == 65506)
		map->shift_pressed = 1;
	if (keycode == 97 || keycode == 119)
		translate(-TRANSLATION, map, keycode);
	else if (keycode == 100 || keycode == 115)
		translate(TRANSLATION, map, keycode);
	else if (keycode == 113)
		map->zoom *= 1.05;
	else if (keycode == 101)
		map->zoom /= 1.05;
	else
		key_hook2(keycode, map);
	if (keycode == 65307)
	{
		free_map_components(map);
		cleanup(map);
		free(map->mlx);
		free(map->dst);
		free(map);
		exit(0);
	}
	else
		draw_image(map);
	return (1);
}
