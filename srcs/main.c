/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omadali <omadali@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 20:14:49 by omadali           #+#    #+#             */
/*   Updated: 2025/02/12 00:19:15 by omadali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

	// Create image
	data.image = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.img = mlx_get_data_addr(data.image, &data.bit, &data.len, &data.endian);

	// Read the map
	if (!read_map(argv[1], data.map))
	{
		cleanup(&data);
		return (1);
	}

	// Draw the map
	draw_map(&data);

	// Set up key press event hook
	mlx_hook(data.win, 2, 1L << 0, handle_key, &data); // 2 = KeyPress event, 1L << 0 = KeyPressMask

	// Start the event loop
	mlx_loop(data.mlx);

	return (0);
}