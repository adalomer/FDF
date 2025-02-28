/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omadali <omadali@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 20:13:42 by omadali           #+#    #+#             */
/*   Updated: 2025/02/28 15:35:25 by omadali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "get_next_line.h"
# include "../minilibx-linux/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

# define WIDTH 1500
# define HEIGHT 900
# define COLOR 0xFFFFFF

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;

typedef struct s_map
{
	int	width;
	int	height;
	int	**z_values;
	int	row;
	int	z_max;
	int	**colors;
}	t_map;

typedef struct s_data
{
	void	*mlx;
	void	*image;
	char	*img;
	void	*win;
	int		len;
	int		edn;
	int		bit;
	t_map	*map;
}	t_data;

typedef struct s_bresenham
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
}	t_bresenham;

int		read_map(char *file, t_map *map);
void	draw_line(t_data *data, t_point p1, t_point p2);
void	draw_map(t_data *data);
int		handle_key(int keycode, t_data *data);
void	cleanup(t_data *data);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *a);
void	draw_pixel(t_data *data, t_point p);
void	update_error(t_point *p1, t_bresenham *bres);
void	draw_horizontal_line(t_data *data, int x, int y);
void	draw_vertical_line(t_data *data, int x, int y);
t_point	project(t_point p, t_data *data);
void	draw_map(t_data *data);
void	draw_line_between_points(t_data *data, t_point p1, t_point p2);
int		count_words(char *line, char a);

#endif