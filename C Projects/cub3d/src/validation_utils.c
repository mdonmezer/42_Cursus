/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdonmeze <mdonmeze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 01:30:00 by rfirat            #+#    #+#             */
/*   Updated: 2025/08/30 00:38:13 by mdonmeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define REQUIRED_EXTENSION ".cub"

static void	print_usage(const char *prog)
{
	printf(C_BYELLOW "Usage: " C_RESET "%s <map.cub>\n", ft_basename(prog));
}

static int	has_required_extension(const char *path)
{
	return (ft_strendswith(path, REQUIRED_EXTENSION));
}

static int	is_hidden_cub_name(const char *path)
{
	const char	*base;

	base = ft_basename(path);
	if (base && base[0] == '.' && ft_strendswith(base, REQUIRED_EXTENSION))
		return (1);
	return (0);
}

static int	validate_file_openable(const char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		printf(ERR_PREFIX ERR_FAILED_OPEN_FILE_FMT, path, strerror(errno));
		return (-1);
	}
	close(fd);
	return (0);
}

int	validate_arguments(int argc, char **argv, const char **map_path)
{
	if (argc != 2)
	{
		printf(ERR_PREFIX ERR_MISSING_OR_EXTRA_ARG);
		print_usage(argv[0]);
		return (EXIT_FAILURE);
	}
	*map_path = argv[1];
	if (!has_required_extension(*map_path))
	{
		printf(ERR_PREFIX ERR_MAP_EXTENSION_FMT, REQUIRED_EXTENSION);
		return (EXIT_FAILURE);
	}
	if (is_hidden_cub_name(*map_path))
	{
		printf(ERR_PREFIX ERR_HIDDEN_CUB_NAME);
		return (EXIT_FAILURE);
	}
	if (validate_file_openable(*map_path) != 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
