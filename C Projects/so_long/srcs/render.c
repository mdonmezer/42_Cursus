/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdonmeze <mdonmeze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 20:15:28 by mdonmeze          #+#    #+#             */
/*   Updated: 2025/04/08 03:21:42 by mdonmeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*load_image(t_game *game, char *path)
{
	void	*img;
	int		width;
	int		height;

	img = mlx_xpm_file_to_image(game->mlx, path, &width, &height);
	if (!img)
		ft_printf("Error\nFailed to load image: %s\n", path);
	return (img);
}

int	load_images(t_game *game)
{
	ft_printf("Loading images...\n");
	game->wall = load_image(game, "textures/wall.xpm");
	game->empty = load_image(game, "textures/empty.xpm");
	game->player = load_image(game, "textures/player.xpm");
	game->collectible = load_image(game, "textures/collectible.xpm");
	game->exit = load_image(game, "textures/exit.xpm");
	if (!game->wall || !game->empty || !game->player
		|| !game->collectible || !game->exit)
	{
		ft_printf("Error\nFailed to load one or more images\n");
		return (0);
	}
	ft_printf("All images loaded successfully\n");
	return (1);
}

static void	draw_tile(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img, x * 64, y * 64);
}

void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			draw_tile(game, game->empty, x, y);
			if (game->map[y][x] == WALL)
				draw_tile(game, game->wall, x, y);
			else if (game->map[y][x] == PLAYER || game->map[y][x] == '2')
				draw_tile(game, game->player, x, y);
			else if (game->map[y][x] == COLLECTIBLE)
				draw_tile(game, game->collectible, x, y);
			else if (game->map[y][x] == EXIT)
				draw_tile(game, game->exit, x, y);
			x++;
		}
		y++;
	}
}

void	cleanup_images(t_game *game)
{
	if (game->mlx)
	{
		if (game->wall)
			mlx_destroy_image(game->mlx, game->wall);
		if (game->empty)
			mlx_destroy_image(game->mlx, game->empty);
		if (game->player)
			mlx_destroy_image(game->mlx, game->player);
		if (game->collectible)
			mlx_destroy_image(game->mlx, game->collectible);
		if (game->exit)
			mlx_destroy_image(game->mlx, game->exit);
	}
}
