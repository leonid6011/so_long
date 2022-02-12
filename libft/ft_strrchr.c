#include "../inc/so_long.h"

char	*ft_strrchr(const char *str, int ch)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
	{
		if (str[i] == (char)ch)
			return ((char *)(str + i));
		i--;
	}
	return (NULL);
}