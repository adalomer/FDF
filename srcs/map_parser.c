/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omadali <omadali@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 20:15:18 by omadali           #+#    #+#             */
/*   Updated: 2025/02/18 02:28:56 by omadali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

void	fill_z_values(t_map *map, char *line, int y)
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

int	open_map_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	return (fd);
}

int	allocate_z_values(t_map *map)
{
	map->z_values = (int **)malloc(sizeof(int *) * 1000);
	if (!map->z_values)
		return (0);
	return (1);
}

int	process_lines(int fd, t_map *map)
{
	char	*line;
	int		y;

	y = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (y == 0)
			map->width = count_words(line, ' ');
		map->z_values[y] = (int *)malloc(sizeof(int) * map->width);
		if (!map->z_values[y])
			return (0);
		fill_z_values(map, line, y);
		free(line);
		y++;
		line = get_next_line(fd);
	}
	map->height = y;
	close(fd);
	return (1);
}

int	read_map(char *file, t_map *map)
{
	int		fd;

	fd = open_map_file(file);
	if (fd < 0)
		return (0);
	if (!allocate_z_values(map))
		return (0);
	return (process_lines(fd, map));
}

