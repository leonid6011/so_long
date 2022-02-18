/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:12:40 by echrysta          #+#    #+#             */
/*   Updated: 2022/02/17 17:12:42 by echrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	final_game(t_game_data *data)
{
	free(data->arr_map);
	ft_putstr_fd("Congratulations! YOU WIN!\n", 1);
	exit(0);
}

void	to_right(t_game_data *data)
{
	int	x_p;
	int	y_p;

	x_p = data->player_pos_x;
	y_p = data->player_pos_y;
	if (data->arr_map[y_p][x_p + 1] == '1')
		return ;
	if (data->max_score == data->score && data->arr_map[y_p][x_p + 1] == 'E')
		final_game(data);
	if (data->arr_map[y_p][x_p + 1] == 'E')
		return ;
	if (data->arr_map[y_p][x_p + 1] == 'C')
		data->score++;
	data->arr_map[y_p][x_p] = '0';
	data->player_pos_x = data->player_pos_x + 1;
	x_p = data->player_pos_x;
	data->arr_map[y_p][x_p] = 'P';
	data->steps++;
	ft_putstr_fd("Steps: ", 1);
	ft_putnbr_fd(data->steps, 1);
	ft_putstr_fd("\n", 1);
	draw_map(data, data->for_mlx_r);
}

void	to_left(t_game_data *data)
{
	int	x_p;
	int	y_p;

	x_p = data->player_pos_x;
	y_p = data->player_pos_y;
	if (data->arr_map[y_p][x_p - 1] == '1')
		return ;
	if (data->max_score == data->score && data->arr_map[y_p][x_p - 1] == 'E')
		final_game(data);
	if (data->arr_map[y_p][x_p - 1] == 'E')
		return ;
	if (data->arr_map[y_p][x_p - 1] == 'C')
		data->score++;
	data->arr_map[y_p][x_p] = '0';
	data->player_pos_x = data->player_pos_x - 1;
	x_p = data->player_pos_x;
	data->arr_map[y_p][x_p] = 'P';
	data->steps++;
	ft_putstr_fd("Steps: ", 1);
	ft_putnbr_fd(data->steps, 1);
	ft_putstr_fd("\n", 1);
	draw_map(data, data->for_mlx_r);
}

void	to_up(t_game_data *data)
{
	int	x_p;
	int	y_p;

	x_p = data->player_pos_x;
	y_p = data->player_pos_y;
	if (data->arr_map[y_p - 1][x_p] == '1')
		return ;
	if (data->max_score == data->score && data->arr_map[y_p - 1][x_p] == 'E')
		final_game(data);
	if (data->arr_map[y_p - 1][x_p] == 'E')
		return ;
	if (data->arr_map[y_p - 1][x_p] == 'C')
		data->score++;
	data->arr_map[y_p][x_p] = '0';
	data->player_pos_y = data->player_pos_y - 1;
	y_p = data->player_pos_y;
	data->arr_map[y_p][x_p] = 'P';
	data->steps++;
	ft_putstr_fd("Steps: ", 1);
	ft_putnbr_fd(data->steps, 1);
	ft_putstr_fd("\n", 1);
	draw_map(data, data->for_mlx_r);
}

void	to_down(t_game_data *data)
{
	int	x_p;
	int	y_p;

	x_p = data->player_pos_x;
	y_p = data->player_pos_y;
	if (data->arr_map[y_p + 1][x_p] == '1')
		return ;
	if (data->max_score == data->score && data->arr_map[y_p + 1][x_p] == 'E')
		final_game(data);
	if (data->arr_map[y_p + 1][x_p] == 'E')
		return ;
	if (data->arr_map[y_p + 1][x_p] == 'C')
		data->score++;
	data->arr_map[y_p][x_p] = '0';
	data->player_pos_y = data->player_pos_y + 1;
	y_p = data->player_pos_y;
	data->arr_map[y_p][x_p] = 'P';
	data->steps++;
	ft_putstr_fd("Steps: ", 1);
	ft_putnbr_fd(data->steps, 1);
	ft_putstr_fd("\n", 1);
	draw_map(data, data->for_mlx_r);
}
