/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omadali <omadali@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 20:15:18 by omadali           #+#    #+#             */
/*   Updated: 2025/02/18 22:58:37 by omadali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    fill_z_values(t_map *map, char *line, int y)
{
    char    **split;
    char    **color_split;
    int     x;

    split = ft_split(line, ' ');
    x = 0;
    while (split[x])
    {
        color_split = ft_split(split[x], ',');
        map->z_values[y][x] = ft_atoi(color_split[0]);
        if (color_split[1])
            map->colors[y][x] = ft_atoi_base(color_split[1], 16);
        else
            map->colors[y][x] = 0xFFFFFF;  // Varsayılan renk: beyaz
        free(color_split[0]);
        if (color_split[1])
            free(color_split[1]);
        free(color_split);
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

int    allocate_z_values(t_map *map)
{
    map->z_values = (int **)malloc(sizeof(int *) * 1000);
    map->colors = (int **)malloc(sizeof(int *) * 1000);  // Renk matrisi için bellek ayırma
    if (!map->z_values || !map->colors)
        return (0);
    return (1);
}

int    process_lines(int fd, t_map *map)
{
    char    *line;
    int     y;

    y = 0;
    line = get_next_line(fd);
    while (line != NULL)
    {
        if (y == 0)
            map->width = count_words(line, ' ');
        map->z_values[y] = (int *)malloc(sizeof(int) * map->width);
        map->colors[y] = (int *)malloc(sizeof(int) * map->width);  // Renk matrisi için bellek ayırma
        if (!map->z_values[y] || !map->colors[y])
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
