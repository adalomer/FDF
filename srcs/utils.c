/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omadali <omadali@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 20:16:54 by omadali           #+#    #+#             */
/*   Updated: 2025/02/18 22:59:12 by omadali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	cleanup(t_data *data)
{
	int	y;

	if (data->map)
	{
		y = 0;
		while (y < data->map->height)
		{
			free(data->map->z_values[y]);
			y++;
		}
		free(data->map->z_values);
		free(data->map);
	}
	if (data->image)
		mlx_destroy_image(data->mlx, data->image);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	exit(1);
}

int	ft_atoi(const char *a)
{
	int	b;
	int	c;
	int	d;

	b = 0;
	c = 1;
	d = 0;
	while ((a[b] >= 9 && a[b] <= 13) || a[b] == 32)
		b++;
	if (a[b] == '-')
	{
		c = -1;
		b++;
	}
	else if (a[b] == '+')
		b++;
	while (a[b] >= '0' && a[b] <= '9')
	{
		d = d * 10 + (a[b] - '0');
		b++;
	}
	return (d * c);
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
