/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yishan <yishan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:31:21 by yishan            #+#    #+#             */
/*   Updated: 2025/01/27 21:13:15 by yishan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_freemap(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i] != NULL)
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	data->map = NULL;
}

int	close_window(t_data *data)
{
	int		i;

	i = 0;
	if (data->map != NULL)
	{
		while (data->map[i] != NULL)
		{
			free(data->map[i]);
			i++;
		}
		free(data->map);
		mlx_destroy_image(data->mlx_pointer, data->img.img_wall);
		mlx_destroy_image(data->mlx_pointer, data->img.img_floor);
		mlx_destroy_image(data->mlx_pointer, data->img.img_collect);
		mlx_destroy_image(data->mlx_pointer, data->img.img_player);
		mlx_destroy_image(data->mlx_pointer, data->img.img_exit);
		mlx_destroy_window(data->mlx_pointer, data->mlx_window);
	}
	mlx_destroy_display(data->mlx_pointer);
	free(data->mlx_pointer);
	exit(0);
}
