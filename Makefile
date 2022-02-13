NAME 	= so_long
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
SRCS	= src/so_long.c src/validation.c libft/ft_atoi.c libft/ft_putstr_fd.c libft/ft_strrchr.c libft/ft_strncmp.c\
			get_next_line/get_next_line.c get_next_line/get_next_line_utils.c src/init.c src/validation2.c\
			src/move.c

OBJ		= $(SRCS:%.c=%.o)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

all		:	$(NAME)

clean	:
	rm -rf $(OBJ)

fclean	: clean
	rm -rf $(NAME)

re		: fclean $(NAME)

.PHONY	: all clean fclean re