/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakhoury <gakhoury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 10:10:12 by gakhoury          #+#    #+#             */
/*   Updated: 2024/08/19 13:14:53 by gakhoury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

float	ft_abs(float val)
{
	if (val < 0.0)
		return (-val);
	return (val);
}

int	ft_round(float val)
{
	if (val >= 0)
		return ((int)(val + 0.5f));
	else
		return ((int)(val - 0.5f));
}
