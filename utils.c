/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:23:04 by mmauri            #+#    #+#             */
/*   Updated: 2025/01/16 12:23:06 by mmauri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_player_pos(t_game *game, int x, int y)
{
	if (game->player.x == 0 && game->player.y == 0)
	{
		game->player.x = x;
		game->player.y = y;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->player.player,
		game->player.x * PIXEL, game->player.y * PIXEL);
}

void	flood(t_game *game, int x, int y)
{	
	if (x < 1 || y < 1 || x >= game->map.map_width - 1|| y >= game->map.map_height - 1)
		return ;
	if (game->map.copy[y][x] == 'P' || game->map.copy[y][x] == 'C' 
		|| game->map.copy[y][x] == 'E' || game->map.copy[y][x] == '0')
	{
		game->map.copy[y][x] = 'X';
		flood(game, x + 1, y);
		flood(game, x - 1, y);
		flood(game, x, y + 1);
		flood(game, x, y - 1);
	}
}
void	reachable(t_game *game)
{
	int y;

	y = 0;
    while (game->map.copy[y])
    {
        if (ft_strchr(game->map.copy[y], 'E') || ft_strchr(game->map.copy[y], 'C'))
        {
            perror("Error\nNot all exits or collectibles reachable!");
            exit_game(game, 1);
        }
        y++;
    }
}

void	floodfill(t_game *game)
{
	int	x;
	int	y;

    y = 0;
    while (game->map.array[y])
    {
        x = 0;
        while (game->map.array[y][x])
        {
            if (game->map.array[y][x] == 'P')
            {
                game->player.x = x;
                game->player.y = y;
                break;
            }
            x++;
        }
        y++;
    }
	flood(game, game->player.x, game->player.y);
	reachable(game);
}

void	check_format(t_game *game)
{
	int	y;

	y = 0;
	while (game->map.array[y] && game->map.array[y + 1]
		&& (ft_strlen(game->map.array[y]) == ft_strlen(game->map.array[y + 1])))
		y++;
	if (game->map.array[y + 1] != NULL)
	{
		free_array(game->map.array);
		perror("Error\nMap  not rectangular\n");
		exit_game(game, 1);
	}
	game->map.map_height = y + 1;
	game->map.map_width = ft_strlen(game->map.array[0]);
	if (game->map.map_height < 3 || game->map.map_width < 3)
	{
		free_array(game->map.array);
		perror("Error\nMap too small\n");
		exit_game(game, 1);
	}
}

void	error_map(int players, int exits, int collectibles, t_game *game)
{
	if (players != 1)
	{
		ft_printf("Too many Players\n");
		exit_game(game, 1);
	}
	if (collectibles < 1)
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

void	check_map(char *ber, t_game *game)
{
	int	i;
	int	players;
	int	exits;

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
