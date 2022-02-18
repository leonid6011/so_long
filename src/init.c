/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:12:34 by echrysta          #+#    #+#             */
/*   Updated: 2022/02/17 17:12:36 by echrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_data_help(t_game_data *data, char **arr_map)
{
	int	x;
	int	y;
	int	max_score;

	max_score = 0;
	y = 0;
	while (arr_map[y])
	{
		x = 0;
		while (arr_map[y][x])
		{
			if (arr_map[y][x] == 'P')
			{
				data->player_pos_x = x;
				data->player_pos_y = y;
			}
			if (arr_map[y][x] == 'C')
				max_score++;
			x++;
		}
		y++;
	}
	data->max_score = max_score;
}

void	init_data(t_game_data *data, char **arr_map)
{
	int	height;

	data->game_over = 0;
	data->steps = 0;
	data->score = 0;
	data->arr_map = arr_map;
	data->map_length = (int)ft_strlen(arr_map[0]) - 1;
	height = 0;
	while (arr_map[height])
		height++;
	data->map_height = height;
	init_data_help(data, arr_map);
}

char	**init_map(char **argv)
{
	char	*name;
	char	**arr_map;
	int		fd;

	name = argv[1];
	fd = open(name, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Can't open file!\n", 2);
		exit(1);
	}
	arr_map = valid_map_arg(fd);
	return (arr_map);
}
