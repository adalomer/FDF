/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_memory.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omadali <omadali@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 20:15:18 by omadali           #+#    #+#             */
/*   Updated: 2025/03/05 01:43:15 by omadali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

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
	{
		if (map->z_values[i])
			free(map->z_values[i]);
		if (map->colors[i])
			free(map->colors[i]);
		return (0);
	}
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

void	free_2d_array(void **array, int height)
{
	int	i;

	i = 0;
	if (array)
	{
		while (i < height)
		{
			if (array[i])
				free(array[i]);
			i++;
		}
		free(array);
	}
}

void	free_map_values(t_map *map)
{
	if (map->z_values)
	{
		free_2d_array((void **)map->z_values, map->height);
		map->z_values = NULL;
	}
	if (map->colors)
	{
		free_2d_array((void **)map->colors, map->height);
		map->colors = NULL;
	}
}
