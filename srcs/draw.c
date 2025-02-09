/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omadali <omadali@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 20:15:54 by omadali           #+#    #+#             */
/*   Updated: 2025/02/09 21:40:19 by omadali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_data *data, t_point p1, t_point p2)
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;

	dx = abs(p2.x - p1.x);
	dy = abs(p2.y - p1.y);
	sx = (p1.x < p2.x) ? 1 : -1;
	sy = (p1.y < p2.y) ? 1 : -1;
	err = dx - dy;
	while (1)
	{
		mlx_pixel_put(data->mlx, data->win, p1.x, p1.y, COLOR);
		if (p1.x == p2.x && p1.y == p2.y)
			break;
		e2 = 2 * err;
		if (e2 > -dy)
		{
			err -= dy;
			p1.x += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			p1.y += sy;
		}
	}
}

void	draw_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map->height)
	{
		x = 0;
		while (x < data->map->width)
		{
			if (x < data->map->width - 1)
				draw_line(data, (t_point){x * 30, y * 30, data->map->z_values[y][x], COLOR},
						(t_point){(x + 1) * 30, y * 30, data->map->z_values[y][x + 1], COLOR});
			if (y < data->map->height - 1)
				draw_line(data, (t_point){x * 30, y * 30, data->map->z_values[y][x], COLOR},
						(t_point){x * 30, (y + 1) * 30, data->map->z_values[y + 1][x], COLOR});
			x++;
		}
		y++;
	}
}