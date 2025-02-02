/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:21:12 by mmauri            #+#    #+#             */
/*   Updated: 2025/01/16 12:22:52 by mmauri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.map_height)
	{
		x = 0;
		while (x < game->map.map_width)
		{
			if (game->map.array[y][x] == '0')
				mlx_put_image_to_window(game->mlx, game->win,
					game->map.ground, x * PIXEL, y * PIXEL);
			else if (game->map.array[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win,
					game->map.exit, x * PIXEL, y * PIXEL);
			else if (game->map.array[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win,
					game->map.collectible_img, x * PIXEL, y * PIXEL);
			else if (game->map.array[y][x] == 'P')
				update_player_pos(game, x, y);
			x++;
		}
		y++;
	}
}

void	set_walls(t_game *game)
{
	int	x;
	int	y;

	if (!game->map.array || !game->mlx || !game->win)
	{
		perror("Error\nFailed to load map or initilizing Minilibx\n");
		exit_game(game, 1);
	}
	if (!game->map.wall)
	{
		perror("Error\nDidn't load wall image\n");
		exit_game(game, 1);
	}
	y = 0;
	while (y < game->map.map_height)
	{
		x = -1;
		while (++x < game->map.map_width)
		{
			if (game->map.array[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win,
					game->map.wall, x * PIXEL, y * PIXEL);
		}
		y++;
	}
}

int	load_images(t_game *game)
{
	int	width;
	int	height;

	if (!game->mlx && game->win)
	{
		perror("Error\nFailed to initialize Minilibx\n");
		exit_game(game, 1);
	}
	game->map.ground = mlx_xpm_file_to_image(game->mlx,
			"textures/ground.xpm", &width, &height);
	game->map.wall = mlx_xpm_file_to_image(game->mlx,
			"textures/wall.xpm", &width, &height);
	game->map.exit = mlx_xpm_file_to_image(game->mlx,
			"textures/exit.xpm", &width, &height);
	game->map.collectible_img = mlx_xpm_file_to_image(game->mlx,
			"textures/collect.xpm", &width, &height);
	game->player.player = mlx_xpm_file_to_image(game->mlx,
			"textures/player.xpm", &width, &height);
	if (!game->map.ground || !game->map.wall || !game->map.exit
		|| !game->map.collectible_img || !game->player.player)
	{
		perror("Error\nFailed to load image(s)!\n");
		exit_game(game, 1);
	}
	return (1);
}

void	set_null(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->map.ground = NULL;
	game->map.wall = NULL;
	game->map.collectible_img = NULL;
	game->map.collectibles = 0;
	game->map.exit = NULL;
	game->map.array = NULL;
	game->map.copy = NULL;
	game->map.map_height = 0;
	game->map.map_width = 0;
	game->map.map = NULL;
	game->map.exit_x = 0;
	game->map.exit_y = 0;
	game->player.player = NULL;
	game->player.x = 0;
	game->player.y = 0;
	game->player.collectibles = 0;
	game->player.moves = 0;
}

void	initialize_game(t_game *game, char *argv)
{
	set_null(game);
	get_map(argv, game);
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		perror("Error\nFailed to initialize Minilibx\n");
		exit_game(game, 1);
	}
	game->win = mlx_new_window(game->mlx, game->map.map_width * PIXEL,
			game->map.map_height * PIXEL, "so_long");
	if (!game->win)
	{
		perror("Error\nFailed to initialize Window\n");
		exit_game(game, 1);
	}
	if (load_images(game) != 1)
	{
		perror("Error\nError loading image(s)\n");
		exit_game(game, 1);
	}
	set_walls(game);
	set_map(game);
}
