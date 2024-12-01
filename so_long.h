#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024  // Set the default buffer size to 1024 bytes
# endif

# define PIXEL 16

# include "minilibx-linux/mlx.h"
# include <stddef.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"
# include <stdlib.h>
# include "libft/gnl/get_next_line.h"

typedef struct s_map
{
    void    *ground;
    void    *wall;
    void    *collectible_img;
    int    collectible_img_width;
    int    collectible_img_height;
    int     collectibles;
    char    *map;
    char **array;
    void   *exit;
    int    map_width;
    int    map_height;
}	t_map;

typedef struct s_player
{
    void    *player;
    int     x;
    int     y;
    int     collectibles;
    int     moves;
    int     img_width;
    int    img_height;
}	t_player;

typedef struct s_game
{
    void    *mlx;
    void    *win;
    void    *img;
    t_map   map;
    t_player player;
}	t_game;


void  get_map(char *argv, t_game *game);

#endif