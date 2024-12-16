#include "so_long.h"

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
