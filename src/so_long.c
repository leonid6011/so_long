/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:12:46 by echrysta          #+#    #+#             */
/*   Updated: 2022/02/17 17:12:47 by echrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
