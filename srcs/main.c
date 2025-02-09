/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omadali <omadali@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 20:14:49 by omadali           #+#    #+#             */
/*   Updated: 2025/02/09 21:22:47 by omadali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		write(1, "Usage: ./fdf <map_file>\n", 24);
		return (1);
	}

	// Allocate memory for the map
	data.map = (t_map *)malloc(sizeof(t_map));
	if (!data.map)
	{
		write(1, "Memory allocation failed\n", 25);
		return (1);
	}

	// Initialize MiniLibX
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "FdF");

	// Read the map
	if (!read_map(argv[1], data.map))
	{
		cleanup(&data);
		return (1);
	}

	// Draw the map and start the event loop
	draw_map(&data);
	mlx_key_hook(data.win, handle_key, &data);
	mlx_loop(data.mlx);

	return (0);
}