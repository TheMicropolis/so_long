#include "so_long.h"

void    set_map(t_game *game)
{
    int y;
    int x;

    y = 0;
    x = 0;
    
    while (game->map.array[y][x])
    {
        while (game->map.array[y][x] == 1)
        {
            game->map.ground = mlx_xpm_file_to_image(game->mlx, "textures/tile1.xpm", &game->map.collectible_img_width, &game->map.collectible_img_height);
            mlx_put_image_to_window(game->mlx, game->win, game->map.ground, y * PIXEL, x * PIXEL);
            x++;
        }
        y++;
        x = 0;
    }
    
    game->map.collectible_img = mlx_xpm_file_to_image(game->mlx, "textures/tile1.xpm", &game->map.collectible_img_width, &game->map.collectible_img_height);
    mlx_put_image_to_window(game->mlx, game->win, game->map.collectible_img, 320, 160);
    game->map.exit = mlx_xpm_file_to_image(game->mlx, "textures/tile1.xpm", &game->map.collectible_img_width, &game->map.collectible_img_height);
    mlx_put_image_to_window(game->mlx, game->win, game->map.exit, 320, 0);
    
    //game->map.ground = mlx_xpm_file_to_image(
    //game->map.wall = mlx_xpm_file_to_image(
}
void    move_player(t_game *game)
{
    mlx_clear_window(game->mlx, game->win);
    set_map(game);
    mlx_put_image_to_window(game->mlx, game->win, game->player.player, game->player.x, game->player.y);
}
int    key_hook(int keycode, t_game *game)
{
    if (keycode == 65307) //esc
        mlx_destroy_window(game->mlx, game->win);
    else if (keycode == 119 || keycode == 38) //w
        game->player.y -= PIXEL;
    else if (keycode == 115 || keycode == 40) //s
        game->player.y += PIXEL;
    else if (keycode == 97 || keycode == 37 ) //a
        game->player.x -= PIXEL;
    else if (keycode == 100 || keycode == 39) //d
        game->player.x += PIXEL;
    move_player(game);
    return (0);
}
void    set_null_player(t_player *player)
{
    player->player = NULL;
    player->x = 0;
    player->y = 0;
    player->collectibles = 0;
    player->moves = 0;
    player->img_width = 0;
    player->img_height = 0;
}
void    set_null_map(t_map *map)
{
    map->ground = NULL;
    map->wall = NULL;
    map->collectible_img = NULL;
    map->collectibles = 0;
    map->collectible_img_height = 0;
    map->collectible_img_width = 0;
    map->exit = NULL;
    map->array = NULL;
}
void    set_null_game(t_game *game)
{
    game->mlx = NULL;
    game->win = NULL;
    game->img = NULL;
    set_null_player(&game->player);
    set_null_map(&game->map);
}
int	main(int ac, char **av)
{
    t_game game;
    
    if (ac != 2)
    {
        printf("too many arguments\n");
        return (1);
    }
    set_null_game(&game);
    set_null_player(&game.player);
    set_null_map(&game.map);
    get_map(av[1]);

    game.mlx = mlx_init();
    game.win = mlx_new_window(game.mlx, WIDTH, HEIGHT, "so_long");

    set_map(&game);

    game.player.player = mlx_xpm_file_to_image(game.mlx, "textures/tile1.xpm", &game.player.img_width, &game.player.img_height);
    mlx_put_image_to_window(game.mlx, game.win, game.player.player, PIXEL, PIXEL);

    mlx_hook(game.win, 2, 1L<<0, key_hook, &game);

    mlx_loop(game.mlx);
}
