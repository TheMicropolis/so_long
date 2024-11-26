# Compiler und Flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iminilibx-linux

# Bibliotheken
MLX = minilibx-linux/libmlx_Linux.a
MLX_FLAGS = -Lminilibx-linux -lmlx -lm -lXext -lX11

# Ziel
NAME = so_long

# Quellen und Objekte
SRC_DIR = src
SRCS = $(SRC_DIR)/so_long.c
OBJS = $(SRCS:.c=.o)

# Regel für das Ziel
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX) $(MLX_FLAGS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
