/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 14:42:13 by mmauri            #+#    #+#             */
/*   Updated: 2025/02/02 14:42:16 by mmauri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_fd(char *argv, t_game *game)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
	{
		perror("Error\nError opening file\n");
		exit_game(game, 1);
	}
	/*game->map.map = ft_strdup_gnl("");
	if (!game->map.map)
	{
		close(fd);
		perror("Error\nError creating map (ft_strdup)!\n");
		exit_game(game, 1);
	}*/
	return (fd);
}

void	check_nl(char *ber, t_game *game)
{
	int	i;

	i = 0;
	while (ber[i] && ber[i + 1])
	{
		if (ber[i] == '\n' && ber[i + 1] == '\n')
		{
			perror("Error\nEmpty line in map!\n");
			exit_game(game, 1);
		}
		i++;
	}
	return ;
}

void	check_horizontal_walls(t_game *game)
{
	int	x;

	x = 0;
	while (x < game->map.map_width)
	{
		if (game->map.array[0][x] != '1')
		{
			perror("Error\nHorizontal Walls not closed\n");
			exit_game(game, 1);
		}
		x++;
	}
	x = 0;
	while (x < game->map.map_width)
	{
		if (game->map.array[game->map.map_height - 1][x] != '1')
		{
			perror("Error\nHorizontal Walls not closed\n");
			exit_game(game, 1);
		}
		x++;
	}
}

void	check_vertical_walls(t_game *game)
{
	int	y;

	y = 0;
	while (y < game->map.map_height)
	{
		if (game->map.array[y][0] != '1')
		{
			perror("Error\nVertical Walls not closed\n");
			exit_game(game, 1);
		}
		y++;
	}
	y = 0;
	while (y < game->map.map_height)
	{
		if (game->map.array[y][game->map.map_width - 1] != '1')
		{
			perror("Error\nVertical Walls not closed\n");
			exit_game(game, 1);
		}
		y++;
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
