#include "so_long.h"

void    update_player_pos(t_game *game, int x, int y)
{
    if (game->player.x == 0 && game->player.y == 0)
    {
        game->player.x = x;
        game->player.y = y;
    }
    mlx_put_image_to_window(game->mlx, game->win, game->player.player, game->player.x * PIXEL, game->player.y * PIXEL);         
}
void    check_format(t_game *game)
{
    int y;

    y = 0;
    while (game->map.array[y] && game->map.array[y + 1] && (ft_strlen(game->map.array[y]) == ft_strlen(game->map.array[y + 1])))
        y++;
    if (game->map.array[y + 1] != NULL)
    {
        free_array(game);
        perror("Error\nMap  not rectangular\n");
        exit_game(game, 1);
    }  
    game->map.map_height = y + 1;
    game->map.map_width = ft_strlen(game->map.array[0]);
    if (game->map.map_height < 3 || game->map.map_width < 3)
    {
        free_array(game);
        perror("Error\nMap too small\n");
        exit_game(game, 1);
    }
    if (!game->map.map)
    {
        free(game->map.map);
        game->map.map = NULL;
    }
}
void error_map(int players, int exits, int collectibles, t_game *game)
{
    if (players != 1)
    {
        ft_printf("Too many Players\n");
        exit_game(game, 1);
    }
    if  (collectibles < 1)
    {
        ft_printf("not enough collectibles\n");
        exit_game(game, 1);
    }
    if (exits != 1)
    {
        ft_printf("Too many exits\n");
        exit_game(game, 1);
    }
}
void check_map(char *ber, t_game *game)
{
    int i;
    int players;
    int exits;

    i = -1;
    players = 0;
    exits = 0;
    while (ber[++i])
    {
        if (ft_strchr_gnl("01PEC\n", ber[i]))
        {
            if (ber[i] == 'P')
                players++;
            else if (ber[i] == 'C') 
                game->map.collectibles++;
            else if (ber[i] == 'E')
                exits++;
        }
        else 
        {
            perror("Error\nUnallowed character in map!\n");
            exit_game(game, 1);
        }
    }
    error_map(players, exits, game->map.collectibles, game);
}