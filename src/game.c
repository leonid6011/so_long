/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:41:20 by echrysta          #+#    #+#             */
/*   Updated: 2022/02/17 17:41:21 by echrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	exit_hook(t_game_data *data)
{
	exit(0);
	free(data->arr_map);
	return (1);
}

void	help_key_hook(int code_key, t_game_data *data)
{
	int	i;

	i = 50;
	if (code_key == 1)
	{
		data->player = mlx_xpm_file_to_image(data->for_mlx_r->mlx,
				"./textures/P.xpm", &i, &i);
		to_down(data);
	}
	if (code_key == 13)
	{
		data->player = mlx_xpm_file_to_image(data->for_mlx_r->mlx,
				"./textures/P_up.xpm", &i, &i);
		to_up(data);
	}
}

int	key_hook(int code_key, t_game_data *data)
{
	int	i;

	i = 50;
	if (code_key == 53)
		exit_hook(data);
	help_key_hook(code_key, data);
	if (code_key == 2)
	{
		data->player = mlx_xpm_file_to_image(data->for_mlx_r->mlx,
				"./textures/P_right.xpm", &i, &i);
		to_right(data);
	}
	if (code_key == 0)
	{
		data->player = mlx_xpm_file_to_image(data->for_mlx_r->mlx,
				"./textures/P_left.xpm", &i, &i);
		to_left(data);
	}
	return (1);
}

void	init_game(t_game_data *data)
{
	t_for_mlx	for_mlx_r;

	for_mlx_r.mlx = mlx_init();
	for_mlx_r.win = mlx_new_window(for_mlx_r.mlx,
			data->map_length * 50, data->map_height * 50, "so_long");
	data->for_mlx_r = &for_mlx_r;
	init_xpm(data, data->for_mlx_r);
	draw_map(data, data->for_mlx_r);
	mlx_key_hook(for_mlx_r.win, &key_hook, data);
	mlx_hook(for_mlx_r.win, 17, 0, exit_hook, data);
	mlx_loop(for_mlx_r.mlx);
}
