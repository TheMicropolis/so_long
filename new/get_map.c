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

void	format_map(char ***ber, t_game *game)
{
	*ber = ft_split(game->map.map, '\n');
	if (!(*ber))
	{
		perror("Error\nMap-Error\n");
		exit_game(game, 1);
	}
	/*y = 0;
	while ((*ber)[y])
	{
		if (!(*ber)[y])
		{
			perror("Error\nError creating map\n");
			exit_game(game, 1);
		}
		y++;
	}*/
}

void	get_line(t_game *game, int fd)
{
	char	*line;
	char	*temp;
	char	*map;

	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		exit_game(game, 1);
	}
	while (line != NULL)
	{
		temp = game->map.map;
		map = ft_strjoin_gnl(temp, line);
		free(line);
		if (!map)
		{
			if (temp)
				free(temp);
			perror("Error\nError constructing map\n");
			exit_game(game, 1);
		}
		if (temp)
				free(temp);
		game->map.map = map;
		line = get_next_line(fd);
	}
}

void	get_map(char *argv, t_game *game)
{
	get_line(game, check_fd(argv, game));
	check_nl(game->map.map, game);
	check_map(game->map.map, game);
	format_map(&game->map.array, game);
	format_map(&game->map.copy, game);
	check_format(game);
	check_horizontal_walls(game);
	check_vertical_walls(game);
	floodfill(game);
}
