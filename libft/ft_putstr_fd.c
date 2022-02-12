#include "../inc/so_long.h"

void	ft_putstr_fd(char const *s, int fd)
{
	if (s == NULL)
		write(1, NULL, 1);
	else
		write(fd, s, ft_strlen(s));
}