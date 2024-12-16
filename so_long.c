#include "so_long.h"

void    move_player(t_game *game, int x, int y, int dy, int dx)
{
    if (game->map.array == NULL || y < 0 || x < 0 || y >= game->map.map_height || x >= game->map.map_width)
        exit_game(game, 1);
    if (game->map.array[y][x] == 'C')
    {
        game->player.collectibles++;
        ft_printf("You collected %d out of %d item(s)!\n", game->player.collectibles, game->map.collectibles);
    }
    if (game->map.array[y][x] == 'E' && game->player.collectibles == game->map.collectibles)
    {
        game->map.array[y][x] = 'P';
        ft_printf("You won!\n");
        exit_game(game, 0);
    } 
    game->player.moves++;
    game->map.array[y - dy][x - dx] = '0';
    game->map.array[y][x] = 'P';
    ft_printf("Moves: %d\n", game->player.moves);
    set_map(game);
}
int    key_hook(int keycode, t_game *game)
{
    //mlx_clear_window(game->mlx, game->win);
    if (keycode == 17)
        exit_game(game, 0);
    else if (keycode == 65307)                          
        exit_game(game, 0);
    else if (keycode == 'w' && game->map.array[game->player.y - 1][game->player.x] != '1')
        move_player(game, game->player.x, --game->player.y, -1, 0);
    else if (keycode == 's' && game->map.array[game->player.y + 1][game->player.x] != '1')                                           
        move_player(game, game->player.x, ++game->player.y, 1, 0);  
    else if (keycode == 'a' && game->map.array[game->player.y][game->player.x - 1] != '1')                                           
        move_player(game, --game->player.x, game->player.y, 0, -1);
    else if (keycode == 'd' && game->map.array[game->player.y][game->player.x + 1] != '1')                                       
        move_player(game, ++game->player.x, game->player.y, 0, 1);
    else
        set_map(game);
    return (0);
}
int main(int ac, char **av)
{
    t_game game;

    if (ac != 2)
    {
        perror("Error\nInvalid argument count\n");
        return (1);
    }
    initialize_game(&game, av[1]);
    mlx_hook(game.win, 2, 1L<<0, key_hook, &game);
    mlx_hook(game.win, 17, 0, exit_game, &game);
    mlx_loop(game.mlx);
    exit_game(&game, 0);
    return (0);
}
