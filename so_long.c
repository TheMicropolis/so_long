/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:20:13 by mmauri            #+#    #+#             */
/*   Updated: 2025/01/16 12:20:19 by mmauri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void handle_exit(t_game *game, int x, int y)
{
	if (game->map.array[y][x] == 'E' && game->player.collectibles == game->map.collectibles)
	{
		game->map.array[y][x] = 'P';
		ft_printf("You won!\n");
		exit_game(game, 0);
	}
	if (game->map.array[y][x] == 'E' && game->player.collectibles != game->map.collectibles)
	{
		game->map.exit_x = x;
		game->map.exit_y = y;
	}
}

void move_player(t_game *game, int x, int y)
{
	int	dx;
	int	dy;

	dx = x - game->player.x;
	dy = y - game->player.y;
    if (game->map.array == NULL || y < 0 || x < 0 || y >= game->map.map_height || x >= game->map.map_width)
        exit_game(game, 1);

    else if (game->map.array[y][x] == 'C')
    {
        game->player.collectibles++;
        ft_printf("You collected %d out of %d item(s)!\n", game->player.collectibles, game->map.collectibles);
    }
    else if (game->map.array[y][x] == 'E')
		handle_exit(game, x, y);
	if ((game->player.y == game->map.exit_y) && (game->player.x == game->map.exit_x))
        game->map.array[y - dy][x - dx] = 'E';
    else
        game->map.array[y - dy][x - dx] = '0';
    game->player.moves++;
	game->player.x += dx;
	game->player.y += dy;
    game->map.array[y][x] = 'P';
    ft_printf("Moves: %d\n", game->player.moves);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 17)
		exit_game(game, 0);
	else if (keycode == 65307)
		exit_game(game, 0);
	else if (keycode == 'w'
		&& game->map.array[game->player.y - 1][game->player.x] != '1')
		move_player(game, game->player.x, game->player.y - 1);
	else if (keycode == 's'
		&& game->map.array[game->player.y + 1][game->player.x] != '1')
		move_player(game, game->player.x, game->player.y + 1);
	else if (keycode == 'a'
		&& game->map.array[game->player.y][game->player.x - 1] != '1')
		move_player(game, game->player.x - 1, game->player.y);
	else if (keycode == 'd'
		&& game->map.array[game->player.y][game->player.x + 1] != '1')
		move_player(game, game->player.x + 1, game->player.y);
	set_map(game);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;
	int	i;

	i = 0;
	if (ac != 2)
	{
		perror("Error\nInvalid argument count\n");
		return (1);
	}
	while (av[1][i])
		i++;
	if (!(ft_isalnum(av[1][i - 5]) && av[1][i - 4] == '.'&&
		av[1][i - 3] == 'b' && av[1][i - 2] == 'e' && av[1][i - 1] == 'r'))
	{
		perror("Error\nNo \".ber\" file!\n");
		return (1);
	}
	initialize_game(&game, av[1]);
	mlx_hook(game.win, 2, 1L << 0, key_hook, &game);
	mlx_hook(game.win, 17, 0, exit_game, &game);
	mlx_loop(game.mlx);
	exit_game(&game, 0);
	return (0);
}