/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 20:38:24 by echrysta          #+#    #+#             */
/*   Updated: 2022/02/17 20:38:26 by echrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libmlx/mlx.h"
# include "../get_next_line/get_next_line.h"

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_for_mlx
{
	void	*mlx;
	void	*win;
}	t_for_mlx;

typedef struct s_map_data_game
{
	int			map_height;
	int			map_length;
	int			player_pos_x;
	int			player_pos_y;
	int			score;
	int			max_score;
	char		**arr_map;
	int			game_over;
	int			steps;
	void		*wall;
	void		*floor;
	void		*exit;
	void		*player;
	void		*player_up;
	void		*player_left;
	void		*player_right;
	void		*items;
	void		*end_img;
	t_for_mlx	*for_mlx_r;
}	t_game_data;

void	valid_arg(int argc, char **argv);
int		ft_atoi(const char *str);
void	ft_putstr_fd(char const *s, int fd);
char	*ft_strrchr(const char *str, int ch);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
void	ft_putnbr_fd(int n, int fd);

char	**init_map(char **argv);
char	**valid_map_arg(int fd);
void	check_one(char **arr_map, int count_str);
void	check_len(char **arr_map, unsigned long int c_str);
void	check_player_exit(char **arr_map);
void	check_valid_symbol(char **arr_map, int count_c);

void	error(char **arr_map);

void	init_data(t_game_data *data, char **arr_map);
void	init_game(t_game_data *data);
void	init_xpm(t_game_data *data, t_for_mlx *for_mlx_r);
int		exit_hook(t_game_data *data);

void	draw_map(t_game_data *data, t_for_mlx *for_mlx_r);
void	to_right(t_game_data *data);
void	to_left(t_game_data *data);
void	to_up(t_game_data *data);
void	to_down(t_game_data *data);

#endif
