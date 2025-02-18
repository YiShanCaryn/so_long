/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yisho <yisho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:28:54 by yisho             #+#    #+#             */
/*   Updated: 2025/02/18 16:35:47 by yisho            ###   ########.fr       */
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

int	path_valid(t_data *data)
{
	char	**mapcopy;

	mapcopy = copy_map(data);
	init_player(data);
	flood(mapcopy, data->pos.y, data->pos.x);
	
	//DEBUG
	int i = 0;
	int j = 0;
	while (mapcopy[i])
	{
		j = 0;
		while(mapcopy[i][j])
		{
			printf("%c", mapcopy[i][j]);
			j++;
		}
		printf ("\n");
		i++;
	}
	//DEBUG
	ft_freecopymap(mapcopy);
	mapcopy = NULL;
	return (1);
}
