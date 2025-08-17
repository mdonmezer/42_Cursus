/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdonmeze <mdonmeze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 19:11:22 by mdonmeze          #+#    #+#             */
/*   Updated: 2025/04/08 11:01:22 by mdonmeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <fcntl.h>
# include <ft_printf.h>
# include <libft.h>
# include <mlx.h>

# define EMPTY '0'
# define WALL '1'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define PLAYER 'P'

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		collectibles;
	int		collected;
	int		moves;
	int		exit_x;
	int		exit_y;

	void	*wall;
	void	*empty;
	void	*player;
	void	*collectible;
	void	*exit;
}t_game;

typedef struct s_img {
	void	*img;
	int		width;
	int		height;
}	t_img;

void	cleanup_and_exit(t_game *game, int exit_code);
int		read_map(t_game *game, char *filename);
void	free_map(t_game *game);
int		validate_map(t_game *game);
int		init_mlx(t_game *game);
void	cleanup_mlx(t_game *game);
int		load_images(t_game *game);
void	render_map(t_game *game);
void	cleanup_images(t_game *game);
int		key_hook(int keycode, t_game *game);
char	*get_next_line(int fd);
int		check_valid_path(t_game *game);
int		arg_check(int ac, char **av);

#endif
