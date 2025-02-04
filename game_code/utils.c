/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yisho <yisho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:31:21 by yishan            #+#    #+#             */
/*   Updated: 2025/02/04 16:17:38 by yisho            ###   ########.fr       */
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

int	key_press(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_loop_end(data->mlx_ptr);
	}
	/*if (keysym == XK_w)
		render_top(data);
	if (keysym == XK_d)
		render_right(data);
	if (keysym == XK_a)
		render_left(data);
	if (keysym == XK_s)
		render_down(data);*/
	return (0);
}
