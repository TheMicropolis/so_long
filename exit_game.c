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
	destroy_img(game->mlx, game->map.ground);
	destroy_img(game->mlx, game->map.collectible_img);
	destroy_img(game->mlx, game->map.wall);
	destroy_img(game->mlx, game->map.exit);
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
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	array = NULL;
}

int	exit_game(t_game *game, int code)
{
	free_img(game);
	if (game->win)
	{
		mlx_destroy_window(game->mlx, game->win);
		game->win = NULL;
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
