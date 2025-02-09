/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omadali <adalomer60@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 12:00:19 by omadali           #+#    #+#             */
/*   Updated: 2024/11/10 12:08:59 by omadali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

char	*ft_get_slice(char *cake)
{
	int		i;
	char	*slice;

	i = 0;
	if (!cake[i])
		return (NULL);
	while (cake[i] && cake[i] != '\n')
		i++;
	slice = (char *)malloc(sizeof(char) * (i + 2));
	if (!slice)
		return (NULL);
	i = 0;
	while (cake[i] && cake[i] != '\n')
	{
		slice[i] = cake[i];
		i++;
	}
	if (cake[i] == '\n')
	{
		slice[i] = cake[i];
		i++;		
	}
	slice[i] = '\0';
	return (slice);
}

char	*ft_get_leftover(char *cake)
{
	int		i;
	int		j;
	char	*new_cake;

	i = 0;
	while (cake[i] && cake[i] != '\n')
		i++;
	if (!cake[i])
	{
		free(cake);
		return (NULL);
	}
	new_cake = (char *)malloc(sizeof(char) * (ft_strlen(cake) - i + 1));
	if (!new_cake)
		return (NULL);
	i++;
	j = 0;
	while (cake[i])
		new_cake[j++] = cake[i++];
	new_cake[j] = '\0';
	free(cake);
	return (new_cake);
}
char	*ft_make_cake(int fd, char *cake)
{
	char	*new_slice;
	int		slice_len;

	new_slice = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!new_slice)
		return (NULL);
	slice_len = 1;
	while (!ft_strchr(cake) && slice_len != 0)
	{
		slice_len = read(fd, new_slice, BUFFER_SIZE);
		if (slice_len == -1)
		{
			free(new_slice);
			return (NULL);
		}
		new_slice[slice_len] = '\0';
		cake = ft_strjoin(cake, new_slice);
	}
	free(new_slice);
	return (cake);
}

char	*get_next_line(int fd)
{
	char		*slice;
	static char	*cake;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	cake = ft_make_cake(fd, cake);
	if (!cake)
		return (NULL);
	slice = ft_get_slice(cake);
	cake = ft_get_leftover(cake);
	return (slice);
}
