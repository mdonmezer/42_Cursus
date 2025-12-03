#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_complex
{
    double  x;
    double  y;
}   t_complex;

typedef struct s_img
{
    void    *img_ptr;
    char    *pixels_ptr;
    int     bpp;
    int     endian;
    int     line_len;
}   t_img;

typedef struct s_fractal
{
    char    *name;
    void    *mlx_connection;
    void    *mlx_window;
    t_img   img;
    double  escape_value;
    int     iterations_def;
    double  shift_x;
    double  shift_y;
    double  zoom;
    double  julia_x;
    double  julia_y;
}   t_fractal;

#endif