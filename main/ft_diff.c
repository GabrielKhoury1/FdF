/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_diff.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakhoury <gakhoury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 10:14:38 by gakhoury          #+#    #+#             */
/*   Updated: 2024/08/19 10:14:51 by gakhoury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

float	ft_dx(t_point *a, t_point *b)
{
	return (b->x - a->x);
}

float	ft_dy(t_point *a, t_point *b)
{
	return (b->y - a->y);
}

float	ft_dz(t_map *map)
{
	return (map->current->z - map->next->z);
}
