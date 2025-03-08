/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omadali <omadali@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 20:13:42 by omadali           #+#    #+#             */
/*   Updated: 2025/03/05 02:50:39 by omadali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "get_next_line.h"
# include "../minilibx-linux/mlx.h"

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
int		handle_key(int keycode, t_data *data);
void	cleanup(t_data *data);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *a);
void	draw_pixel(t_data *data, t_point p);
void	update_error(t_point *p1, t_bresenham *bres);
t_point	project(t_point p, t_data *data);
void	draw_map(t_data *data);
void	draw_line_between_points(t_data *data, t_point p1, t_point p2);
int		count_words(char *line, char a);
int		ft_atoi_base(const char *str, int base);
void	fill_z_values(t_map *map, char *line, int y);
int		open_map_file(char *file);
void	get_map_dimensions(char *file, t_map *map);
int		process_lines(int fd, t_map *map);
int		allocate_z_values(t_map *map);
void	free_map_values(t_map *map);
int		handle_close(t_data *data);

#endif