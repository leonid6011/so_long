#include "get_next_line.h"

unsigned long	ft_strlen(const char *s)
{
	unsigned long	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int ch)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != (char)ch)
		i++;
	if (str[i] == (char)ch)
		return ((char *)str + i);
	return (NULL);
}

char	*strjoin_for_gnl(char *s1, char *s2)
{
	int		m;
	int		n;
	char	*result;

	m = 0;
	n = 0;
	if (!s1)
		return ((void *)0);
	result = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (result == NULL)
		return (NULL);
	while (s1[m] != '\0')
	{
		result[m] = s1[m];
		m++;
	}
	while (s2[n] != '\0')
	{
		result[m + n] = s2[n];
		n++;
	}
	result[m + n] = '\0';
	free(s1);
	return (result);
}
