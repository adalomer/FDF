/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omadali <omadali@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 20:16:17 by omadali           #+#    #+#             */
/*   Updated: 2025/02/10 23:42:11 by omadali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include "fdf.h"

int	handle_key(int keycode, t_data *data)
{
	if (keycode == 65307) // ESC key
	{
		mlx_destroy_window(data->mlx, data->win);
		cleanup(data);
	}
	return (0);
}