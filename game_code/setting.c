/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yishan <yishan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 22:09:39 by yishan            #+#    #+#             */
/*   Updated: 2025/02/08 13:12:03 by yishan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_player(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->map[x])
	{
		while (data->map[x][y])
		{
			if (data->map[x][y] == 'P')
			{
				data->pos.x = x;
				data->pos.y = y;
			}
			y++;
		}
		y = 0;
		x++;
	}
}

void	check_content(t_count *content)
{
	content->count_player = 0;
	content->count_exit = 0;
	content->count_collect = 0;
	content->count_fish = 0;
	content->exit = 'E';
	content->player = 'P';
	content->wall = '1';
	content->floor = '0';
	content->collect = 'C';
}

void	set_img_paths(t_data *data)
{
	data->img.height = IMG_SIZE;
	data->img.width = IMG_SIZE;
	data->img.floor = "./game_images/tile.xpm";
	data->img.wall = "./game_images/wall.xpm";
	data->img.collect = "./game_images/collect.xpm";
	data->img.player = "./game_images/player.xpm";
	data->img.exit = "./game_images/exit.xpm";
}

void	set_img(t_data *data)
{
	set_img_paths(data);
	data->img.img_wall = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.wall, &(data->img.width), &(data->img.height));
	data->img.img_floor = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.floor, &(data->img.width), &(data->img.height));
	data->img.img_exit = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.exit, &(data->img.width), &(data->img.height));
	data->img.img_collect = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.collect, &(data->img.width), &(data->img.height));
	data->img.img_player = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.player, &(data->img.width), &(data->img.height));
	if (!data->img.img_wall || !data->img.img_floor || !data->img.img_exit
		||!data->img.img_collect || !data->img.img_player)
	{
		ft_printf("Error\n Loading textures failed: %s.\n", strerror(errno));
		clear_game(data);
		exit (1);
	}
}
