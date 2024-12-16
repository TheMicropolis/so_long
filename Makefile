# Compiler und Flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -Iminilibx-linux -I./libft -I./libft/gnl -I./libft/ft_printf
# Bibliotheken
MLX = minilibx-linux/libmlx_Linux.a
MLX_FLAGS = -Lminilibx-linux -lmlx -lm -lXext -lX11
LIBFT = ./libft/libft.a

# Ziel
NAME = so_long

# Quellen und Objekte
SRCS = so_long.c get_map.c exit_game.c
OBJS = $(SRCS:.c=.o)

# Regel für das Ziel
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(OBJS) $(MLX) $(MLX_FLAGS) $(LIBFT) $(CFLAGS) -o $(NAME)

$(LIBFT):
	make -C ./libft

clean:
	rm -f $(OBJS)
	make -C ./libft clean

fclean: clean
	rm -f $(NAME)
	make -C ./libft fclean

re: fclean all
