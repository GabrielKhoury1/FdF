/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakhoury <gakhoury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:09:48 by gakhoury          #+#    #+#             */
/*   Updated: 2024/08/26 10:17:43 by gakhoury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	close_window(t_map *map)
{
	free_map_components(map);
	cleanup(map);
	free(map->dst);
	free(map->mlx);
	free(map);
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc == 2)
	{
		map = malloc(sizeof(t_map));
		if (!map)
			handle_error(map, "Memory allocation failed\n");
		map->dst = (char *)malloc(sizeof(char) * (15 + ft_strlen(argv[1]) + 1));
		map->dst[0] = '\0';
		ft_strlcat(map->dst, "maps/", 6);
		ft_strlcat(map->dst, argv[1], 15 + ft_strlen(argv[1]) + 1);
		if (!init_map(map, map->dst))
			handle_error(map, "Initialization failed\n");
		draw_image(map);
		mlx_hook(map->win, 2, 1L << 0, key_hook, map);
		mlx_hook(map->win, 3, 1L << 1, key_release, map);
		mlx_hook(map->win, 17, 1L << 17, close_window, map);
		print_binds(map);
		mlx_loop(map->mlx);
		return (0);
	}
}
