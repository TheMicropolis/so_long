#include "so_long.h"

void    destroy_img(void *mlx, void *img)
{
    if (img)
    {
        mlx_destroy_image(mlx, img);
        img = NULL;
    } 
}
void    free_img(t_game *game)
{
    destroy_img(game->mlx, game->map.ground);
    destroy_img(game->mlx, game->map.collectible_img);
    destroy_img(game->mlx, game->map.wall);
    destroy_img(game->mlx, game->map.exit);
    destroy_img(game->mlx, game->player.player);
    if (game->map.map)
    {
        free(game->map.map);
        game->map.map = NULL;
    }
}
void    free_array(t_game *game)
{
    int i;

    i = 0;
    while (game->map.array[i])
    {
        free(game->map.array[i]);
        i++;
    }
    free(game->map.array);
    game->map.array = NULL;
}
int exit_game(t_game *game, int code)
{
   if (game->win) 
    {
        mlx_destroy_window(game->mlx, game->win);
        game->win = NULL;
    }
    if (game->map.array)
        free_array(game);
    free_img(game);  
    if (game->mlx)
    {
        mlx_destroy_display(game->mlx);
        free(game->mlx);   
            game->mlx = NULL;
    }
    exit(code);
}

