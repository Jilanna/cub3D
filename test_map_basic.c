#include "../includes/cube.h"
#include "../includes/libft.h"

int test_map_basic(t_params *params, char **mappy, int hi, int wi)
{
    int i;
    int j;

    i = 0;
    params->dirx = -2;
    while (i < hi)
    {
        j = 0;
        while (j < wi)
        {
            if (mappy[i][j] == ' ' || mappy[i][j] == '0'
            || mappy[i][j] == '1' || mappy[i][j] == '2')
                j++;
            else if ((mappy[i][j] == 'N' || mappy[i][j] == 'E'
            || mappy[i][j] == 'S' || mappy[i][j] == 'W') && params->dirx == -2)
            {
                get_position(params, mappy[i][j], j, i);
                j++;
            }
            else
                return (-1);
        }
        i++;
    }
    return(0);
}

void    get_position(t_params *params, char position, int x, int y)
{
    params->posx = (double)x;
    params->posy = (double)y;
    if (position == 'N')
    {
        params->dirx = 0;
        params->diry = 1;
    }
    else if (position == 'E')
    {
        params->dirx = 1;
        params->diry = 0;
    }
    else if (position == 'S')
    {
        params->dirx = 0;
        params->diry = -1;
    }
    else
    {
        params->dirx = -1;
        params->diry = 0;
    }
    get_plane(params);
}

void    get_plane(t_params *params)
{
    if (params->dirx == 0)
    {
        params->planex = 0.6;
        params->planey = 0;
    }
    else
    {
        params->planex = 0;
        params->planey = 0.6;
    }
}