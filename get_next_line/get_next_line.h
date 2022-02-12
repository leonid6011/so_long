/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:58:07 by echrysta          #+#    #+#             */
/*   Updated: 2021/11/24 17:58:41 by echrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 36
# endif

# include <unistd.h>
# include <stdlib.h>

unsigned long	ft_strlen(const char *s);
char			*ft_strchr(const char *str, int ch);
char			*strjoin_for_gnl(char *s1, char *s2);
char			*get_next_line(int fd);

#endif
