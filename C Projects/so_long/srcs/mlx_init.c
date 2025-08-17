/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdonmeze <mdonmeze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 19:29:26 by mdonmeze          #+#    #+#             */
/*   Updated: 2025/04/08 09:02:18 by mdonmeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_mlx(t_game *game)
{
	int	win_width;
	int	win_height;

	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_printf("Error\nFailed to initialize MLX\n");
		return (0);
	}
	win_width = game->width * 64;
	win_height = game->height * 64;
	game->win = mlx_new_window(game->mlx, win_width, win_height, "so_long");
	if (!game->win)
	{
		ft_printf("Error\nFailed to create window\n");
		return (0);
	}
	ft_printf("Window dimensions: %d x %d\n", win_width, win_height);
	return (1);
}

void	cleanup_mlx(t_game *game)
{
	if (game && game->mlx)
	{
		cleanup_images(game);
		if (game->win)
		{
			mlx_destroy_window(game->mlx, game->win);
			game->win = NULL;
		}
		if (game->mlx)
		{
			mlx_destroy_display(game->mlx);
			free(game->mlx);
			game->mlx = NULL;
		}
	}
}
