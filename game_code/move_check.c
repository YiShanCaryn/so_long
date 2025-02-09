/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yishan <yishan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:14:46 by yishan            #+#    #+#             */
/*   Updated: 2025/02/08 13:34:15 by yishan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		loop_end(data);
	}
	if (keysym == XK_w)
		render_top(data);
	if (keysym == XK_d)
		render_right(data);
	if (keysym == XK_a)
		render_left(data);
	if (keysym == XK_s)
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
		ft_printf("Exit unlocked! 🎉\n");
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
		ft_printf("🎉 You Win! 🎉\n");
		clear_game(data);
		exit(0);
	}
	return (0);
}
