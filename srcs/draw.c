/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omadali <omadali@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 20:15:54 by omadali           #+#    #+#             */
/*   Updated: 2025/02/18 02:34:18 by omadali          ###   ########.fr       */
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

	dx = abs(p2.x - p1.x);
	dy = abs(p2.y - p1.y);
	if (p1.x < p2.x)
		sx = 1;
	else
		sx = -1;
	if (p1.y < p2.y)
		sy = 1;
	else
		sy = -1;
	err = dx - dy;
	while (1)
	{
		draw_pixel(data, p1);
		if (p1.x == p2.x && p1.y == p2.y)
			break ;
		update_error(&p1, sx, sy, &err, dx, dy);
	}
}

t_point	project(t_point p, t_data *data)
{
	t_point	projected;
	float	angle;
	float	scale;

	angle = 0.523599;
	scale = fmin((float)WIDTH / (data->map->width * 2), (float)HEIGHT / (data->map->height * 2));
	scale = fmin(scale, 20.0f);
	p.x -= (data->map->width / 2);
	p.y -= (data->map->height / 2);
	projected.x = (p.x - p.y) * cos(angle) * scale + WIDTH / 2;
	projected.y = (p.x + p.y) * sin(angle) * scale - p.z * (scale / 3.5) + HEIGHT / 2;
	return (projected);
}

void	draw_pixel(t_data *data, t_point p)
{
	int	pixel;

	if ((p.x < WIDTH && p.x >= 0) && (p.y < HEIGHT && p.y >= 0))
	{
		pixel = (p.y * data->len) + (p.x * (data->bit / 8));
		*(unsigned int *)(data->img + pixel) = COLOR;
	}
}

void	draw_line_between_points(t_data *data, int x1, int y1, int x2, int y2)
{
	t_point	p1;
	t_point	p2;

	p1 = (t_point){x1, y1, data->map->z_values[y1][x1], COLOR};
	p2 = (t_point){x2, y2, data->map->z_values[y2][x2], COLOR};
	p1 = project(p1, data);
	p2 = project(p2, data);
	draw_line(data, p1, p2);
}

void	update_error(t_point *p1, int sx, int sy, int *err, int dx, int dy)
{
	int	e2;

	e2 = *err;
	if (e2 > -dy)
	{
		*err -= dy;
		p1->x += sx;
	}
	if (e2 < dx)
	{
		*err += dx;
		p1->y += sy;
	}
}

void	draw_map(t_data *data)
{
	int		x;
	int		y;

	y = 0;
	while (y < data->map->height)
	{
		x = 0;
		while (x < data->map->width)
		{
			if (x < data->map->width - 1)
				draw_line_between_points(data, x, y, x + 1, y);
			if (y < data->map->height - 1)
				draw_line_between_points(data, x, y, x, y + 1);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->image, 0, 0);
}

