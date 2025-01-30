/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yisho <yisho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:06:36 by yisho             #+#    #+#             */
/*   Updated: 2025/01/30 12:45:00 by yisho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	core_read(t_data *data)
{
	data->mlx_window = mlx_new_window(data->mlx_pointer,
			(data->width * data->img.width), (data->height * data->img.height),
			"So_long");
	if (data->mlx_window == NULL)
	{
		free(data->mlx_pointer);
		return ;
	}
	mlx_loop_hook(data->mlx_pointer, &render, data);
	mlx_hook(data->mlx_window, KeyRelease, KeyReleaseMask, &key_press, data);
	mlx_hook(data->mlx_window, 17, 0, &end, data);
	mlx_loop(data->mlx_pointer);
	end(data);
}
