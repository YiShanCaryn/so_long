/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yisho <yisho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:14:46 by yishan            #+#    #+#             */
/*   Updated: 2025/02/13 10:17:41 by yisho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		loop_end(data);
	}
	if (keysym == XK_w || keysym == XK_Up)
		render_top(data);
	if (keysym == XK_d || keysym == XK_Right)
		render_right(data);
	if (keysym == XK_a || keysym == XK_Left)
		render_left(data);
	if (keysym == XK_s || keysym == XK_Down)
		render_down(data);
	return (0);
}

void	process_move(t_data *data, int new_y, int new_x)
{
	if (data->map[new_y][new_x] == data->content.collect)
	{
		data->content.count_fish++;
		data->map[new_y][new_x] = data->content.floor;
		ft_printf("Fish collected! Total: %d/%d\n",
			data->content.count_fish, data->content.count_collect);
	}
	if (can_exit(data) && data->map[new_y][new_x] == data->content.exit)
	{
		win_game(data);
	}
	data->map[new_y][new_x] = data->content.player;
}

int	can_exit(t_data *data)
{
	if (data->content.count_fish == data->content.count_collect)
	{
		if (data->exitshowned == 0)
		{
			ft_printf("Exit unlocked! 🎉\n");
			data->exitshowned = 1;
		}
		return (1);
	}
	else
		return (0);
}

int	win_game(t_data *data)
{
	if (can_exit(data)
		&& data->map[data->pos.y][data->pos.x] == data->content.exit)
	{
		ft_printf("Game Over!🎉 You Win! 🎉\n");
		data->game_won = 1;
	}
	return (0);
}

void	display_win_message(t_data *data)
{
	if (data->game_won == 1)
	{
		mlx_clear_window(data->mlx_ptr, data->mlx_win);
		mlx_string_put(data->mlx_ptr, data->mlx_win,
			400, 200, 0xFFFFFF, "YOU WIN!");
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
			data->img.img_unlock, 100, 100);
		data->game_won = 2;
	}
}
