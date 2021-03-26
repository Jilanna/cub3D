#include "cube.h"
#include "libft.h"

int test_map_basic(t_params *params, char **mappy, int hi, int wi)
{
    int i;
    int j;

    i = 0;
    params->perso = '0';
    while (i < hi)
    {
        j = 0;
        while (j < wi)
        {
            if (mappy[i][j] == ' ' || mappy[i][j] == '0'
            || mappy[i][j] == '1' || mappy[i][j] == '2')
                j++;
            else if ((mappy[i][j] == 'N' || mappy[i][j] == 'E'
            || mappy[i][j] == 'S' || mappy[i][j] == 'W') && params->perso == '0')
            {
                params->perso == mappy[i][j];
                j++;
            }
            else
                return (-1);
        }
        i++;
    }
    return(0);
}