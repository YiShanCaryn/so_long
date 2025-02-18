/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yisho <yisho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:28:54 by yisho             #+#    #+#             */
/*   Updated: 2025/02/18 16:52:15 by yisho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**copy_map(t_data *data)
{
	char	**mapcopy;
	int		row;

	row = 0;
	while (data->map[row] != NULL)
		row++;
	mapcopy = malloc(sizeof(char *) * (row + 1));
	if (!mapcopy)
		return (NULL);
	row = 0;
	while (data->map[row] != NULL)
	{
		mapcopy[row] = ft_strdup(data->map[row]);
		row++;
	}
	mapcopy[row] = NULL;
	return (mapcopy);
}

void	flood(char **map, int y, int x)
{
	if (map[y][x] == '1' || map[y][x] == 'Z')
		return ;
	map[y][x] = 'Z';
	flood(map, y - 1, x);
	flood(map, y + 1, x);
	flood(map, y, x - 1);
	flood(map, y, x + 1);
}

void	ft_freecopymap(char	**mapcopy)
{
	int	i;

	if (mapcopy == NULL)
		return ;
	i = 0;
	while (mapcopy[i] != NULL)
	{
		free(mapcopy[i]);
		i++;
	}
	free(mapcopy);
}

static int	com_map(t_data *data, char	**mapcopy)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->map[y])
	{
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'E' && mapcopy[y][x] == 'E')
				return (0);
			else if (data->map[y][x] == 'C' && mapcopy[y][x] == 'C')
				return (0);
			x++;
		}
		x = 0;
		y++;
	}
	return (1);
}

int	path_valid(t_data *data)
{
	char	**mapcopy;
	int		result;

	mapcopy = copy_map(data);
	init_player(data);
	flood(mapcopy, data->pos.y, data->pos.x);
	result = com_map(data, mapcopy);
	ft_freecopymap(mapcopy);
	mapcopy = NULL;
	return (result);
}
