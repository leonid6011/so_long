#include "../inc/so_long.h"

void	to_right(t_game_data *data)
{
	int pos_x_p;
	int pos_y_p;

	pos_x_p = data->player_pos_x;
	pos_y_p = data->player_pos_y;
	if (data->arr_map[pos_y_p][pos_x_p + 1] == '1')
		return ;
	if (data->arr_map[pos_y_p][pos_x_p + 1] == 'C')
		data->score++;
	printf("data->score %d\n", data->score);
	data->arr_map[pos_y_p][pos_x_p] = '0';
	data->player_pos_x = data->player_pos_x + 1;
	pos_x_p = data->player_pos_x;
	data->arr_map[pos_y_p][pos_x_p] = 'P';
	draw_map(data, data->for_mlx_r);
}

void	to_left(t_game_data *data)
{
	int pos_x_p;
	int pos_y_p;

	pos_x_p = data->player_pos_x;
	pos_y_p = data->player_pos_y;
	if (data->arr_map[pos_y_p][pos_x_p - 1] == '1')
		return ;
	if (data->arr_map[pos_y_p][pos_x_p - 1] == 'C')
		data->score++;
	printf("data->score %d\n", data->score);
	data->arr_map[pos_y_p][pos_x_p] = '0';
	data->player_pos_x = data->player_pos_x - 1;
	pos_x_p = data->player_pos_x;
	data->arr_map[pos_y_p][pos_x_p] = 'P';
	draw_map(data, data->for_mlx_r);
}

void	to_up(t_game_data *data)
{
	int pos_x_p;
	int pos_y_p;

	pos_x_p = data->player_pos_x;
	pos_y_p = data->player_pos_y;
	if (data->arr_map[pos_y_p - 1][pos_x_p] == '1')
		return ;
	if (data->arr_map[pos_y_p - 1][pos_x_p] == 'C')
		data->score++;
	printf("data->score %d\n", data->score);
	data->arr_map[pos_y_p][pos_x_p] = '0';
	data->player_pos_y = data->player_pos_y - 1;
	pos_y_p = data->player_pos_y;
	data->arr_map[pos_y_p][pos_x_p] = 'P';
	draw_map(data, data->for_mlx_r);
}

void	to_down(t_game_data *data)
{
	int pos_x_p;
	int pos_y_p;

	pos_x_p = data->player_pos_x;
	pos_y_p = data->player_pos_y;
	if (data->arr_map[pos_y_p + 1][pos_x_p] == '1')
		return ;
	if (data->arr_map[pos_y_p + 1][pos_x_p] == 'C')
		data->score++;
	printf("data->score %d\n", data->score);
	data->arr_map[pos_y_p][pos_x_p] = '0';
	data->player_pos_y = data->player_pos_y + 1;
	pos_y_p = data->player_pos_y;
	data->arr_map[pos_y_p][pos_x_p] = 'P';
	draw_map(data, data->for_mlx_r);
}