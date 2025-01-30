/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yisho <yisho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 22:09:39 by yishan            #+#    #+#             */
/*   Updated: 2025/01/30 10:51:35 by yisho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_content(t_count *content)
{
	content->count_player = 0;
	content->count_exit = 0;
	content->count_collect = 0;
	content->exit = 'E';
	content->player = 'P';
	content->wall = '1';
	content->space = '0';
	content->collect = 'C';
}

void	set_img(t_data *data)
{
	data->img.height = 80;
	data->img.width = 160;
	data->img.floor = "./game_images/tile.xpm";
	data->img.wall = "./game_images/wall.xpm";
	data->img.collect = "./game_images/collect.xpm";
	data->img.player = "./game_images/player.xpm";
	data->img.exit = "./game_images/exit.xpm";
	data->img.img_wall = mlx_xpm_file_to_image(data->mlx_pointer,
			data->img.wall, &(data->img.width), &(data->img.height));
	data->img.img_floor = mlx_xpm_file_to_image(data->mlx_pointer,
			data->img.floor, &(data->img.width), &(data->img.height));
	data->img.img_exit = mlx_xpm_file_to_image(data->mlx_pointer,
			data->img.exit, &(data->img.width), &(data->img.height));
	data->img.img_collect = mlx_xpm_file_to_image(data->mlx_pointer,
			data->img.collect, &(data->img.width), &(data->img.height));
	data->img.img_player = mlx_xpm_file_to_image(data->mlx_pointer,
			data->img.player, &(data->img.width), &(data->img.height));
}
