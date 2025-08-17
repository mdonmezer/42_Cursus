/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdonmeze <mdonmeze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 22:30:08 by mdonmeze          #+#    #+#             */
/*   Updated: 2025/04/08 08:24:19 by mdonmeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_rectangular(t_game *game)
{
	int	i;
	int	len;

	if (game->height < 3 || game->width < 3)
	{
		ft_printf("Error\nMap must be at least 3x3\n");
		return (0);
	}
	i = 0;
	while (i < game->height - 1)
	{
		len = ft_strlen(game->map[i]);
		if (len != game->width)
		{
			ft_printf("Error\nMap must be rectangular\n");
			return (0);
		}
		i++;
	}
	return (1);
}

static int	is_sur_walls(t_game *game)
{
	int	i;

	i = 0;
	if (!game->map || !game->map[0])
		return (0);
	while (i < game->width)
	{
		if (game->map[0][i] != WALL || game->map[game->height - 1][i] != WALL)
		{
			ft_printf("Error\nMap must be surrounded by walls\n");
			return (0);
		}
		i++;
	}
	i = 0;
	while (i < game->height)
	{
		if (game->map[i][0] != WALL || game->map[i][game->width - 1] != WALL)
		{
			ft_printf("Error\nMap must be surrounded by walls\n");
			return (0);
		}
		i++;
	}
	return (1);
}

static void	check_character(t_game *game, int i, int j, int *counts)
{
	if (game->map[i][j] == EXIT)
		counts[0]++;
	else if (game->map[i][j] == PLAYER)
	{
		counts[1]++;
		game->player_x = j;
		game->player_y = i;
	}
	else if (game->map[i][j] == COLLECTIBLE)
		counts[2]++;
	else if (game->map[i][j] != EMPTY && game->map[i][j] != WALL)
	{
		ft_printf("Error\nInvalid character in map %c\n", game->map[i][j]);
		counts[3] = 1;
	}
}

static int	is_req_elements(t_game *game)
{
	int	i;
	int	j;
	int	counts[4];

	ft_memset(counts, 0, sizeof(counts));
	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			check_character(game, i, j, counts);
			j++;
		}
		i++;
	}
	if (counts[3] == 1)
		return (0);
	if (counts[0] != 1 || counts[1] != 1 || counts[2] < 1)
	{
		ft_printf("Error\nUse 1 exit, 1 player,and at least 1 collectible\n");
		return (0);
	}
	game->collectibles = counts[2];
	return (1);
}

int	validate_map(t_game *game)
{
	if (!is_rectangular(game))
		return (0);
	if (!is_sur_walls(game))
		return (0);
	if (!is_req_elements(game))
		return (0);
	if (!check_valid_path(game))
		return (0);
	return (1);
}
