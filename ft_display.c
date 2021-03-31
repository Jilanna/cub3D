#include "cube.h"
#include "libft.h"

int ft_open_mlx(t_params *p)
{
    p->mlx_ptr = mlx_init();
    if (p->mlx_ptr == NULL)
        return (-1);
    p->win_ptr = mlx_new_window(p->mlx_ptr, p->sizex, p->sizey, "JI");
    if (p->win_ptr == NULL)
        return (-1);
    return (0);
}

int ft_display_player(t_params *params)
{
    mlx_pixel_put (p->mlx_ptr, p->win_ptr, int x, int y, int color );
}

int ft_display(t_params *params)
{
    int out;

    out = ft_open_mlx(params);
    if (out == -1)
        return (-1);
    ft_display_player(params);
    return(out);
}