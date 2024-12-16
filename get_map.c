#include "so_long.h"
#include "libft/libft.h"

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
void    format_map(char *ber, t_game *game)
{
    int y;

    game->map.array = ft_split(ber, '\n'); 
    if (!game->map.array)
    {
        perror("Error\nMap-Error\n");
        exit_game(game, 1);
    }
    y = 0;
    while (y < game->map.map_height)
    {
        if (!game->map.array[y])
        {
            free_array(game);
            perror("Error\nError creating map\n");
            exit_game(game, 1);
        }
        y++;
    }
    check_format(game);
}
void    get_line(t_game *game, int fd)
{
    char *line;
    char *temp;

    while ((line = get_next_line(fd)) != NULL)
    {
        if (!line)
        {
            perror("Error\nError reading map\n");
            free(game->map.map);
            exit_game(game, 1);
        }
        temp = game->map.map;
        game->map.map = ft_strjoin_gnl(temp, line);
        if (temp)
            free(temp);
        free(line);
        if (!game->map.map)
        {
            close(fd);
            perror("Error\nError constructing map\n");
            exit_game(game, 1);
        }
    }
}
void   get_map(char *argv, t_game *game)
{
    int fd;

    fd = open(argv, O_RDONLY);
    if (fd == -1)
    {
    	perror("Error\nError opening file\n");
        exit_game(game, 1);
    }
    get_line(game, fd);
    if (!game->map.map || !*game->map.map)
    {
        perror("Error\nEmpty map file\n");
        exit_game(game, 1);
    }
    close(fd);
    check_map(game->map.map, game);
    format_map(game->map.map, game);
    if (!game->map.map)
    {
        perror("Error\nError creating map1\n");
        exit_game(game, 1);
    }
}
