/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omadali <omadali@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 20:14:49 by omadali           #+#    #+#             */
/*   Updated: 2025/03/05 02:50:17 by omadali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int	checker(char **str)
{
	int		len;
	int		fd;

	if (!str[1])
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	len = ft_strlen(str[1]);
	if (len < 4 || ft_strcmp(&str[1][len - 4], ".fdf") != 0)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	fd = open(str[1], O_RDONLY);
	if (fd == -1)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	close(fd);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	checker(argv);
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
		cleanup(&data);
	draw_map(&data);
	mlx_hook(data.win, 2, 1L << 0, handle_key, &data);
	mlx_hook(data.win, 17, 0, handle_close, &data);
	mlx_loop(data.mlx);
	return (0);
}
