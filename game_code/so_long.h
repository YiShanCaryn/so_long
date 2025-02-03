/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yishan <yishan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:40:23 by yishan            #+#    #+#             */
/*   Updated: 2025/02/03 13:51:59 by yishan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../libft/ft_printf.h"
# include "../mlx_linux/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define IMG_SIZE 60
# define FLOOR "game_images/tile.xpm"
# define WALL "game_images/wall.xpm"
# define COLLECT "game_images/collect.xpm"
# define PLAYER "game_images/player.xpm"
# define EXIT "game_images/exit.xpm"

typedef struct s_count
{
	int		count_player;
	int		count_exit;
	int		count_collect;
	char	exit;
	char	collect;
	char	player;
	char	wall;
	char	floor;
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
	int			x;
	int			y;
}				t_pos;

typedef struct s_data
{
	int		width;
	int		height;
	int		count_steps;
	char	**map;
	void	*mlx_ptr;
	void	*mlx_win;
	t_count	content;
	t_img	img;
	t_pos	pos;
}				t_data;

//map
char	**parse_map(char *path, t_data *data);
int		ft_check_map(t_data *data);
int		ft_check_format(char **map);
int		ft_check_top_bottom(char *row);
int		ft_check_sides(char **map);
int		ft_check_valid_chars(char **map);

//core
void	init_window(t_data *data);
void	loop_images(t_data data);
int		render_loop(t_data *data);
void	draw_tile(t_data *data, int width, int x, int y);
/*void 	render_top(t_data *data);
void 	render_right(t_data *data);
void 	render_left(t_data *data);
void 	render_down(t_data *data);*/

//setting
void	init_player(t_data *data);
void	check_content(t_count *content);
void	set_img(t_data *data);

//utils
void	ft_freemap(t_data *data);
void	destroy_window(t_data *data);
void	close_window(t_data *data);
int		key_press(int keysym, t_data *data);

#endif