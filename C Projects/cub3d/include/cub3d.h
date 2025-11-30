/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfirat <rfirat@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:19:31 by rfirat            #+#    #+#             */
/*   Updated: 2025/11/28 17:10:26 by rfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <errno.h>

// Colors
# define C_RESET "\x1b[0m"
# define C_BOLD "\x1b[1m"
# define C_DIM "\x1b[2m"
# define C_ITALIC "\x1b[3m"
# define C_UNDER "\x1b[4m"
# define C_BLACK "\x1b[30m"
# define C_RED "\x1b[31m"
# define C_GREEN "\x1b[32m"
# define C_YELLOW "\x1b[33m"
# define C_BLUE "\x1b[34m"
# define C_MAGENTA "\x1b[35m"
# define C_CYAN "\x1b[36m"
# define C_WHITE "\x1b[37m"
# define C_BBLACK "\x1b[90m"
# define C_BRED "\x1b[91m"
# define C_BGREEN "\x1b[92m"
# define C_BYELLOW "\x1b[93m"
# define C_BBLUE "\x1b[94m"
# define C_BMAGENTA "\x1b[95m"
# define C_BCYAN "\x1b[96m"
# define C_BWHITE "\x1b[97m"

// Error Messages
# define ERR_PREFIX "\x1b[91mError\n\x1b[0m"
# define ERR_INVALID_FLOOR_COLOR "invalid floor color format\n"
# define ERR_INVALID_CEILING_COLOR "invalid ceiling color format\n"
# define ERR_EMPTY_LINE_INSIDE_MAP "empty line inside map\n"
# define ERR_INVALID_CHAR_OR_SPACE_IN_MAP "invalid character or space in map\n"
# define ERR_INVALID_CHARACTER_IN_MAP "invalid character in map\n"
# define ERR_MISSING_TEXTURE_PATHS "missing one or more texture paths\n"
# define ERR_MISSING_FLOOR_OR_CEILING "missing floor or ceiling color (F/C)\n"
# define ERR_MISSING_MAP_CONTENT "missing map content\n"
# define ERR_MAP_TOO_SMALL "map too small\n"
# define ERR_MAP_NOT_CLOSED "map not closed (flood fill)\n"
# define ERR_MAP_PLAYER_COUNT "map must contain exactly one player (N/S/E/W)\n"
# define ERR_FAILED_LOAD_NORTH_FMT "Failed to load North texture: %s\n"
# define ERR_FAILED_LOAD_SOUTH_FMT "Failed to load South texture: %s\n"
# define ERR_FAILED_LOAD_EAST_FMT "Failed to load East texture: %s\n"
# define ERR_FAILED_LOAD_WEST_FMT "Failed to load West texture: %s\n"
# define ERR_FAILED_INIT_MLX "Failed to initialize MLX\n"
# define ERR_FAILED_CREATE_WINDOW "Failed to create window\n"
# define ERR_FAILED_CREATE_IMAGE "Failed to create image\n"
# define ERR_FAILED_LOAD_TEXTURES "Failed to load textures\n"
# define ERR_FAILED_OPEN_FILE_FMT "failed to open file: '%s' (%s)\n"
# define ERR_MISSING_OR_EXTRA_ARG "missing or extra argument.\n"
# define ERR_MAP_EXTENSION_FMT "map file must have '%s' extension.\n"
# define ERR_HIDDEN_CUB_NAME "hidden .cub filename is not allowed.\n"

// MLX settings
# define WIN_WIDTH 800
# define WIN_HEIGHT 600
# define WIN_TITLE "Cub3D"
# define FOV_PLANE 0.66
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define TEXTURE_NORTH 0
# define TEXTURE_SOUTH 1
# define TEXTURE_EAST 2
# define TEXTURE_WEST 3

// Type definitions
typedef struct s_gc_node
{
	void				*ptr;
	struct s_gc_node	*next;
}						t_gc_node;

typedef struct s_gc
{
	t_gc_node			*head;
}						t_gc;

typedef struct s_rgb
{
	int					r;
	int					g;
	int					b;
}						t_rgb;

typedef struct s_player
{
	double				x;
	double				y;
	double				angle;
	double				move_speed;
	double				rot_speed;
	double				mouse_sensitivity;
}						t_player;

typedef struct s_ray_result
{
	double				distance;
	int					wall_side;
	int					hit_dir;
	double				wall_x;
}						t_ray_result;

typedef struct s_ray
{
	double				camera_x;
	double				dir_x;
	double				dir_y;
	int					map_x;
	int					map_y;
	double				sidedist_x;
	double				sidedist_y;
	double				deltadist_x;
	double				deltadist_y;
	double				wall_dist;
	int					step_x;
	int					step_y;
	int					side;
	double				wall_x;
	int					line_height;
	int					draw_start;
	int					draw_end;
}						t_ray;

typedef struct s_texture
{
	void				*img_ptr;
	char				*img_data;
	int					width;
	int					height;
	int					bpp;
	int					line_length;
	int					endian;
}						t_texture;

typedef struct s_mlx
{
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr;
	char				*img_data;
	int					bpp;
	int					line_length;
	int					endian;
	int					width;
	int					height;
}						t_mlx;

typedef struct s_keys
{
	int					w;
	int					s;
	int					a;
	int					d;
	int					left;
	int					right;
	int					mouse_pressed;
}						t_keys;

typedef struct s_scene
{
	t_gc				gc;
	char				*no_path;
	char				*so_path;
	char				*we_path;
	char				*ea_path;
	t_rgb				floor_color;
	t_rgb				ceiling_color;
	char				**map_lines;
	int					map_height;
	int					map_width;
}						t_scene;

typedef struct s_cub
{
	struct s_scene		*scene_ref;
	t_mlx				mlx;
	t_player			player;
	t_texture			textures[4];
	t_keys				keys;
}						t_cub;

typedef struct s_dct_params
{
	t_cub				*cub;
	int					x;
	t_ray				*ray;
	int					texture_id;
	int					tex_x;
}						t_dct_params;

typedef struct s_vline
{
	int					y;
	int					tex_x;
	int					tex_y;
	double				step;
	double				tex_pos;
	int					color;
	int					texture_id;
	int					ceiling_color;
	int					floor_color;
}						t_vline;

typedef struct s_tw_params
{
	t_cub				*cub;
	int					x;
	int					texture_id;
	int					tex_x;
	double				step;
	double				tex_pos;
	int					draw_start;
	int					draw_end;
}						t_tw_params;

typedef struct s_normalize_row_params
{
	t_scene				*s;
	int					r;
	int					c;
	char				*row;
	char				*newrow;
}						t_normalize_row_params;

typedef struct s_line_params
{
	char				***arr;
	int					*count;
	int					cap;
	t_gc				*gc;
}						t_line_params;

typedef struct s_mapctx
{
	int					height;
	int					width;
	int					h;
	int					i;
	int					player_count;
	char				c;
	char				**grid;
	int					row;
	int					col;
	int					lenrow;
	int					rr;
	char				tile;
	struct s_scene		*scene;
}						t_mapctx;

typedef struct s_process_neighbor_params
{
	t_mapctx			*ctx;
	int					*stack;
	int					*stack_top;
	int					r;
	int					c;
}						t_process_neighbor_params;

typedef struct s_flood_init_params
{
	t_scene				*s;
	t_mapctx			*ctx;
	int					sr;
	int					sc;
	int					**out_stack;
	int					*out_stack_top;
	int					(*dr)[4];
	int					(*dc)[4];
}						t_flood_init_params;

typedef struct s_parsectx
{
	char				**lines;
	int					line_count;
	int					i;
	int					map_started;
	char				err[256];
	const char			*line;
}						t_parsectx;

typedef struct s_adj_vars
{
	int		h;
	int		i;
	int		dr[4];
	int		dc[4];
	int		nh;
	int		ni;
}			t_adj_vars;

// Garbage Collector
void					gc_init(t_gc *gc);
int						gc_register(t_gc *gc, void *ptr);
void					*gc_malloc(t_gc *gc, size_t size);
void					*gc_calloc(t_gc *gc, size_t count, size_t size);
char					*gc_strdup(t_gc *gc, const char *s);
void					gc_free_all(t_gc *gc);

// String Utils
size_t					ft_strlen(const char *s);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
int						ft_strendswith(const char *s, const char *suffix);
const char				*ft_basename(const char *path);
int						ft_is_space(int c);
int						ft_is_digit(int c);
long					ft_atoi_pos(const char *s, int *ok);
int						ft_max(int a, int b);
char					*gc_strtrim(t_gc *gc, const char *s);

// Parser
int						parse_scene(const char *path, t_scene *out_scene);
void					free_scene(t_scene *scene);

// Validation
int						validate_arguments(int argc, char **argv,
							const char **map_path);

// Debug
void					debug_print_scene(const t_scene *s);

// MLX
void					init_mlx_struct(t_cub *cub);
int						init_mlx_and_start(t_cub *cub);
void					init_player(t_cub *cub);
int						find_player_spawn(t_cub *cub);
int						load_textures(t_cub *cub);
int						get_texture_pixel(t_cub *cub, int texture_id, int x,
							int y);
int						close_window(t_cub *cub);
int						expose_hook(t_cub *cub);
int						key_press(int keycode, t_cub *cub);
int						key_release(int keycode, t_cub *cub);
int						mouse_hook(int x, int y, t_cub *cub);
int						mouse_press(int button, int x, int y, t_cub *cub);
int						mouse_release(int button, int x, int y, t_cub *cub);
int						game_loop(t_cub *cub);
void					hide_mouse_cursor(t_cub *cub);
void					cleanup_mlx_resources(t_cub *cub);
void					raycasting(t_cub *cub);
void					render_frame(t_cub *cub);
int						is_wall(t_cub *cub, double x, double y);
int						check_collision(t_cub *cub, double new_x, double new_y);
void					move_player(t_cub *cub, double dx, double dy);
void					rotate_player(t_cub *cub, double rotation_speed);

int						is_identifier_line(const char *line);
int						read_lines_from_fd(int fd, t_line_params *p);

int						init_line_params(t_line_params *p, t_gc *gc,
							char ***arr, int *count);
int						is_walkable(char t);
void					init_mapctx(t_mapctx *ctx, t_scene *s);
int						validate_chars_and_player(t_scene *s);
int						build_padded_grid(t_scene *s, t_mapctx *ctx);
void					copy_map_into_grid(t_scene *s, t_mapctx *ctx);
int						draw_column_texture(t_dct_params *p, t_cub *cub);
void					draw_column_floor(t_cub *cub, int x, int start_y);
void					set_dda(t_ray *ray, t_cub *cub);
void					perform_dda(t_scene *s, t_ray *ray);
void					calculate_line_height(t_ray *ray, t_cub *cub);
void					clear_image(t_cub *cub);
const char				*skip_spaces(const char *p);
int						parse_rgb_triplet(const char *s, t_rgb *out);
int						load_textures(t_cub *cub);
int						is_valid_map_row(const char *line);
int						append_map_line(t_scene *s, const char *line);
int						handle_identifier_line(t_scene *scene,
							const char *line);
int						is_map_line(const char *line);
int						normalize_map(t_scene *s);
int						validate_map_content(t_scene *s, char *errbuf,
							size_t errcap);
int						validate_space_adjancency(t_scene *s);
void					scene_init(t_scene *s);
int						read_lines_with_gnl(const char *path, char ***out_lines,
							int *out_count, t_gc *gc);
int						handle_line(t_parsectx *ctx, t_scene *scene, int *stop);
int						finalize_scene(t_scene *scene, t_parsectx *ctx);
int						cleanup_parse_failure(t_scene *scene);
void					*ft_calloc(unsigned int count, unsigned int size);
void					*ft_memcpy(void	*out, const void *src,
							unsigned int len);
#endif
