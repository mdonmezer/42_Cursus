/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdonmeze <mdonmeze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 20:25:36 by mdonmeze          #+#    #+#             */
/*   Updated: 2025/04/08 03:21:54 by mdonmeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_player(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] == EXIT)
		game->map[new_y][new_x] = '2';
	else
		game->map[new_y][new_x] = PLAYER;
	if (game->map[game->player_y][game->player_x] == '2')
		game->map[game->player_y][game->player_x] = 'E';
	else
		game->map[game->player_y][game->player_x] = EMPTY;
	game->player_x = new_x;
	game->player_y = new_y;
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
}

static int	is_valid_move(t_game *game, int x, int y)
{
	if (game->map[y][x] == WALL)
		return (0);
	else if (game->map[y][x] == EXIT && game->collected != game->collectibles)
	{
		ft_printf("Collect all items first\n");
		return (1);
	}
	return (1);
}

static void	try_move(t_game *game, int x, int y)
{
	if (!is_valid_move(game, x, y))
		return ;
	if (game->map[y][x] == COLLECTIBLE)
	{
		game->collected++;
		ft_printf("Collected: %d/%d\n", game->collected, game->collectibles);
	}
	else if (game->map[y][x] == EXIT && game->collected == game->collectibles)
	{
		ft_printf("Congratulations! You completed the level in %d moves.\n",
			game->moves + 1);
		cleanup_and_exit(game, 0);
	}
	move_player(game, x, y);
	render_map(game);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
	{
		ft_printf("Game closed\n");
		cleanup_and_exit(game, 0);
	}
	else if (keycode == KEY_W)
		try_move(game, game->player_x, game->player_y - 1);
	else if (keycode == KEY_A)
		try_move(game, game->player_x - 1, game->player_y);
	else if (keycode == KEY_S)
		try_move(game, game->player_x, game->player_y + 1);
	else if (keycode == KEY_D)
		try_move(game, game->player_x + 1, game->player_y);
	render_map(game);
	return (0);
}
