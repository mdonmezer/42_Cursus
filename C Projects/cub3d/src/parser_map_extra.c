/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map_extra.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfirat <rfirat@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:05:00 by anon             #+#    #+#             */
/*   Updated: 2025/10/31 14:05:00 by anon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	validate_line_chars(const char *line, int *player_count)
{
	int		i;
	char	c;

	i = 0;
	while (line[i] != '\0')
	{
		c = line[i];
		if (!(c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E'
				|| c == 'W'))
		{
			printf(ERR_PREFIX ERR_INVALID_CHAR_OR_SPACE_IN_MAP);
			return (-1);
		}
		if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
			(*player_count)++;
		i++;
	}
	return (0);
}

int	validate_chars_and_player(t_scene *s)
{
	int	h;
	int	player_count;

	player_count = 0;
	h = 0;
	while (h < s->map_height)
	{
		if (validate_line_chars(s->map_lines[h], &player_count) != 0)
			return (-1);
		h++;
	}
	if (player_count != 1)
	{
		printf(ERR_PREFIX ERR_MAP_PLAYER_COUNT);
		return (-1);
	}
	return (0);
}

static int	is_player_or_floor(char c)
{
	return (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static int	check_adjacents(t_adj_vars *vars, t_scene *s)
{
	int	k;

	k = 0;
	while (k < 4)
	{
		vars->nh = vars->h + vars->dr[k];
		vars->ni = vars->i + vars->dc[k];
		if (vars->nh >= 0 && vars->nh < s->map_height && vars->ni >= 0
			&& vars->ni < (int)ft_strlen(s->map_lines[vars->nh])
			&& s->map_lines[vars->nh][vars->ni] == ' ')
		{
			printf(ERR_PREFIX "Map error: Floor or player is"
				"adjacent to a space.\n");
			return (-1);
		}
		k++;
	}
	return (0);
}

int	validate_space_adjancency(t_scene *s)
{
	t_adj_vars	vars;
	const int	temp_dr[] = {-1, 1, 0, 0};
	const int	temp_dc[] = {0, 0, -1, 1};

	ft_memcpy(vars.dr, temp_dr, sizeof(temp_dr));
	ft_memcpy(vars.dc, temp_dc, sizeof(temp_dc));
	vars.h = 0;
	while (vars.h < s->map_height)
	{
		vars.i = 0;
		while (vars.i < (int)ft_strlen(s->map_lines[vars.h]))
		{
			if (is_player_or_floor(s->map_lines[vars.h][vars.i]))
			{
				if (check_adjacents(&vars, s) != 0)
					return (-1);
			}
			vars.i++;
		}
		vars.h++;
	}
	return (0);
}
