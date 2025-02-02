void	exit_and_close(t_game *game, int fd, char *line, char  *temp)
{
	if (line)
		free(line);
	if (temp && temp != game->map.map)
		free(temp);
	close(fd);
	perror("Error\nError constructing map\n");
	exit_game(game, 1);
}
void	get_line(t_game *game, int fd)
{
	char	*line;
	char	*temp;
	char	*map;

	temp = NULL;
	line = get_next_line(fd);
	if (!line)
		exit_and_close(game, fd, line, temp);
	while (line != NULL)
	{
		temp = game->map.map;
		map = ft_strjoin_gnl(temp, line);
		if (!map)
			exit_and_close(game, fd, line, temp);
		free(line);
		line = NULL;
		game->map.map = map;
		line = get_next_line(fd);
		if (!line)
			exit_and_close(game, fd, line, temp);
	}
	if (line)
		free(line);
	if (temp && temp != game->map.map)
		free(temp);
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
			perror("Error\nError constructing map\n");
			close(fd);
			free(game->map.map);
			exit_game(game, 1);
		}
		game->map.map = map;
		line = get_next_line(fd);
		if (!line)
		{
			close(fd);
			exit_game(game, 1);
		}	
	}
	free(line);
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
