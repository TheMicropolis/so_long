#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024  // Set the default buffer size to 1024 bytes
# endif

# define PIXEL 32

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
    int     collectibles;
    char    *map;
    char **array;
    char **copy;
    void   *exit;
    int    map_width;
    int    map_height;
    int     exit_x;
    int     exit_y;
}	t_map;

typedef struct s_player
{
    void    *player;
    int     x;
    int     y;
    int     collectibles;
    int     moves;
}	t_player;

typedef struct s_game
{
    void    *mlx;
    void    *win;
    t_map   map;
    t_player player;
}	t_game;

void    get_map(char *argv, t_game *game);
void    free_array(char **array);
void    initialize_game(t_game *game, char *argv);
void    set_map(t_game *game);
void    set_walls(t_game *game);
void    set_null(t_game *game);
void    update_player_pos(t_game *game, int x, int y);
void    check_format(t_game *game);
void    check_map(char *ber, t_game *game);
void    move_player(t_game *game, int x, int y);
void    free_img(t_game *game);
void    destroy_img(void *mlx, void *img);
int     key_hook(int keycode, t_game *game);
int     exit_game(t_game *game, int code);
int     load_images(t_game *game);
void    check_horizontal_walls(t_game  *game);
void    check_vertical_walls(t_game  *game);
void    handle_exit(t_game *game, int x, int y);
void    format_map(char ***ber, t_game *game);
char    **copy_map(t_game *game);
void	floodfill(t_game *game);

#endif