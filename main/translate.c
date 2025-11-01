/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakhoury <gakhoury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:20:16 by gakhoury          #+#    #+#             */
/*   Updated: 2024/08/19 11:20:51 by gakhoury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	translate(int translation, t_map *map, int keycode)
{
	if (keycode == 97 || keycode == 100)
	{
		map->x_begin += translation;
		map->center->x += translation;
	}
	if (keycode == 115 || keycode == 119)
	{
		map->y_begin += translation;
		map->center->y += translation;
	}
}
