/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omadali <omadali@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 20:16:54 by omadali           #+#    #+#             */
/*   Updated: 2025/03/03 21:56:37 by omadali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_horizontal_lines(t_data *data, int y)
{
	int		x;
	t_point	p1;
	t_point	p2;

	x = 0;
	while (x < data->map->width - 1)
	{
		p1 = (t_point){x, y, data->map->z_values[y][x],
			data->map->colors[y][x]};
		p2 = (t_point){x + 1, y, data->map->z_values[y][x + 1],
			data->map->colors[y][x + 1]};
		draw_line_between_points(data, p1, p2);
		x++;
	}
}

void	draw_vertical_lines(t_data *data, int x)
{
	int		y;
	t_point	p1;
	t_point	p2;

	y = 0;
	while (y < data->map->height - 1)
	{
		p1 = (t_point){x, y, data->map->z_values[y][x],
			data->map->colors[y][x]};
		p2 = (t_point){x, y + 1, data->map->z_values[y + 1][x],
			data->map->colors[y + 1][x]};
		draw_line_between_points(data, p1, p2);
		y++;
	}
}

void	draw_map(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->map->height)
	{
		draw_horizontal_lines(data, y);
		y++;
	}
	x = 0;
	while (x < data->map->width)
	{
		draw_vertical_lines(data, x);
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->image, 0, 0);
}

int	count_words(char *line, char a)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] != a && (line[i + 1] == a || line[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}
