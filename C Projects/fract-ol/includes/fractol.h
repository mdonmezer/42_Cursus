#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "../minilibx-linux/mlx.h"
# include "structs.h"
# include "keys.h"

# define WIDTH 800
# define HEIGHT 800

# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF

# define PSYCHEDELIC_PURPLE 0x660066
# define AQUA_DREAM 0x33CCCC
# define HOT_PINK 0xFF66B2
# define ELECTRIC_BLUE 0x0066FF
# define LAVA_RED 0xFF3300

// init
void    fractal_init(t_fractal *fractal);

// render
void    fractal_render(t_fractal *fractal);

// math
double  map(double unscaled_num, double new_min, double new_max, double old_min, double old_max);
t_complex   sum_complex(t_complex z1, t_complex z2);
t_complex   square_complex(t_complex z);

// hooks
int     key_handler(int keysym, t_fractal *fractal);
int     close_handler(t_fractal *fractal);
int     mouse_handler(int button, int x, int y, t_fractal *fractal);

// utils
int     ft_strncmp(const char *s1, const char *s2, size_t n);
void    ft_putstr_fd(char *s, int fd);
double  ft_atodbl(char *s);

#endif