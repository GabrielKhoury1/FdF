/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakhoury <gakhoury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:48:57 by gakhoury          #+#    #+#             */
/*   Updated: 2024/08/26 09:19:09 by gakhoury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

static int	has_digit(char *num)
{
	while (*num == ' ' || (*num >= 9 && *num <= 13))
		num++;
	if (*num >= '0' && *num <= '9')
		return (1);
	return (0);
}

void	read_file_into_grid(const char *filename, t_map *map)
{
	int		i;
	int		j;
	char	**numbers;

	i = 0;
	map->fd = open(filename, O_RDONLY);
	if (map->fd < 0)
		handle_error(map, "File not found\n");
	map->grid = (float **)malloc(sizeof(float *) * map->height);
	map->line = get_next_line(map->fd);
	while (map->line)
	{
		numbers = ft_split(map->line, ' ');
		if (!numbers)
			handle_error(map, "Split failure\n");
		map->grid[i] = (float *)malloc(sizeof(float) * map->width);
		j = 0;
		while (numbers[++j - 1])
			if (j - 1 < map->width)
				map->grid[i][map->width - j] = (float)ft_atoi(numbers[j - 1]);
		free(map->line);
		free_char_array(numbers);
		i++;
		map->line = get_next_line(map->fd);
	}
}

static void	get_coordinates_2(t_map *map, char **numbers, int j)
{
	int	i;
	int	count_cols;

	i = 0;
	while (numbers[i])
	{
		if (has_digit(numbers[i]))
			j++;
		i++;
	}
	count_cols = j;
	if (map->width < count_cols)
		map->width = count_cols;
}

void	get_coordinates(char *filename, t_map *map)
{
	int		i;
	int		j;
	char	**numbers;

	map->fd = open(filename, O_RDONLY);
	if (map->fd < 0)
		handle_error(map, "File not found\n");
	i = 0;
	map->line = get_next_line(map->fd);
	while (map->line)
	{
		j = 0;
		numbers = ft_split(map->line, ' ');
		if (!numbers)
			handle_error(map, "Split failure\n");
		get_coordinates_2(map, numbers, j);
		free(map->line);
		free_char_array(numbers);
		i++;
		map->line = get_next_line(map->fd);
	}
	map->height = i;
	close(map->fd);
}
