#include "fractol.h"

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (button == 4)
	{
		fractal->zoom *= 0.95;
	}
	else if (button == 5)
	{
		fractal->zoom *= 1.05;
	}
	fractal_render(fractal);
	return (0);
}
