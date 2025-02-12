/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omadali <omadali@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 20:13:42 by omadali           #+#    #+#             */
/*   Updated: 2025/02/11 23:31:40 by omadali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "get_next_line.h"
# include "mlx.h"
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
	int x;
	int y;
	int z;
	int color;
} t_point;

typedef struct s_map
{
	int width;
	int height;
	int **z_values;
	int **colors;
} t_map;

typedef struct s_data
{
	void *mlx;
	void *image;
	char *img;
	void *win;
	int len;
	int endian;
	int bit;
	t_map *map;
} t_data;

// Function prototypes
int		read_map(char *file, t_map *map);
void	draw_line(t_data *data, t_point p1, t_point p2);
void	draw_map(t_data *data);
int		handle_key(int keycode, t_data *data);
void	cleanup(t_data *data);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *a);

#endif