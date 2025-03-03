/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dimensions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omadali <omadali@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 20:15:18 by omadali           #+#    #+#             */
/*   Updated: 2025/03/03 21:57:53 by omadali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_map_dimensions(char *file, t_map *map)
{
	int		fd;
	char	*line;
	int		y;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return ;
	y = 0;
	line = get_next_line(fd);
	if (line)
		map->width = count_words(line, ' ');
	while (line)
	{
		free(line);
		y++;
		line = get_next_line(fd);
	}
	map->height = y;
	close(fd);
}

int	process_lines(int fd, t_map *map)
{
	char	*line;
	int		y;

	y = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		fill_z_values(map, line, y);
		free(line);
		y++;
		line = get_next_line(fd);
	}
	close(fd);
	return (1);
}
