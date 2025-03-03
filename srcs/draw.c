/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omadali <omadali@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 20:15:54 by omadali           #+#    #+#             */
/*   Updated: 2025/03/03 21:59:53 by omadali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_data *data, t_point p1, t_point p2)
{
	t_bresenham	bres;

	bres.dx = abs(p2.x - p1.x);
	bres.dy = abs(p2.y - p1.y);
	if (p1.x < p2.x)
		bres.sx = 1;
	else
		bres.sx = -1;
	if (p1.y < p2.y)
		bres.sy = 1;
	else
		bres.sy = -1;
	bres.err = bres.dx - bres.dy;
	while (1)
	{
		draw_pixel(data, p1);
		if (p1.x == p2.x && p1.y == p2.y)
			break ;
		update_error(&p1, &bres);
	}
}

void	update_error(t_point *p1, t_bresenham *bres)
{
	int	e2;

	e2 = bres->err;
	if (e2 > -bres->dy)
	{
		bres->err -= bres->dy;
		p1->x += bres->sx;
	}
	if (e2 < bres->dx)
	{
		bres->err += bres->dx;
		p1->y += bres->sy;
	}
}

t_point	project(t_point p, t_data *data)
{
	t_point	projected;
	float	angle;
	float	scale;

	angle = 0.523599;
	scale = fmin((float)WIDTH / (data->map->width * 2),
			(float)HEIGHT / (data->map->height * 2));
	if (data->map->width <= 11 && data->map->height <= 11)
		scale = fmin(scale, 30.0f);
	else
		scale = fmin(scale, 20.0f);
	p.x -= (data->map->width / 2);
	p.y -= (data->map->height / 2);
	projected.x = (p.x - p.y) * cos(angle) * scale + WIDTH / 2;
	projected.y = (p.x + p.y) * sin(angle) * scale
		- p.z * (scale / 3.5) + HEIGHT / 2;
	projected.color = p.color;
	return (projected);
}

void	draw_pixel(t_data *data, t_point p)
{
	int	pixel;

	if ((p.x < WIDTH && p.x >= 0) && (p.y < HEIGHT && p.y >= 0))
	{
		pixel = (p.y * data->len) + (p.x * (data->bit / 8));
		*(unsigned int *)(data->img + pixel) = p.color;
	}
}

void	draw_line_between_points(t_data *data, t_point p1, t_point p2)
{
	p1.z = data->map->z_values[p1.y][p1.x];
	p2.z = data->map->z_values[p2.y][p2.x];
	if (data->map->colors)
	{
		p1.color = data->map->colors[p1.y][p1.x];
		p2.color = data->map->colors[p2.y][p2.x];
	}
	else
	{
		p1.color = COLOR;
		p2.color = COLOR;
	}
	p1 = project(p1, data);
	p2 = project(p2, data);
	draw_line(data, p1, p2);
}
