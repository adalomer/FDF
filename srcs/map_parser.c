/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omadali <omadali@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 20:15:18 by omadali           #+#    #+#             */
/*   Updated: 2025/03/05 01:30:35 by omadali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <unistd.h>
#include <fcntl.h>

void fill_z_values(t_map *map, char *line, int y)
{
	char	**split;
	char	**color_split;
	int		x;
	int		len;

	if (!line || !map)
		return;
	
	// Satır sonundaki boşlukları temizle
	len = ft_strlen(line);
	while (len > 0 && (line[len - 1] == ' ' || line[len - 1] == '\n'))
		line[--len] = '\0';

	split = ft_split(line, ' ');
	if (!split)
		return;

	// Önce tüm satırı 0 ve varsayılan renkle doldur
	x = 0;
	while (x < map->width)
	{
		map->z_values[y][x] = 0;
		map->colors[y][x] = COLOR;
		x++;
	}

	// Sonra gerçek değerleri oku
	x = 0;
	while (split[x] && x < map->width)
	{
		color_split = ft_split(split[x], ',');
		if (color_split)
		{
			map->z_values[y][x] = ft_atoi(color_split[0]);
			if (color_split[1])
				map->colors[y][x] = ft_atoi_base(color_split[1], 16);
			
			free(color_split[0]);
			if (color_split[1])
				free(color_split[1]);
			free(color_split);
		}
		free(split[x]);
		x++;
	}
	free(split);
}

int	open_map_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	return (fd);
}

int	read_map(char *file, t_map *map)
{
	int	fd;

	get_map_dimensions(file, map);
	if (map->width <= 0 || map->height <= 0)
		return (0);
	if (!allocate_z_values(map))
		return (0);
	fd = open_map_file(file);
	if (fd < 0)
		return (0);
	return (process_lines(fd, map));
}
