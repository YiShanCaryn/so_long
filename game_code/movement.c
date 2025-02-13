/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yisho <yisho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:23:18 by yishan            #+#    #+#             */
/*   Updated: 2025/02/13 11:40:04 by yisho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_top(t_data *data)
{
	int	pos_x;
	int	pos_y;

	pos_x = data->pos.x;
	pos_y = data->pos.y;
	if (data->game_won >= 1)
		return ;
	if (data->map[pos_y - 1][pos_x] == data->content.exit)
	{
		if (!can_exit(data))
		{
			ft_printf("Eat fish first!\nYou have %d left.\n",
				data->content.count_collect - data->content.count_fish);
			return ;
		}
	}
	if (data->map[pos_y - 1][pos_x] != data->content.wall)
	{
		data->map[pos_y][pos_x] = data->content.floor;
		data->pos.y -= 1;
		process_move(data, data->pos.y, data->pos.x);
		data->count_steps++;
		ft_printf("Step count: %d\n", data->count_steps);
	}
}

void	render_right(t_data *data)
{
	int	pos_x;
	int	pos_y;

	if (data->game_won >= 1)
		return ;
	pos_x = data->pos.x;
	pos_y = data->pos.y;
	if (data->map[pos_y][pos_x + 1] == data->content.exit)
	{
		if (!can_exit(data))
		{
			ft_printf("Eat fish first!\nYou have %d left.\n",
				data->content.count_collect - data->content.count_fish);
			return ;
		}
	}
	if (data->map[pos_y][pos_x + 1] != data->content.wall)
	{
		data->map[pos_y][pos_x] = data->content.floor;
		data->pos.x += 1;
		process_move(data, data->pos.y, data->pos.x);
		data->count_steps++;
		printf("Step count: %d\n", data->count_steps);
	}
}

void	render_left(t_data *data)
{
	int	pos_x;
	int	pos_y;

	pos_x = data->pos.x;
	pos_y = data->pos.y;
	if (data->game_won >= 1)
		return ;
	if (data->map[pos_y][pos_x - 1] == data->content.exit)
	{
		if (!can_exit(data))
		{
			ft_printf("Eat fish first!\nYou have %d left.\n",
				data->content.count_collect - data->content.count_fish);
			return ;
		}
	}
	if (data->map[pos_y][pos_x - 1] != data->content.wall)
	{
		data->map[pos_y][pos_x] = data->content.floor;
		data->pos.x -= 1;
		process_move(data, data->pos.y, data->pos.x);
		data->count_steps++;
		printf("Step count: %d\n", data->count_steps);
	}
}

void	render_down(t_data *data)
{
	int	pos_x;
	int	pos_y;

	pos_x = data->pos.x;
	pos_y = data->pos.y;
	if (data->game_won >= 1)
		return ;
	if (data->map[pos_y + 1][pos_x] == data->content.exit)
	{
		if (!can_exit(data))
		{
			ft_printf("Eat fish first!\nYou have %d left.\n",
				data->content.count_collect - data->content.count_fish);
			return ;
		}
	}
	if (data->map[pos_y + 1][pos_x] != data->content.wall)
	{
		data->map[pos_y][pos_x] = data->content.floor;
		data->pos.y += 1;
		process_move(data, data->pos.y, data->pos.x);
		data->count_steps++;
		printf("Step count: %d\n", data->count_steps);
	}
}
