/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:13:01 by echrysta          #+#    #+#             */
/*   Updated: 2022/02/17 17:13:02 by echrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	error(char **arr_map)
{
	free(arr_map);
	exit(1);
}

void	check_player_exit_help(int count_p, int count_e, char **arr_map)
{
	if (count_p != 1 || count_p == 0)
	{
		ft_putstr_fd("Invalid map\n", 2);
		error(arr_map);
	}
	if (count_e == 0)
	{
		ft_putstr_fd("Invalid map\n", 2);
		error(arr_map);
	}
}

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
	check_player_exit_help(count_p, count_e, arr_map);
}

void	error_map(char **arr_map)
{
	ft_putstr_fd("Invalid map\n", 2);
	error(arr_map);
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
								error_map(arr_map);
			j++;
		}
		i++;
	}
}
