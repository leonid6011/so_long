#include "../inc/so_long.h"

int	main(int argc, char **argv)
{
	t_game_data	data;
	char		**arr_map;

	valid_arg(argc, argv);
	arr_map = init_map(argv);
	init_data(&data, arr_map);
	init_game(&data);
}