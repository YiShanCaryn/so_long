/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yisho <yisho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:22:28 by yishan            #+#    #+#             */
/*   Updated: 2025/02/18 16:37:39 by yisho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	format_check(char *map_name)
{
	if (ft_strncmp(map_name + ft_strlen(map_name) - 4, ".ber", 4) != 0)
	{
		ft_printf("Error\nNo correct format map found\n");
		exit (1);
	}
}

int	close_map(char *line_map, char *tmp_buff, int fd)
{
	ft_printf("Error\nMap not valid.\n");
	if (line_map != NULL)
		free(line_map);
	if (tmp_buff != NULL)
		free(tmp_buff);
	line_map = get_next_line(fd);
	while (line_map)
	{
		free(line_map);
		line_map = get_next_line(fd);
	}
	close(fd);
	exit(1);
	return (0);
}

char	**map_read(char *map_name)
{
	char	*line_map;
	char	*buff;
	char	*tmp_buff;
	char	**map;
	int		fd;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		return (NULL);
	buff = ft_strdup("");
	line_map = get_next_line(fd);
	while (line_map)
	{
		tmp_buff = buff;
		if (line_map[0] == '\n')
			close_map(line_map, tmp_buff, fd);
		buff = ft_strjoin(buff, line_map);
		free(tmp_buff);
		free(line_map);
		line_map = get_next_line(fd);
	}
	close (fd);
	map = ft_split(buff, '\n');
	free(buff);
	return (map);
}

char	**parse_map(char *path, t_data *data)
{
	int	last_row;

	last_row = 0;
	data->map = map_read(path);
	if (!(ft_check_format(data->map)))
		return (ft_freemap(data), NULL);
	if (!(ft_check_valid_chars(data->map)))
		return (ft_freemap(data), NULL);
	if (!(ft_check_top_bottom(data->map[0])))
		return (ft_freemap(data), NULL);
	while (data->map[last_row + 1])
		last_row++;
	if (!(ft_check_top_bottom(data->map[last_row])))
		return (ft_freemap(data), NULL);
	if (!(ft_check_sides(data->map)))
		return (ft_freemap(data), NULL);
	if (!ft_check_map(data) || !path_valid(data))
	{
		ft_printf("Error\nNeed 1 Player/Exit/1 Object that are accessible\n");
		return (ft_freemap(data), NULL);
	}
	return (data->map);
}
