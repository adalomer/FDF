/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_memory.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omadali <omadali@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 20:15:18 by omadali           #+#    #+#             */
/*   Updated: 2025/03/03 22:00:44 by omadali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	free_allocated_memory(t_map *map, int i)
{
	while (i > 0)
	{
		i--;
		free(map->z_values[i]);
		free(map->colors[i]);
	}
	free(map->z_values);
	free(map->colors);
}

static int	allocate_row(t_map *map, int i)
{
	map->z_values[i] = (int *)malloc(sizeof(int) * map->width);
	map->colors[i] = (int *)malloc(sizeof(int) * map->width);
	if (!map->z_values[i] || !map->colors[i])
		return (0);
	return (1);
}

int	allocate_z_values(t_map *map)
{
	int	i;

	map->z_values = (int **)malloc(sizeof(int *) * map->height);
	map->colors = (int **)malloc(sizeof(int *) * map->height);
	if (!map->z_values || !map->colors)
		return (0);
	i = 0;
	while (i < map->height)
	{
		if (!allocate_row(map, i))
		{
			free_allocated_memory(map, i);
			return (0);
		}
		i++;
	}
	return (1);
}

void	free_map_values(t_map *map)
{
	int	i;

	i = 0;
	if (map->z_values)
	{
		while (i < map->height)
		{
			if (map->z_values[i])
				free(map->z_values[i]);
			i++;
		}
		free(map->z_values);
	}
	if (map->colors)
	{
		while (i < map->height)
		{
			if (map->colors[i])
				free(map->colors[i]);
			i++;
		}
		free(map->colors);
	}
	map->z_values = NULL;
	map->colors = NULL;
}
