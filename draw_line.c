#include "../includes/cube.h"
#include "../includes/libft.h"

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
		p->img.data[TO_COORD(xa, ya)] = 0xb3b3b3;
		xa += dx;
		ya += dy;
	}
}