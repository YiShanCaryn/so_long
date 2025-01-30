/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yisho <yisho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:27:12 by yishan            #+#    #+#             */
/*   Updated: 2025/01/30 11:37:54 by yisho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_check_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i] != NULL)
	{
		j = 0;
		while (data->map[i][j] != '\0')
		{
			if (data->map[i][j] == data->content.player)
				data->content.count_player++;
			else if (data->map[i][j] == data->content.exit)
				data->content.count_exit++;
			else if (data->map[i][j] == data->content.collect)
				data->content.count_collect++;
			j++;
		}
		i++;
	}
	if ((data->content.count_collect < 0 || data->content.count_exit != 1
			|| data->content.count_player != 1))
	{
		ft_printf("Error\nNeed 1 Player/Exit and at least 1 Object\n");
		return ;
	}
}

int	ft_check_format(char **map)
{
	int		i;
	int		j;
	int		count_j;

	i = 0;
	j = 0;
	count_j = 0;
	while (map[0][count_j])
		count_j++;
	while (map[i] != NULL)
	{
		while (map[i][j])
			j++;
		if (j != count_j)
		{
			ft_printf("Error\nMap must be a rectangle or a square\n");
			return (0);
		}
		j = 0;
		i++;
	}
	return (1);
}

int	ft_check_top_bottom(char *row)
{
	int	x;

	x = 0;
	while (row[x] && row[x] != '\n')
	{
		if (row[x] != '1')
		{
			ft_printf("Error\nWall not properly enclosed on top/bottom\n");
			return (0);
		}
		x++;
	}
	return (1);
}

int	ft_check_sides(char **map)
{
	int	y;
	int	last_column;

	y = 0;
	last_column = ft_strlen(map[0]) - 1;
	while (map[y])
	{
		if (map[y][0] != '1' || map[y][last_column] != '1')
		{
			ft_printf("Error\nSide walls are not properly enclosed\n");
			return (0);
		}
		y++;
	}
	return (1);
}

int	ft_check_valid_chars(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] != '1' && map[y][x] != 'C' && map[y][x] != 'P' && \
				map[y][x] != 'E' && map[y][x] != '0')
			{
				ft_printf("Error\nInvalid map");
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}
