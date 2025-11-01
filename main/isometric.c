/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakhoury <gakhoury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 10:53:32 by gakhoury          #+#    #+#             */
/*   Updated: 2024/08/19 10:53:42 by gakhoury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	isometric(t_point *a)
{
	float	angle;
	float	tmp_x;
	float	tmp_y;

	angle = 0.46373398;
	tmp_x = a->x;
	tmp_y = a->y;
	a->x = (tmp_x - tmp_y) * cos(angle);
	a->y = (tmp_x + tmp_y) * sin(angle) - a->z * cos(angle);
}
