/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakhoury <gakhoury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 18:04:00 by gakhoury          #+#    #+#             */
/*   Updated: 2024/08/27 08:43:14 by gakhoury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H

// # include "../minilibx-linux/mlx.h"
# include "../Libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <limits.h>
# include <fcntl.h>

# define LIB_H
# define WIN_WIDTH	1600
# define WIN_HEIGHT	900
# define PANEL_HEIGHT 1600
# define PANEL_WIDTH 350
# define PANEL_COLOR 0x1E1E1E
# define ZOOM 5
# define TRANSLATION 2
# define ROTATION_INCREMENT 0.07
# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
}	t_point;

typedef struct s_map
{
	int		width;
	int		height;
	float	x_begin;
	float	y_begin;
	float	z_begin;
	float	**grid;
	void	*mlx;
	void	*win;
	void	*img;
	char	*data;
	int		bpp;
	int		size_line;
	int		endian;
	double	alpha;
	double	theta;
	double	gamma;
	t_point	*center;
	t_point	*current;
	t_point	*next;
	float	current_x;
	float	current_y;
	float	current_z;
	int		fd;
	char	*line;
	char	*dst;
	float	min_z;
	float	max_z;
	float	zoom;
	int		dir_1;
	int		dir_2;
	int		shift_pressed;
}t_map;

int		key_release(int keycode, t_map *map);
int		key_hook(int keycode, t_map *map);
int		init_map(t_map *map, char *filename);
int		init_mlx(t_map *map);
int		interpolate_color(int start_color, int end_color, float fraction);
int		ft_round(float val);
void	isometric(t_point *a);
void	init_center(t_map *map);
void	print_binds(t_map *map);
void	bresenham(t_map *map, t_point *a, t_point *b);
void	ft_increment(t_map *map);
void	ft_decrement(t_map *map);
void	draw_image(t_map *map);
void	free_char_array(char **array);
void	cleanup(t_map *map);
void	free_map_components(t_map *map);
void	free_grid(int **grid, int height);
void	put_pixel(t_map *map, int x, int y, int color);
void	get_coordinates(char *filename, t_map *map);
void	read_file_into_grid(const char *filename, t_map *map);
void	top_side_rotate(t_map *map);
void	front_side_rotate(t_map *map);
void	right_side_rotate(t_map *map);
void	top_side_rrotate(t_map *map);
void	front_side_rrotate(t_map *map);
void	right_side_rrotate(t_map *map);
void	apply_view(t_point *a, t_map *map);
void	scale_offset(t_point *a, float zoom);
void	translate(int translation, t_map *map, int keycode);
void	handle_error(t_map *map, const char *error_msg);
void	put_line(t_map *map, float x, float y);
float	ft_dx(t_point *a, t_point *b);
float	ft_dy(t_point *a, t_point *b);
float	ft_dz(t_map *map);
float	get_min_z(t_map *map);
float	get_max_z(t_map *map);
float	ft_fraction(float x1, float x2, float x);
float	ft_abs(float val);

#endif