#include "../inc/so_long.h"

void	check_player_exit(char **arr_map)
{
	int	count_p;
	int	count_e;
	int	i;
	int	j;

	i = 0;
	count_e = 0;
	count_p = 0;
	while (arr_map[i])
	{
		j = 0;
		while (arr_map[i][j])
		{
			if (arr_map[i][j] == 'E')
				count_e++;
			if (arr_map[i][j] == 'P')
				count_p++;
			j++;
		}
		i++;
	}
	if (count_p != 1 || count_p == 0)
	{
		ft_putstr_fd("Invalid map\n", 2);
		exit(1);
	}
	if (count_e == 0)
	{
		ft_putstr_fd("Invalid map\n", 2);
		exit(1);
	}
}

void	error_map(void)
{
	ft_putstr_fd("Invalid map\n", 2);
	exit(1);
}

void	check_valid_symbol(char **arr_map, int count_c)
{
	int	i;
	int	j;

	i = 0;
	while (i != count_c - 1)
	{
		j = 0;
		while (arr_map[i][j] != '\0' && arr_map[i][j] != '\n')
		{
			if (arr_map[i][j] != '0')
				if (arr_map[i][j] != '1')
					if (arr_map[i][j] != 'C')
						if (arr_map[i][j] != 'E')
							if (arr_map[i][j] != 'P')
								error_map();
			j++;
		}
		i++;
	}
}