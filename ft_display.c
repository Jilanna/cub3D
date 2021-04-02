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
    p->img.img_ptr = mlx_new_image(p->mlx, p->sizex, p->sizey);
    if (p->img.img_ptr == NULL)
        return (-1);
	p->img.data = (int *)mlx_get_data_addr(p->img.img_ptr, &p->img.bpp,
    &p->img.lenght, &p->img.endian);
    if (p->img.data == NULL)
        return (-1);
    return (0);
}

int ft_display_player(t_params *p)
{
    mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->img.img_ptr, 0, 0);
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