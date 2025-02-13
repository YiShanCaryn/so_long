/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_reader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yisho <yisho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:06:36 by yisho             #+#    #+#             */
/*   Updated: 2025/02/13 15:41:49 by yisho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_tile(t_data *data, int x, int y)
{
	if (data->map[y][x] == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
			data->img.img_wall, x * IMG_SIZE, y * IMG_SIZE);
	else if (data->map[y][x] == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
			data->img.img_floor, x * IMG_SIZE, y * IMG_SIZE);
	else if (data->map[y][x] == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
			data->img.img_collect, x * IMG_SIZE, y * IMG_SIZE);
	else if (data->map[y][x] == 'P')
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
			data->img.img_player, x * IMG_SIZE, y * IMG_SIZE);
	else if (data->map[y][x] == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
			data->img.img_exit, x * IMG_SIZE, y * IMG_SIZE);
}

int	render_loop(t_data *data)
{
	int		x;
	size_t	y;

	x = 0;
	y = 0;
	if (data->game_won >= 1)
	{
		display_win_message(data);
		return (0);
	}
	while (data->map[y])
	{
		while (data->map[y][x] && data->map[y][x] != '\n')
		{
			draw_tile(data, x, y);
			x++;
		}
		x = 0;
		y++;
	}
	return (1);
}

void	loop_images(t_data data)
{
	mlx_loop_hook(data.mlx_ptr, &render_loop, &data);
	mlx_hook(data.mlx_win, 2, 1L >> 0, &key_press, &data);
	mlx_hook(data.mlx_win, 17, 0, loop_end, &data);
	mlx_loop(data.mlx_ptr);
}

static void	window_size(t_data *data)
{
	int	i;

	if (!data->map || !data->map[0])
	{
		ft_printf("Error\n Map is invalid or empty.\n");
		clear_game(data);
	}
	data->width = ft_strlen(data->map[0]) * IMG_SIZE;
	i = 0;
	while (data->map[i] != NULL)
		i++;
	data->height = i * IMG_SIZE;
}

void	init_window(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
	{
		ft_printf("Error: Failed to initialize MLX.\n");
		clear_game(data);
		exit(1);
	}
	window_size(data);
	data->mlx_win = mlx_new_window(data->mlx_ptr,
			data->width, data->height, "So_long");
	if (!data->mlx_win)
	{
		ft_printf("Error: Failed to create window\n");
		clear_game(data);
		exit(1);
	}
}
