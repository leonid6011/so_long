#include "../inc/so_long.h"

void	valid_arg(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr_fd("Error\nargc != 2\n", 2);
		exit(0);
	}
    if (!ft_strrchr(argv[1], '.'))
	{
		ft_putstr_fd("Error\nInvalid name map *.ber\n", 2);
		exit(0);
	}
	if (ft_strncmp(ft_strrchr(argv[1], '.'), ".ber", ft_strlen(argv[1])) != 0)
	{
		ft_putstr_fd("Error\nInvalid name map *.ber\n", 2);
		exit(0);
	}
}

static void	check_one_help(char **arr_map, int x, int y)
{
	x = 0;
	y--;
	while (arr_map[y][x])
	{
		if (arr_map[y][x] != '1' && arr_map[y][x] != '\n')
		{
			ft_putstr_fd("Invalid map\n", 2);
			exit(1);
		}
		x++;
	}
}

void	check_one(char **arr_map, int count_str)
{
	int	x;
	int	y;

	x = 0;
	while (arr_map[0][x])
	{
		if (arr_map[0][x] != '1' && arr_map[0][x] != '\n')
		{
			ft_putstr_fd("Invalid map\n", 2);
			exit(1);
		}
		x++;
	}
	x = x - 2;
	y = 0;
	while (y != count_str - 1)
	{
		if (arr_map[y][0] != '1')
		{
			ft_putstr_fd("Invalid map\n", 2);
			exit(1);
		}
		if (arr_map[y][x] != '1')
		{
			ft_putstr_fd("Invalid map\n", 2);
			exit(1);
		}
		y++;
	}
	check_one_help(arr_map, x, y);
}

void	check_len(char **arr_map, unsigned long int c_str)
{
	unsigned long int	len_str;
	unsigned long int	i;

	len_str = ft_strlen(arr_map[0]);
	i = 0;
	while (i != c_str - 2)
	{
		if (ft_strlen(arr_map[i]) != len_str)
		{
			ft_putstr_fd("Invalid map\n", 2);
			exit(1);
		}
		i++;
	}
	if (ft_strlen(arr_map[i]) != len_str - 1)
	{
		ft_putstr_fd("Invalid map\n", 2);
		exit(1);
	}
}

char	**valid_map_arg(int fd)
{
	char	**arr_map;
	char	*one_str;
	int		i;

	arr_map = (char **)malloc(sizeof(char *) * 10000);
	i = 0;
	while (one_str)
	{
		one_str = get_next_line(fd);
		arr_map[i] = one_str;
		i++;
	}
	close(fd);
	check_one(arr_map, i);
	check_len(arr_map, i);
	check_player_exit(arr_map);
	check_valid_symbol(arr_map, i);
	return (arr_map);
}