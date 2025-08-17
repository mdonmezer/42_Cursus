/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdonmeze <mdonmeze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 19:35:40 by mdonmeze          #+#    #+#             */
/*   Updated: 2025/04/08 03:21:20 by mdonmeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**duplicate_map(t_game *game)
{
	char	**copy;
	int		i;

	copy = (char **)malloc(sizeof(char *) * (game->height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < game->height)
	{
		copy[i] = ft_strdup(game->map[i]);
		if (!copy[i])
		{
			while (i-- >= 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[game->height] = NULL;
	return (copy);
}

static void	flood_fill(char **map, int x, int y, int *reach_counts)
{
	if (map[y][x] == WALL || map[y][x] == 'V')
		return ;
	if (map[y][x] == COLLECTIBLE)
		reach_counts[0]++;
	if (map[y][x] == EXIT)
		reach_counts[1] = 1;
	map[y][x] = 'V';
	flood_fill(map, x + 1, y, reach_counts);
	flood_fill(map, x - 1, y, reach_counts);
	flood_fill(map, x, y + 1, reach_counts);
	flood_fill(map, x, y - 1, reach_counts);
}

int	check_valid_path(t_game *game)
{
	char	**temp_map;
	int		reach_counts[2];
	int		i;

	ft_memset(reach_counts, 0, sizeof(int) * 2);
	temp_map = duplicate_map(game);
	if (!temp_map)
		return (0);
	flood_fill(temp_map, game->player_x, game->player_y, reach_counts);
	i = 0;
	while (i < game->height)
		free(temp_map[i++]);
	free(temp_map);
	if (reach_counts[0] != game->collectibles || reach_counts[1] != 1)
	{
		ft_printf("Error\nUnreachable collectible or exit on the map\n");
		return (0);
	}
	return (1);
}
