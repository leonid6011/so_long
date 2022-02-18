/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:32:26 by echrysta          #+#    #+#             */
/*   Updated: 2022/02/17 17:32:27 by echrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	draw_help_map(t_game_data *data, t_for_mlx *for_mlx_r, int x, int y)
{
	if (data->arr_map[y][x] == '1')
	{
		mlx_put_image_to_window(for_mlx_r->mlx,
			for_mlx_r->win, data->wall, x * 50, y * 50);
	}
	if (data->arr_map[y][x] == '0')
	{
		mlx_put_image_to_window(for_mlx_r->mlx,
			for_mlx_r->win, data->floor, x * 50, y * 50);
	}
	if (data->arr_map[y][x] == 'E')
	{
		mlx_put_image_to_window(for_mlx_r->mlx, for_mlx_r->win,
			data->exit, x * 50, y * 50);
	}
	if (data->arr_map[y][x] == 'C')
	{
		mlx_put_image_to_window(for_mlx_r->mlx, for_mlx_r->win,
			data->items, x * 50, y * 50);
	}
	if (data->arr_map[y][x] == 'P')
	{
		mlx_put_image_to_window(for_mlx_r->mlx, for_mlx_r->win,
			data->player, x * 50, y * 50);
	}	
}

void	draw_map(t_game_data *data, t_for_mlx *for_mlx_r)
{
	int	y;
	int	x;

	y = 0;
	while (y != data->map_height)
	{
		x = 0;
		while (x != data->map_length)
		{
			draw_help_map(data, for_mlx_r, x, y);
			x++;
		}
		y++;
	}
}

void	init_xpm(t_game_data *data, t_for_mlx *for_mlx_r)
{
	int	i;

	i = 50;
	data->wall = mlx_xpm_file_to_image(for_mlx_r->mlx,
			"./textures/1.xpm", &i, &i);
	data->floor = mlx_xpm_file_to_image(for_mlx_r->mlx,
			"./textures/0.xpm", &i, &i);
	data->player = mlx_xpm_file_to_image(for_mlx_r->mlx,
			"./textures/P.xpm", &i, &i);
	data->exit = mlx_xpm_file_to_image(for_mlx_r->mlx,
			"./textures/E.xpm", &i, &i);
	data->items = mlx_xpm_file_to_image(for_mlx_r->mlx,
			"./textures/C.xpm", &i, &i);
}
