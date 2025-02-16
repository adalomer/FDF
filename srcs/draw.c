/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omadali <omadali@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 20:15:54 by omadali           #+#    #+#             */
/*   Updated: 2025/02/17 02:40:23 by omadali          ###   ########.fr       */
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
	int	pixel;

	dx = abs(p2.x - p1.x);
	dy = abs(p2.y - p1.y);
	sx = (p1.x < p2.x) ? 1 : -1;
	sy = (p1.y < p2.y) ? 1 : -1;
	err = dx - dy;
	while (1)
	{
		if ((p1.x < WIDTH && p1.x >= 0) && (p1.y < HEIGHT && p1.y >= 0))
		{
			pixel = (p1.y * data->len) + (p1.x * (data->bit / 8));
			*(unsigned int*)(data->img + pixel) = COLOR;
		}
		if (p1.x == p2.x && p1.y == p2.y)
			break;
		e2 = err;
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

t_point	project(t_point p, t_data *data)
{
	t_point	projected;
	float	angle;
	float	scale;

	angle = 0.523599; // 30 degrees in radians (π/6)

	// Calculate scale based on map size
	scale = fmin((float)WIDTH / (data->map->width * 2), (float)HEIGHT / (data->map->height * 2));
	scale = fmin(scale, 20.0f); // Limit the maximum scale

	// Center the map
	p.x -= (data->map->width / 2);
	p.y -= (data->map->height / 2);

	// Apply isometric projection
	projected.x = (p.x - p.y) * cos(angle) * scale + WIDTH / 2;
	projected.y = (p.x + p.y) * sin(angle) * scale - p.z * (scale / 3.5) + HEIGHT / 2;

	return (projected);
}

void	draw_map(t_data *data)
{
	int		x;
	int		y;
	t_point	p1;
	t_point	p2;

	y = 0;
	while (y < data->map->height)
	{
		x = 0;
		while (x < data->map->width)
		{
			if (x < data->map->width - 1)
			{
				p1 = (t_point){x, y, data->map->z_values[y][x], COLOR};
				p2 = (t_point){x + 1, y, data->map->z_values[y][x + 1], COLOR};
				p1 = project(p1, data);
				p2 = project(p2, data);
				draw_line(data, p1, p2);
			}
			if (y < data->map->height - 1)
			{
				p1 = (t_point){x, y, data->map->z_values[y][x], COLOR};
				p2 = (t_point){x, y + 1, data->map->z_values[y + 1][x], COLOR};
				p1 = project(p1, data);
				p2 = project(p2, data);
				draw_line(data, p1, p2);
			}
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->image, 0, 0);
}
