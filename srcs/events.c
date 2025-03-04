/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omadali <omadali@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 20:16:17 by omadali           #+#    #+#             */
/*   Updated: 2025/03/05 02:50:12 by omadali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_key(int keycode, t_data *data)
{
	if (keycode == 65307)
	{
		cleanup(data);
	}
	return (0);
}

int handle_close(t_data *data)
{
    cleanup(data);
    return (0);
}