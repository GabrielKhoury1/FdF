/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakhoury <gakhoury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 10:16:43 by gakhoury          #+#    #+#             */
/*   Updated: 2024/08/26 10:08:23 by gakhoury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	interpolate_color(int start_color, int end_color, float fraction)
{
	int	red;
	int	green;
	int	blue;

	red = ((start_color >> 16) & 0xFF) + fraction * (((end_color >> 16) & 0xFF)
			- ((start_color >> 16) & 0xFF));
	green = ((start_color >> 8) & 0xFF) + fraction * (((end_color >> 8) & 0xFF)
			- ((start_color >> 8) & 0xFF));
	blue = (start_color & 0xFF) + fraction * ((end_color & 0xFF) - (start_color
				& 0xFF));
	if (red < 0)
		red = 0;
	else if (red > 255)
		red = 255;
	if (green < 0)
		green = 0;
	else if (green > 255)
		green = 255;
	if (blue < 0)
		blue = 0;
	else if (blue > 255)
		blue = 255;
	return ((red << 16) | (green << 8) | blue);
}

float	ft_fraction(float x1, float x2, float x)
{
	float	temp;

	if (x1 > x2)
	{
		temp = x1;
		x1 = x2;
		x2 = temp;
	}
	if (x1 == x2)
	{
		if (x == x1)
			return (0);
		else
			return (0);
	}
	return ((x - x1) / (x2 - x1));
}
