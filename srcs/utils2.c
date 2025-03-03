/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omadali <omadali@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 01:48:19 by omadali           #+#    #+#             */
/*   Updated: 2025/03/03 21:56:51 by omadali          ###   ########.fr       */
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
			free(data->map->colors[y]);
			y++;
		}
		free(data->map->z_values);
		free(data->map->colors);
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

static int	get_hex_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (-1);
}

int	ft_atoi_base(const char *str, int base)
{
	int	result;
	int	digit;
	int	i;

	result = 0;
	i = 0;
	if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
		i = 2;
	while (str[i])
	{
		digit = get_hex_digit(str[i]);
		if (digit == -1)
			break ;
		result = result * base + digit;
		i++;
	}
	return (result);
}
