#ifndef SO_LONG_H
# define SO_LONG_H

# define WIDTH 480
# define HEIGHT 320
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


void  get_map(char *argv);

#endif