#include "../includes/cube.h"
#include "../includes/libft.h"

int	rounding(t_params *p, double x, double y)
{
	int		out;
	double	tempx;
	double	tempy;
	double	temp;

	temp = modf(x, &tempx);
	if (temp > 0.5)
		tempx += 1;
	temp = modf(y, &tempy);
	if (temp > 0.5)
		tempy += 1;
	out = (int)(tempx) + (int)(tempy) * p->img.lenght;
	return (out);
}

void	draw_line(t_params *p, double xa, double ya, double xb, double yb)
{
	double	dx;
	double	dy;
	double	step;

	dx = xb - xa;
	dy = yb - ya;
    if (fabs(dx) > fabs(dy))
        step = fabs(dx);
    else
        step = fabs(dy);
	dx /= step;
	dy /= step;
	while (fabs(xb - xa) > 0.01 || fabs(yb - ya) > 0.01)
	{
		p->img.data[rounding(p, xa, ya)] = 0x7f7f7f;
		xa += dx;
		ya += dy;
	}
}