#include "cube.h"
#include "libft.h"

int ft_open_mlx(t_params *params)
{
    int out;
    void    *mlx_ptr;
    void    *win_ptr;

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, params->sizex, params->sizey);
    mlx_loop(mlx_ptr);
    return (out);
}

int ft_display(t_params *params)
{
    int out;

    out = ft_open_mlx(params);
    return(out);
}