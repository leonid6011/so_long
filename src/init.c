#include "../inc/so_long.h"

int  exit_hook()
{
    exit(0);
}

void	draw_map(t_game_data *data, t_for_mlx *for_mlx_r)
{
	int y;
	int x;

	y = 0;
	while (y != data->map_height)
	{
		x = 0;
		while (x != data->map_length)
		{
			if (data->arr_map[y][x] == '1')
				mlx_put_image_to_window(for_mlx_r->mlx, for_mlx_r->win, data->wall, x * 50, y * 50);
			if (data->arr_map[y][x] == '0')
				mlx_put_image_to_window(for_mlx_r->mlx, for_mlx_r->win, data->floor, x * 50, y * 50);
			if (data->arr_map[y][x] == 'E')
				mlx_put_image_to_window(for_mlx_r->mlx, for_mlx_r->win, data->exit, x * 50, y * 50);
			if (data->arr_map[y][x] == 'C')
				mlx_put_image_to_window(for_mlx_r->mlx, for_mlx_r->win, data->items, x * 50, y * 50);	
			if (data->arr_map[y][x] == 'P')
				mlx_put_image_to_window(for_mlx_r->mlx, for_mlx_r->win, data->player, x * 50, y * 50);				
			x++;
		}
		y++;
	}
}

void	init_xpm(t_game_data *data, t_for_mlx *for_mlx_r)
{
	int i;

	i = 50;
	data->wall = mlx_xpm_file_to_image(for_mlx_r->mlx, "./textures/1.xpm", &i, &i);
	data->floor = mlx_xpm_file_to_image(for_mlx_r->mlx, "./textures/0.xpm", &i, &i);
	data->player = mlx_xpm_file_to_image(for_mlx_r->mlx, "./textures/P.xpm", &i, &i);
	data->exit = mlx_xpm_file_to_image(for_mlx_r->mlx, "./textures/E.xpm", &i, &i);
	data->items = mlx_xpm_file_to_image(for_mlx_r->mlx, "./textures/C.xpm", &i, &i);
}

int	key_hook(int code_key, t_game_data *data)
{
	if (code_key == 65307)
		exit_hook(data);
	if (code_key == 115)
		to_down(data);
	if (code_key == 119)
		to_up(data);
	if (code_key == 100)
		to_right(data);
	if (code_key == 97)
		to_left(data);
	//printf("key_code %d\n", code_key);
	return (1);
}

void	init_game(t_game_data *data)
{
	t_for_mlx for_mlx_r;

	for_mlx_r.mlx = mlx_init();
	for_mlx_r.win = mlx_new_window(for_mlx_r.mlx, data->map_length * 50, data->map_height * 50, "so_long");

	data->for_mlx_r = &for_mlx_r;

	init_xpm(data, data->for_mlx_r);
	draw_map(data, data->for_mlx_r);
	mlx_key_hook(for_mlx_r.win, &key_hook, data);
	mlx_hook(for_mlx_r.win, 17, 0, exit_hook, data);
	mlx_loop(for_mlx_r.mlx);
}

void	init_data(t_game_data *data, char **arr_map)
{
	int height;
	int x;
	int y;
	int	max_score;

	data->game_over = 0;
	data->steps = 0;
	data->score = 0;
	data->arr_map = arr_map;
	data->map_length = (int)ft_strlen(arr_map[0]) - 1;
	height = 0;
	while (arr_map[height])
		height++;
	data->map_height = height;
	y = 0;
	max_score = 0;
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

char	**init_map(char **argv)
{
	char    *name;
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