/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omadali <omadali@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 20:15:18 by omadali           #+#    #+#             */
/*   Updated: 2025/02/17 00:54:13 by omadali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	count_words(char *line, char delimiter)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] != delimiter && (line[i + 1] == delimiter || line[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

void    fill_z_values(t_map *map, char *line, int y)
{
	char	**split;
	int		x;

	split = ft_split(line, ' ');
	x = 0;
	while (split[x])
	{
		map->z_values[y][x] = ft_atoi(split[x]);
		free(split[x]);
		x++;
	}
	free(split);
}

int	read_map(char *file, t_map *map)
{
	int		fd;
	char	*line;
	int		y;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);

	// Allocate memory for z_values
	map->z_values = (int **)malloc(sizeof(int *) * 1000); // Temporary size, adjust as needed // düzelt
	if (!map->z_values)
		return (0);

	y = 0;
	while ((line = get_next_line(fd)) != NULL)  // Correct usage of get_next_line
	{
		if (y == 0)
			map->width = count_words(line, ' ');

		// Allocate memory for each row
		map->z_values[y] = (int *)malloc(sizeof(int) * map->width);
		if (!map->z_values[y])
			return (0);

		fill_z_values(map, line, y);
		free(line);
		y++;
	}
	map->height = y;
	close(fd);
	return (1);
}