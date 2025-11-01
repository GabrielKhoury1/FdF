/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_offset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakhoury <gakhoury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 10:13:30 by gakhoury          #+#    #+#             */
/*   Updated: 2024/08/19 10:13:40 by gakhoury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	scale_offset(t_point *a, float zoom)
{
	a->x *= zoom;
	a->y *= zoom;
	a->x += (WIN_WIDTH - (float)(10 * zoom)) / 2 + TRANSLATION;
	a->y += (WIN_HEIGHT - (float)(10 * zoom)) / 2 + TRANSLATION;
}
