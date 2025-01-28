/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yishan <yishan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:07:45 by yishan            #+#    #+#             */
/*   Updated: 2025/01/27 21:10:32 by yishan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		ft_printf("Error\nThis programe take 1 argument .ber\n");
		return (0);
	}
	ft_bzero(&data, sizeof(t_data));
	data.mlx_pointer = mlx_init();
	check_content(&(data.content));
	data.map = parse_map(argv[1], &data);
	if (data.map != NULL)
	{
		
	}
	else
		close_window(&data);
	return (0);
}
