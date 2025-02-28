/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omadali <omadali@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 01:48:19 by omadali           #+#    #+#             */
/*   Updated: 2025/02/28 15:39:05 by omadali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	cleanup(t_data *data)
{
	int	y;

	if (data->map)
	{
		y = 0;
		while (data->map->z_values[y])
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
