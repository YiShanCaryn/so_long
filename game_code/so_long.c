/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yishan <yishan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:07:45 by yishan            #+#    #+#             */
/*   Updated: 2025/02/08 13:13:22 by yishan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		ft_printf("Error\nThis programe take 1 argument .ber\n");
		return (0);
	}
	else
	{
		ft_bzero(&data, sizeof(t_data));
		check_content(&(data.content));
		data.map = parse_map(argv[1], &data);
		if (data.map != NULL)
		{
			init_player(&data);
			init_window(&data);
			set_img(&data);
			loop_images(data);
		}
		clear_game(&data);
	}
	return (0);
}
