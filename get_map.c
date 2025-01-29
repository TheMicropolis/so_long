/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:20:57 by mmauri            #+#    #+#             */
/*   Updated: 2025/01/16 12:20:59 by mmauri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_horizontal_walls(t_game *game)
{
	int	x;

	x = 0;
	while (x < game->map.map_width)
	{
		if (game->map.array[0][x] != '1')
		{
			free_array(game->map.array);
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
			free_array(game->map.array);
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

void	format_map(char ***ber, t_game *game)
{
	int	y;

	*ber = ft_split(game->map.map, '\n');
	if (!(*ber))
	{
		perror("Error\nMap-Error\n");
		exit_game(game, 1);
	}
	y = 0;
	while (y < game->map.map_height)
	{
		if (!(*ber)[y])
		{
			free_array(*ber);
			perror("Error\nError creating map\n");
			exit_game(game, 1);
		}
		y++;
	}
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

void	get_line(t_game *game, int fd)
{
	char	*line;
	char	*temp;

	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		exit_game(game, 1);
	}
	while (line != NULL)
	{
		temp = game->map.map;
		game->map.map = ft_strjoin_gnl(temp, line);
		if (!game->map.map)
		{
			free(temp);
			free(line);
			perror("Error\nError constructing map\n");
			exit_game(game, 1);
		}
		free(line);
		free(temp);
		line = get_next_line(fd);
	}
	close(fd);
}

void	check_fd(char *argv, t_game *game)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		perror("Error\nError opening file\n");
		exit_game(game, 1);
	}
	get_line(game, fd);
	close(fd);
	if (!game->map.map || !*game->map.map)
	{
		perror("Error\nEmpty map file\n");
		exit_game(game, 1);
	}
}

void	get_map(char *argv, t_game *game)
{
	check_fd(argv, game);
	check_nl(game->map.map, game);
	check_map(game->map.map, game);
	format_map(&game->map.array, game);
	format_map(&game->map.copy, game);
	check_format(game);
	check_horizontal_walls(game);
	check_vertical_walls(game);
	floodfill(game);
}
