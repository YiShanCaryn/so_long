/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yishan <yishan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:31:21 by yishan            #+#    #+#             */
/*   Updated: 2025/02/06 13:14:33 by yishan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_freemap(t_data *data)
{
	int	i;

	if (data->map == NULL)
		return ;
	i = 0;
	while (data->map[i] != NULL)
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	data->map = NULL;
}

void	destroy_textures(t_data *data, void **image)
{
	if (image && *image)
	{
		mlx_destroy_image(data->mlx_ptr, *image);
		*image = NULL;
	}
}

void	clear_game(t_data *data)
{
	destroy_textures(data, &(data->img.img_wall));
	destroy_textures(data, &(data->img.img_floor));
	destroy_textures(data, &(data->img.img_collect));
	destroy_textures(data, &(data->img.img_player));
	destroy_textures(data, &(data->img.img_exit));
	if (data->mlx_win)
	{
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		data->mlx_win = NULL;
	}
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		data->mlx_ptr = NULL;
	}
	ft_freemap(data);
}

int	loop_end(t_data *data)
{
	if (data->mlx_ptr != NULL)
	{
		mlx_loop_end(data->mlx_ptr);
	}
	return (0);
}
