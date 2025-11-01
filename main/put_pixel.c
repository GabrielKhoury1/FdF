/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakhoury <gakhoury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 10:18:02 by gakhoury          #+#    #+#             */
/*   Updated: 2024/08/19 10:18:31 by gakhoury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	put_pixel(t_map *map, int x, int y, int color)
{
	int	i;

	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		i = (y * map->size_line) + (x * (map->bpp / 8));
		if (i >= 0 && i + 3 < WIN_WIDTH * WIN_HEIGHT * (map->bpp / 8))
		{
			*(unsigned int *)(map->data + i) = color;
		}
	}
}
