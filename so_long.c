#include "so_long.h"
void  set_img(void **img_ptr, char *img_path, t_game *game, int x, int y)
{
    int width;
    int height;
    *img_ptr = mlx_xpm_file_to_image(game->mlx, img_path, &width, &height);
    if (*img_ptr)
        mlx_put_image_to_window(game->mlx, game->win, *img_ptr, x * PIXEL, y * PIXEL);
    else
    {
        printf("Error: Failed to load image %s\n", img_path);
        exit(1);
    }
}
void    set_map(t_game *game)
{
    int x; 
    int y;

    y = 0;
    while (y < game->map.map_height)
    {
        x = 0;
        while (x < game->map.map_width)
        {
            if (game->map.array[y][x] == '1')
                set_img(&game->map.wall, "textures/wall.xpm", game, x, y);
            else if (game->map.array[y][x] == '0')
                set_img(&game->map.ground, "textures/ground.xpm", game, x, y);
            else if (game->map.array[y][x] == 'E')
                set_img(&game->map.exit, "textures/exit.xpm", game, x, y);
            else if (game->map.array[y][x] == 'C')
                set_img(&game->map.collectible_img, "textures/collect.xpm", game, x, y);
            else if (game->map.array[y][x] == 'P') 
            {
                if (game->player.x == 0 && game->player.y == 0)
                {
                    game->player.x = x;
                    game->player.y = y;
                }
            set_img(&game->player.player, "textures/collect.xpm", game, game->player.x, game->player.y);
            }
            x++;
        }
        y++;
    }
}

void move_player(t_game *game, int x, int y, int dy, int dx)
{
    game->map.array[y][x] = '0';
    if (game->map.array[y + dy][x + dx] == 'C')
    {
        game->player.collectibles++;
        game->map.array[y + dy][x + dy] = 'P';
    }
    game->player.moves++;
    set_map(game);
}
int    key_hook(int keycode, t_game *game)
{
    mlx_clear_window(game->mlx, game->win);
    if (keycode == 65307)                           //esc
        mlx_destroy_window(game->mlx, game->win);
    else if (keycode == 'w')                                                 //w
        move_player(game, game->player.x, --game->player.y, -1, 0);
    else if (keycode == 's')       //s                                             
        move_player(game, game->player.x, ++game->player.y, 1, 0);  
    else if (keycode == 'a')        //a                                               
        move_player(game, --game->player.x, game->player.y, 0, -1);
    else if (keycode == 'd')       //d                                            
        move_player(game, ++game->player.x, game->player.y, 0, 1);
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
    map->map_height = 0;
    map->map_width = 0;
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
    get_map(av[1], &game);

    game.mlx = mlx_init();
    game.win = mlx_new_window(game.mlx, game.map.map_width * PIXEL, game.map.map_height * PIXEL, "so_long");

    set_map(&game);

    //game.player.player = mlx_xpm_file_to_image(game.mlx, "textures/tile1.xpm", &game.player.img_width, &game.player.img_height);
    //mlx_put_image_to_window(game.mlx, game.win, game.player.player, game.player.x * 1, game.player.y * 1);

    mlx_hook(game.win, 2, 1L<<0, key_hook, &game);

    mlx_loop(game.mlx);
}
