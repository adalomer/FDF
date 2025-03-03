/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omadali <omadali@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 20:14:49 by omadali           #+#    #+#             */
/*   Updated: 2025/03/03 21:51:44 by omadali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	cleanup1(t_data *data)
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
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		write(1, "Usage: ./fdf <map_file>\n", 24);
		return (1);
	}
	data.map = (t_map *)malloc(sizeof(t_map));
	if (!data.map)
	{
		write(1, "Memory allocation failed\n", 25);
		return (1);
	}
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "FDF");
	data.image = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.img = mlx_get_data_addr(data.image, &data.bit, &data.len, &data.edn);
	if (!read_map(argv[1], data.map))
		cleanup1(&data);
	draw_map(&data);
	mlx_hook(data.win, 2, 1L << 0, handle_key, &data);
	mlx_hook(data.win, 17, 0, cleanup1, &data);
	mlx_loop(data.mlx);
	return (0);
}
