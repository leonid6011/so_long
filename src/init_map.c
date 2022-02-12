#include "../inc/so_long.h"

void	init_map(char **argv)
{
	char    *name;
	int		fd;

	name = argv[1];
	fd = open(name, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Can't open file!\n", 2);
		exit(1);
	}
	valid_map_arg(fd);
}