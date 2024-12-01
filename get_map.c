#include "so_long.h"
#include "libft/libft.h"

void check_map(char *ber)
{
    t_map map;
    int i;
    int x;

    i = 0;
    while (ber[i])
    {
       if (ft_strchr("01PEC\n", ber[i]))
            i++;
        else
        {
            printf("unallowed character in map\n");
            exit(1);
        }
    }
    i = 0;
    while (ber[i])
    {
        if (ber[i] == 'C')
            map.collectibles++;
        i++;
    }
    if  (map.collectibles < 1)
    {
        printf("not enough collectibles\n");
        exit(1);
    }
    i = 0;
    x = 0;
    while (ber[i])
    {
        if (ber[i] == 'E')
            x++;
        i++;
    }
    if (x != 1)
    {
        printf("Too many exits\n");
        exit(1);
    }
}

void    format_map(char *ber, t_game *game)
{
    int y;


    y = 0;
    game->map.array = ft_split(ber, '\n');
    if (!game->map.array)
    {
        printf("Map-Error\n");
        exit(1);
    }
    while (game->map.array[y] && game->map.array[y + 1] && (ft_strlen(game->map.array[y]) == ft_strlen(game->map.array[y + 1])))
    {
        y++;
    } 
    if (game->map.array[y + 1] != NULL)
    {
        printf("Map  not rectangular\n");
        exit(1);
    }  
    game->map.map_height = y + 1;
    game->map.map_width = ft_strlen(game->map.array[0]);
}

void   get_map(char *argv, t_game *game)
{
    char *map;
    char *line;
    int fd;
    map = ft_strdup_gnl("");
    if (!map)
    {
        printf("Allocation error\n");
    }
    fd = open(argv, O_RDONLY);
    if (fd == -1)
    {
    	printf("Error opening file\n");
    }
    while ((line = get_next_line(fd)) != NULL)
    {
        map = ft_strjoin_gnl(map, line);
        if (!map)
        {
            printf("Error constructing map\n");
        }
        free(line);
    }
    close(fd);
    printf("%s\n", map);
    check_map(map);
    format_map(map, game);
}