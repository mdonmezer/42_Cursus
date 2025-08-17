/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdonmeze <mdonmeze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 19:25:32 by mdonmeze          #+#    #+#             */
/*   Updated: 2025/04/08 10:53:06 by mdonmeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	arg_check(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac != 2 || !av[1] || av[1][0] == '\0')
	{
		ft_printf("Usage: %s <map's path>\n", av[0]);
		return (0);
	}
	while (av[1][i] && av[1][i] != '.')
		i++;
	if (av[1][0] == '.')
		return (0);
	if (av[1][i - 1] != '/' && av[1][i] == '.' && av[1][i + 1] == 'b'
		&& av[1][i + 2] == 'e' && av[1][i + 3] == 'r' && av[1][i + 4] == '\0')
		return (1);
	return (0);
}

static void	clean_gnl_buffer(int fd)
{
	char	*tmp;

	tmp = get_next_line(fd);
	while (tmp)
	{
		free(tmp);
		tmp = get_next_line(fd);
	}
}

static int	handle_map_error(char *msg, char *tmp, char *line, int fd)
{
	ft_printf("Error\n%s\n", msg);
	if (tmp)
		free (tmp);
	if (line)
		free(line);
	clean_gnl_buffer(fd);
	close(fd);
	return (0);
}

static int	read_map_lines(t_game *game, int fd, char **line)
{
	char	*tmp;

	tmp = get_next_line(fd);
	while (tmp)
	{
		if (tmp[0] == '\n' || tmp[0] == '\0')
			return (handle_map_error
				("Error\nMap contains empty lines\n", tmp, *line, fd));
		if (!*line)
			*line = ft_strdup(tmp);
		else
			*line = ft_strjoin(*line, tmp);
		if (!*line)
			return (handle_map_error
				("Error\nMemory allocation failed\n", tmp, NULL, fd));
		game->height++;
		free(tmp);
		tmp = get_next_line(fd);
	}
	return (1);
}

int	read_map(t_game *game, char *filename)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open(filename, O_RDONLY, 0644);
	if (fd < 0)
		return (handle_map_error("Error\nCould not open file\n", NULL, NULL, fd));
	if (!read_map_lines(game, fd, &line))
		return (0);
	if (!line)
		return (handle_map_error("Error\nMap file is empty\n", NULL, NULL, fd));
	game->map = ft_split(line, '\n');
	free(line);
	clean_gnl_buffer(fd);
	close(fd);
	return (1);
}
