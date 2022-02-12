/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:19:27 by echrysta          #+#    #+#             */
/*   Updated: 2021/11/24 17:21:02 by echrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ost_ot_ost(char *ost)
{
	char	*new_ost;
	int		i;
	int		n;

	i = 0;
	while (ost[i] != '\0' && ost[i] != '\n')
		i++;
	if (!ost[i])
	{
		free (ost);
		return ((void *)0);
	}
	new_ost = malloc(sizeof(char) * (ft_strlen(ost) - i + 1));
	if (!new_ost)
		return ((void *)0);
	i++;
	n = 0;
	while (ost[i] != '\0')
		new_ost[n++] = ost[i++];
	free(ost);
	new_ost[n] = '\0';
	return (new_ost);
}

char	*line_create(char *ost)
{
	char	*line;
	int		i;

	i = 0;
	if (!ost[i])
		return ((void *)0);
	while (ost[i] != '\0' && ost[i] != '\n')
		i++;
	line = malloc((i + 2) * sizeof(char));
	if (!line)
		return ((void *)0);
	i = 0;
	while (ost[i] != '\0' && ost[i] != '\n')
	{
		line[i] = ost[i];
		i++;
	}
	if (ost[i] == '\n')
	{
		line[i] = ost[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*read_from_b(int fd, char *ost)
{
	char	b[BUFFER_SIZE + 1];
	long	count;

	b[0] = '\0';
	count = 1;
	while (!ft_strchr(b, '\n') && count)
	{
		count = read(fd, b, BUFFER_SIZE);
		if (count == -1)
			return ((void *)0);
		b[count] = '\0';
		if (!ost)
		{
			ost = malloc(1);
			if (!ost)
				return ((void *)0);
			ost[0] = '\0';
		}
		ost = strjoin_for_gnl(ost, b);
	}
	return (ost);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*ost;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return ((void *)0);
	ost = read_from_b(fd, ost);
	if (!ost)
		return ((void *)0);
	line = line_create(ost);
	ost = ost_ot_ost(ost);
	return (line);
}
