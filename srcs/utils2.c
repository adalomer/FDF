/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omadali <adalomer60@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 01:48:19 by omadali           #+#    #+#             */
/*   Updated: 2025/02/27 09:51:52 by omadali          ###   ########.fr       */
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
int	ft_atoi_base(const char *str, int base)
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			result = result * base + (str[i] - '0');
		else if (str[i] >= 'A' && str[i] <= 'F')
			result = result * base + (str[i] - 'A' + 10);
		else if (str[i] >= 'a' && str[i] <= 'f')
			result = result * base + (str[i] - 'a' + 10);
		else
			break ;
		i++;
	}
	return (result);
}
