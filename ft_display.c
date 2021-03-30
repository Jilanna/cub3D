#include "cube.h"
#include "libft.h"

int ft_open_mlx(t_params *p)
{
    p->mlx_ptr = mlx_init();
    if (p->mlx_ptr == NULL)
        return (-1);
    p->win_ptr = mlx_new_window(mlx_ptr, p->sizex, p->sizey, "Jeu incroyable");
    if (p->win_ptr == NULL)
        return (-1);
    return (0);
}

int ft_display(t_params *params)
{
    int out;

    out = ft_open_mlx(params);
    if (out == -1)
        return (-1);
    return(out);
}