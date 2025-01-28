/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yishan <yishan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:40:23 by yishan            #+#    #+#             */
/*   Updated: 2025/01/27 21:12:08 by yishan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "libft/ft_printf.h"
# include "mlx_linux/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_count
{
	int		count_player;
	int		count_exit;
	int		count_collect;
	char	exit;
	char	collect;
	char	player;
	char	wall;
	char	space;
}				t_count;

typedef struct s_img
{
	char	*player;
	char	*floor;
	char	*wall;
	char	*collect;
	char	*exit;
	void	*img_floor;
	void	*img_player;
	void	*img_exit;
	void	*img_wall;
	void	*img_collect;
	int		height;
	int		width;
}				t_img;

typedef struct s_pos
{
	int			i;
	int			j;
}				t_pos;

typedef struct s_data
{
	int		width;
	int		height;
	int		count;
	char	**map;
	void	*mlx_pointer;
	void	*mlx_window;
	t_count	content;
	t_img	img;
	t_pos	pos;
}				t_data;

//map
char	**parse_map(char *path, t_data *data);
void	ft_check_map(t_data *data);
int		ft_check_format(char **map);
int		ft_check_top_bottom(char *row);
int		ft_check_sides(char **map);
int		ft_check_valid_chars(char **map);

//utils
void	check_content(t_count *content);
void	ft_freemap(t_data *data);
int		close_window(t_data *data);


#endif