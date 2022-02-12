#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx_linux/mlx.h"
# include "../get_next_line/get_next_line.h"

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h> //потом убрать


void			valid_arg(int argc, char **argv);
int				ft_atoi(const char *str);
void			ft_putstr_fd(char const *s, int fd);
char			*ft_strrchr(const char *str, int ch);
int				ft_strncmp(const char *str1, const char *str2, size_t n);

void    init_map(char **argv);
void	valid_map_arg(int fd);
void	check_one(char **arr_map, int count_str);
void	check_len(char **arr_map, unsigned long int c_str);
void	check_player_exit(char **arr_map);
void	check_valid_symbol(char **arr_map, int count_c);

#endif