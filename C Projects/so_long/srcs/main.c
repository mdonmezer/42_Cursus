/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdonmeze <mdonmeze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 19:22:19 by mdonmeze          #+#    #+#             */
/*   Updated: 2025/04/08 09:32:08 by mdonmeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_game *game)
{
	int	i;

	if (!game->map)
		return ;
	i = 0;
	while (i < game->height)
	{
		if (game->map[i])
			free(game->map[i]);
		i++;
	}
	free(game->map);
	game->map = NULL;
}

void	cleanup_and_exit(t_game *game, int exit_code)
{
	free_map(game);
	cleanup_mlx(game);
	exit(exit_code);
}

static int	handle_close(t_game *game)
{
	ft_printf("Game closed\n");
	cleanup_and_exit(game, 0);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (!arg_check(ac, av))
	{
		ft_printf("Error\nUsage: ./so_long map_file.ber\n");
		return (1);
	}
	ft_memset(&game, 0, sizeof(t_game));
	if (read_map(&game, av[1]) == 0)
		cleanup_and_exit(&game, 1);
	game.width = (int)ft_strlen(game.map[0]);
	if (validate_map(&game) == 0)
		cleanup_and_exit(&game, 1);
	if (init_mlx(&game) == 0)
		cleanup_and_exit(&game, 1);
	if (load_images(&game) == 0)
	{
		ft_printf("Error\nFailed to load images\n");
		cleanup_and_exit(&game, 1);
	}
	render_map(&game);
	mlx_key_hook(game.win, key_hook, &game);
	mlx_hook(game.win, 17, 0, handle_close, &game);
	mlx_loop(game.mlx);
	return (0);
}
