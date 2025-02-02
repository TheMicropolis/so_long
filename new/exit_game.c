/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:20:39 by mmauri            #+#    #+#             */
/*   Updated: 2025/01/16 12:20:42 by mmauri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

void	destroy_img(void *mlx, void *img)
{
	if (img)
	{
		mlx_destroy_image(mlx, img);
		img = NULL;
	}
}

void	free_img(t_game *game)
{
	if (game->map.ground)
		destroy_img(game->mlx, game->map.ground);
	if (game->map.collectible_img)
		destroy_img(game->mlx, game->map.collectible_img);
	if (game->map.wall)
		destroy_img(game->mlx, game->map.wall);
	if (game->map.exit)
		destroy_img(game->mlx, game->map.exit);
	if (game->player.player)
		destroy_img(game->mlx, game->player.player);
	if (game->map.map)
	{
		free(game->map.map);
		game->map.map = NULL;
	}
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	if (array)
	{
		while (array[i])
		{
			free(array[i]);
			array[i] = NULL;
			i++;
		}
		free(array);
		array = NULL;
	}
}

int	exit_game(t_game *game, int code)
{
	free_img(game);
	if (game->win)
	{
		mlx_destroy_window(game->mlx, game->win);
		game->win = NULL;
	}
	if (game->map.map)
	{
		free(game->map.map);
		game->map.map = NULL;
	}
	if (game->map.array)
		free_array(game->map.array);
	if (game->map.copy)
		free_array(game->map.copy);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
	}
	exit(code);
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
